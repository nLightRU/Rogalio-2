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

    m_floorTexture = new sf::Texture();
    m_wallTexture = new sf::Texture();

    bool floor_loaded = m_floorTexture->loadFromFile(texturesFile, sf::IntRect(736, 368, 30, 30));
    bool wall_loaded = m_wallTexture->loadFromFile(texturesFile, sf::IntRect(736, 272, 30, 30));
            
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
    sf::Vector2f start(30.f, 30.f);

    // Room walls
    for (size_t i = 0; i < w; ++i) {
        sf::Sprite s_t(*m_wallTexture);
        s_t.setPosition(start + sf::Vector2f(sprite_a * i, sprite_a));
        sprites.push_back(std::move(s_t));

        //sf::Sprite s_b(*m_wallTexture);
        //s_b.setPosition(sf::Vector2f(20.f * i, 20.f * h));
        //sprites.push_back(std::move(s_b));
    }

    // Room inner space
    for (size_t i = 1; i < h - 2; ++i) 
    {
        for (size_t j = 1; j < w - 1; ++j)
        {
            sf::Sprite s(*m_floorTexture);
            s.setPosition(start + sf::Vector2f(sprite_a * j, sprite_a * i));
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

        m_Window->display();
    }
}
