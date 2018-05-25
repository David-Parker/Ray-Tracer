#pragma once

/* Defines a window region. */
class Window
{
public:
	int width;
	int height;

	Window(int width, int height) : width(width), height(height) {}
	~Window();
};

