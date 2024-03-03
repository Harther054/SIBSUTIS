#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <time.h>
#include "windows.h"

using namespace std;
using namespace sf;

const int n = 21;


RenderWindow window(VideoMode(1000, 800), "Lab 6");

class figure
{
private:
	int dx, dy, y, x, point_count, size;

	CircleShape circle;
	RectangleShape rectangle;

public:

	figure(int shape_point_count, int shape_size)
	{
		if (shape_size == 15) 
		{
			circle.setFillColor(Color::Black);
			circle.setOutlineThickness(3.f);
			circle.setOutlineColor(Color(rand() % 250, rand() % 250, rand() % 250));
		}
		else if (shape_size == 2 || shape_size == 13)
		{
			rectangle.setFillColor(Color(rand() % 250, rand() % 250, rand() % 250));
			rectangle.setPosition(rand() % 1000, rand() % 800);
			rectangle.setSize(Vector2f(shape_point_count, shape_size));
		}
		else
		{
			circle.setFillColor(Color(rand() % 250, rand() % 250, rand() % 250));
		}
		if (shape_size != 2 || shape_size != 13)
		{
			circle.setRadius(shape_size);
			circle.setPointCount(shape_point_count);
			circle.setPosition(rand() % 1000, rand() % 800);
		}

		if (shape_size == 12) 
		{
			circle.setScale(2, 1);
		}


		dx = 5; dy = 5;
	}

	void paint(int type, CircleShape circle)
	{
		window.draw(circle);
	}
	void paint(int type, RectangleShape rectangle)
	{
		window.draw(rectangle);
	}

	void Move(int type, int rotate = 1)
	{

		x = rectangle.getPosition().x;
		x = circle.getPosition().x;

		if (x > 999 || x < 0) dx *= -1;


		circle.move(dx, 0);
		rectangle.move(dx, 0);

		if (rotate == -1)
		{

			rectangle.rotate(10.f);
			circle.rotate(10.f);
		}
	}

	void Move2(int type, int rotate = 1)
	{
		window.draw(rectangle);
		window.draw(circle);

		x = rectangle.getPosition().x;
		y = rectangle.getPosition().y;

		x = circle.getPosition().x;
		y = circle.getPosition().y;

		if (x > 999 || x < 0) dx *= -1;
		if (y > 799 || y < 0) dy *= -1;

		rectangle.move(dx, dy);
		circle.move(dx, dy);

		if (rotate == -1)
		{

			rectangle.rotate(10.f);
			circle.rotate(10.f);
		}
	}

	CircleShape get()
	{
		return circle;
	}
	RectangleShape get2()
	{
		return rectangle;
	}
};

class tPoint : public figure
{
public:
	tPoint() :
		figure(30, 5)
	{}
};

class triangle : public figure
{
public:
	triangle() :
		figure(3, 10)
	{}
};

class rhombus : public figure
{
public:
	rhombus() :
		figure(4, 10)
	{}
};

class ring : public figure
{
public:
	ring() :
		figure(30, 15)
	{}
};

class ellipse : public figure
{
public:
	ellipse() :
		figure(30, 12)
	{}
};

class line : public figure
{
public:
	line() :
		figure(30, 2)
	{}
};

class rectangle_shape : public figure
{
public:
	rectangle_shape() :
		figure(30, 13)
	{}
};


int main()
{
	int i, rotate = -1;

	srand(time(0));

	figure* mass[n];

	for (i = 0; i < n; i += 7)
	{
		mass[i] = new tPoint;
		mass[i + 1] = new triangle;
		mass[i + 2] = new rhombus;
		mass[i + 3] = new ring;
		mass[i + 4] = new ellipse;
		mass[i + 5] = new line;
		mass[i + 6] = new rectangle_shape;
	}
	CircleShape circle;
	RectangleShape rectangle;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)

				window.close();
		}
		window.clear(Color::Black);


		for (i = 0; i < n; i++)
		{
			circle = mass[i]->get();
			rectangle = mass[i]->get2();

			mass[i]->paint(i, circle);
			mass[i]->paint(i, rectangle);
			if (event.mouseButton.button == Mouse::Left)
			{
				mass[i]->Move(i, rotate);
			}

			else {
				mass[i]->Move2(i, rotate);
			}

		}
		Sleep(1);
		window.display();
	}
	return 0;
}