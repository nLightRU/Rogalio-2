#include "config.h"
#include "game.h"

Game::Game() : m_title("Rogalio 2"), m_width(WIDTH), m_height(HEIGHT)
{
    m_renderer = new Renderer(m_width, m_height, m_title);
    m_currentLevel = new Level();
}

Game::Game(const std::string& title, size_t width, size_t height) :
    m_title(title.c_str()),
    m_width(width),
    m_height(height)
{
    m_renderer = new Renderer(m_width, m_height, m_title);
    m_currentLevel = new Level();
}

Game::~Game()
{
    // we delete this later after we start
    // storing all levels or using level manager
    delete m_currentLevel;

    delete m_renderer;
}

void Game::run()
{
    // handle events and input
    // render
    m_renderer->render();
}