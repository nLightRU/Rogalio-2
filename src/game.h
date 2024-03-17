#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "renderer.h"
#include "level.h"

class Game
{
private:
	const char* m_title;
	size_t m_width, m_height;
	

	
	Renderer *m_renderer;
	Level* m_currentLevel;
	

private:
	void render();
	void handle_events();

public:
	Game();
	Game(const std::string& title, size_t width, size_t height);
	~Game();

	void run();
};

