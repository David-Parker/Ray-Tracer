#pragma once

/* Defines a window region. */
class Window
{
private:
	int width;
	int height;
public:
	Window(int width, int height) : width(width), height(height) {}
	~Window();

	int Width() { return this->width; }
	int Height() { return this->height; }
};

