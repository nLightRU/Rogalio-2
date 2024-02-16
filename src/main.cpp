#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

// start 384, 400
// end 447, 447


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), 
                           "Rogalio 2", 
                           sf::Style::Resize | sf::Style::Titlebar | sf::Style::Close);

    
    
    sf::Texture floor_texture;
    if ( !floor_texture.loadFromFile("level.png", sf::IntRect(736, 208, 40, 40)) )
    {
        std::cerr << "ERROR in loading texture from file" << std::endl;
        exit(4);
    }

    sf::Vector2f initial_position{40.f, 40.f};
    sf::Sprite sprite(floor_texture);
    sprite.setPosition(initial_position);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        window.draw(sprite);
        
        window.display();
    }

 
    return 0;
}