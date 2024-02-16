#include <ctime>
#include <cstdlib>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>


sf::Color getRandomColor() {
    uint8_t r = std::rand() % 255 + 1;
    uint8_t g = std::rand() % 255 + 1;
    uint8_t b = std::rand() % 255 + 1;

    return sf::Color(r, g, b);
}

int main()
{
    std::srand(std::time(nullptr));
    

    sf::RenderWindow window(sf::VideoMode(800, 600), "Rogalio 2", sf::Style::Resize | 
                                                                  sf::Style::Titlebar | 
                                                                  sf::Style::Close);

    sf::RectangleShape shape(sf::Vector2f(80.f, 80.f));
    shape.setPosition(sf::Vector2f(40.f, 40.f));

    size_t shapes_num = 5;
    sf::Vector2f quad_size = sf::Vector2f(40.f, 40.f);
    sf::Vector2f initial_position = sf::Vector2f(0.f, 0.f);

    sf::RectangleShape** quads = new sf::RectangleShape*[shapes_num];
    for (size_t i = 0; i < shapes_num; ++i) {
        quads[i] = new sf::RectangleShape(quad_size);
        quads[i]->setPosition(initial_position + sf::Vector2f(45.f * i, 0.f));
    }

    std::vector<sf::RectangleShape> *v_quads = new std::vector<sf::RectangleShape>;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (size_t i = 0; i < shapes_num; ++i) 
        {
            quads[i]->setFillColor(getRandomColor());
            window.draw(*quads[i]);
        }
        window.display();
    }

    for (size_t i = 0; i < shapes_num; ++i) 
    {
        delete quads[i];
    }

    delete[] quads;

    return 0;
}