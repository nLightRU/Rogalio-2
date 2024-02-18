#include "config.h"
#include "game.h"

Game::Game() : 
    m_title("Rogalio 2"),
    m_width(WIDTH),
    m_height(HEIGHT),
    m_window(sf::VideoMode(m_width, m_height), m_title, DEFAULT_FLAGS)
{

}

Game::Game(const std::string& title, size_t width, size_t height) :
    m_title(title.c_str()),
    m_width(width),
    m_height(height),
    m_window(sf::VideoMode(m_width, m_height), m_title, DEFAULT_FLAGS)
{

}

Game::~Game()
{

}

void Game::run()
{
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        m_window.clear(sf::Color::White);

        m_window.display();
    }
}
