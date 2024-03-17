#include "renderer.h"

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "config.h"
#include "level.h"

// lt 736  368
// lb 736  399
// rt 767  368
// rb 767  399
// 30x30 

Renderer::Renderer() 
{
	m_Window = new sf::RenderWindow(sf::VideoMode(800, 600), "Rogalio 2", DEFAULT_FLAGS);
}

Renderer::Renderer(size_t width, size_t heigth, const std::string& title)
{
	m_Window = new sf::RenderWindow(sf::VideoMode(width, heigth), 
								title, DEFAULT_FLAGS);

    

    bool textures_loaded = loadTextures();

    if (!textures_loaded)
    {
        exit(2);
    }
}

bool Renderer::loadTextures() 
{
    std::string texturesFile = RES_FOLDER;
    texturesFile += R"(RF_Catacombs_v1.0\mainlevbuild.png)";

    std::string playerTexture = RES_FOLDER;
    playerTexture += R"(RPG_Hero\idle\idle_down_40x40.png)";

    m_floorTexture = new sf::Texture();
    m_wallTexture = new sf::Texture();
    m_playerTexture = new sf::Texture();

    bool floor_loaded = m_floorTexture->loadFromFile(texturesFile, sf::IntRect(736, 368, 30, 30));
    bool wall_loaded = m_wallTexture->loadFromFile(texturesFile, sf::IntRect(384, 400, 30, 30));
    bool player_loaded = m_playerTexture->loadFromFile(playerTexture, sf::IntRect(0, 0, 24, 24));

    return floor_loaded && wall_loaded;
}

Renderer::~Renderer() 
{
    delete m_floorTexture;
    delete m_wallTexture;
    delete m_Window;
}

void Renderer::render()
{
    std::vector<sf::Sprite> sprites;

    size_t w = 12, h = 10;
    float sprite_a = 30.f;
    sf::Vector2f start(0.f, 0.f);

    sf::Sprite player(*m_playerTexture);
    player.setPosition(start + sf::Vector2f(50.f, 50.f));

    // Room walls top and bottom
    for (size_t i = 0; i < w; ++i) 
    {
        sf::Sprite s_t(*m_wallTexture);
        sf::Vector2f pos_t(sprite_a * i, 0.f);
        s_t.setPosition(pos_t + start);
        sprites.push_back(std::move(s_t));

        sf::Sprite s_b(*m_wallTexture);
        sf::Vector2f pos_b(sprite_a * i, sprite_a * (h - 1));
        s_b.setPosition(pos_b + start);
        sprites.push_back(std::move(s_b));
    }

    // Room walls right and left
    for (size_t i = 0; i < h - 1; ++i)
    {
        sf::Sprite s_l(*m_wallTexture);
        sf::Vector2f pos_l(0, sprite_a * i);
        s_l.setPosition(pos_l + start);
        sprites.push_back(std::move(s_l));

        sf::Sprite s_r(*m_wallTexture);
        sf::Vector2f pos_r(sprite_a * (w - 1), sprite_a * i);
        s_r.setPosition(pos_r + start);
        sprites.push_back(std::move(s_r));
    }

    // Room inner space
    for (size_t i = 1; i < h - 1; ++i) 
    {
        for (size_t j = 1; j < w - 1; ++j)
        {
            sf::Sprite s(*m_floorTexture);
            sf::Vector2f pos(sprite_a * j, sprite_a * i);
            s.setPosition(pos + start);
            sprites.push_back(std::move(s));
        }
    }
    

    while (m_Window->isOpen())
    {
        sf::Event event;
        while (m_Window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_Window->close();
        }

        m_Window->clear(sf::Color::Black);

        for (const auto& sprite : sprites)
        {
            m_Window->draw(sprite);
        }

        m_Window->draw(player);

        m_Window->display();
    }
}
