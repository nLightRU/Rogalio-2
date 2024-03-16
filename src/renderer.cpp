#include "renderer.h"

#include <SFML/Graphics.hpp>

#include "config.h"
#include "level.h"

Renderer::Renderer() 
{
	m_Window = new sf::RenderWindow(sf::VideoMode(800, 600), "Rogalio 2", DEFAULT_FLAGS);
}

Renderer::Renderer(size_t width, size_t heigth, const std::string& title)
{
	m_Window = new sf::RenderWindow(sf::VideoMode(width, heigth), 
								title, DEFAULT_FLAGS);
}

bool Renderer::loadTextures() 
{

}

Renderer::~Renderer() 
{
	delete m_Window;
}

void Renderer::render()
{
    while (m_Window->isOpen())
    {
        sf::Event event;
        while (m_Window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_Window->close();
        }

        m_Window->clear(sf::Color::Black);

        m_Window->display();
    }
}
