#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
// start 735, 207
// size 20 x 20


int main()
{
    std::srand(std::time(nullptr));

    sf::RenderWindow window(sf::VideoMode(800, 600), 
                           "Rogalio 2", 
                           sf::Style::Resize | sf::Style::Titlebar | sf::Style::Close);

    
    sf::Image* asset_map = new sf::Image();
    if (!asset_map->loadFromFile(R"(res\RF_Catacombs_V1.0\mainlevbuild.png)"))
    {
        exit(3);
    }
    
    std::vector<sf::Texture> floor_textures;
    floor_textures.reserve(6);

    for (size_t i = 0; i < 3; ++i)
    {
        for(size_t j = 0; j < 2; ++j)
        {
            sf::Texture t;
            t.loadFromImage(*asset_map, sf::IntRect(735 + j*16, 207 + i*16, 16, 16));
            floor_textures.emplace_back(std::move(t));
        }
    }


    sf::Vector2f start_pos = sf::Vector2f(80.f, 80.f);
    std::vector<sf::Sprite> sprites;
    for (size_t i = 0; i < 15; ++i)
    {
        for (size_t j = 0; j < 15; ++j)
        {
            int idx = std::rand() % 6;
            sf::Sprite s(floor_textures[idx]);
            sf::Vector2f pos = start_pos + sf::Vector2f(16.f * i, 16.f * j);
            s.setPosition(pos);
            sprites.push_back(std::move(s));
        }
    }
            
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        for (const auto& s : sprites) 
        {
            window.draw(s);
        }
        
        
        window.display();
    }

    delete asset_map;
 
    return 0;
}