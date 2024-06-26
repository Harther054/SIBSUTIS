﻿#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf; using namespace std;

const int WIDTH = 900;
const int HEIGHT = 600;

class Figure
{
protected:
	float X, Xd;
	float Y, Yd;
	int Red;
	int Green;
	int Blue;

protected:
	float Angle;
	CircleShape Shape;


public:
	Figure()
	{
		Angle = 0;
		Red = rand() % 256;
		Green = rand() % 256;
		Blue = rand() % 256;
		X = rand() % 850;
		Y = rand() % 560;
		Xd = 1 + rand() % 10;
		Yd = 0;
	}

	void Draw(RenderWindow& window)
	{
		window.draw(Shape);
	}

	void RotateMove(RenderWindow& window)
	{
		Shape.setRotation(Angle += 0.2);
	}

	void HorisontalMove(RenderWindow& window)
	{
		X += Xd;
		Shape.move(Xd, Yd);

		if (X > WIDTH || X < 0)
		{
			Xd = (-1) * Xd;
		}
	}

	//virtual void Draw(RenderWindow& window, char R)
	//{
		//window.draw(rectangle);
	//}
};

class Point : public Figure
{
protected:

	int R;

public:

	Point()
	{
		R = 5;
		Angle = 0;
		Shape.setRadius(R);
		Shape.setFillColor(Color(Red, Green, Blue));
		Shape.setPosition(X, Y);
		Shape.setOrigin(Shape.getRadius(), Shape.getRadius());
	}
};

class Triangle : public Point
{
protected:

	int NumberVertices;

public:

	Triangle()
	{
		R = 60;
		NumberVertices = 3;
		Shape.setPointCount(NumberVertices);
		Shape.setRadius(R);
		Shape.setOrigin(Shape.getRadius(), Shape.getRadius());
	}
};

class Rhomb : public Triangle
{
public:

	Rhomb()
	{
		R = 50;
		NumberVertices = 4;
		Shape.setPointCount(NumberVertices);
		Shape.setRadius(R);
		Shape.setOrigin(Shape.getRadius(), Shape.getRadius());
	}
};

class Circle : public Point
{

public:

	Circle()
	{
		float R = 50;
		float ringSize = 5;
		Shape.setRadius(R);
		Shape.setFillColor(Color(0, 100, 180, 100));
		Shape.setOutlineThickness(ringSize);
		Shape.setOutlineColor(Color(Red, Green, Blue));
		Shape.setOrigin(Shape.getRadius(), Shape.getRadius());
	}
};

class Rectangle : public Figure
{
protected:
	RectangleShape rectangle;
public:
	Rectangle()
	{
		float Width = 250;
		float Height = 100;
		rectangle.setSize(Vector2f(Width, Height));
		rectangle.setFillColor(Color(Red, Green, Blue));
		rectangle.setPosition(X, Y);
		rectangle.setOrigin(Width / 2, Height / 2);
	}

	void RotateMove(RenderWindow& window)
	{
		rectangle.setRotation(Angle += 0.2);
	}

	virtual void HorisontalMove(RenderWindow& window)
	{
		X += Xd;

		rectangle.move(Xd, Yd);

		if (X > WIDTH || X < 0)
		{
			Xd = (-1) * Xd;
		}
	}
	virtual void Draw(RenderWindow& window)
	{
		window.draw(rectangle);
	}


};

class Line : public Rectangle
{
public:

	Line(float Width = 1, float Height = 200)
	{
		rectangle.setOrigin(Width / 2, Height / 2);
		rectangle.setSize(Vector2f(Width, Height));
		rectangle.setRotation(20);
	}
};

class Ellipse : public Circle
{
public:

	Ellipse()
	{
		Shape.setScale(Vector2f(3, 1));
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	auto clock = new Clock[2];
	auto point = new Point[2];
	auto rectangle = new Rectangle[2];
	auto ellipse = new Ellipse[2];
	auto line = new Line[2];
	auto circle = new Circle[2];
	auto rhomb = new Rhomb[2];
	auto triangle = new Triangle[2];

	int choice;


	char R = 'rect';
	cout << "Выберите вариат движения:\n";
	cout << "1 - Горизонтальное движение\n2 - Движение вокруг центра\n";
	cin >> choice;

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "LAB 5");
	window.setFramerateLimit(120);

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		window.clear(Color(0, 100, 180, 100));

		for (int i = 0; i < 2; i++)
		{
			if (choice == 1) {
				point[i].Draw(window);
				point[i].HorisontalMove(window);

				rectangle[i].Draw(window);
				rectangle[i].HorisontalMove(window);

				ellipse[i].Draw(window);
				ellipse[i].HorisontalMove(window);

				line[i].Draw(window);
				line[i].HorisontalMove(window);

				circle[i].Draw(window);
				circle[i].HorisontalMove(window);

				rhomb[i].Draw(window);
				rhomb[i].HorisontalMove(window);

				triangle[i].Draw(window);
				triangle[i].HorisontalMove(window);
			}
			else if (choice == 2)
			{
				point[i].Draw(window);
				point[i].RotateMove(window);

				rectangle[i].Draw(window);
				rectangle[i].RotateMove(window);

				ellipse[i].Draw(window);
				ellipse[i].RotateMove(window);

				line[i].Draw(window);
				line[i].RotateMove(window);

				circle[i].Draw(window);
				circle[i].RotateMove(window);

				rhomb[i].Draw(window);
				rhomb[i].RotateMove(window);

				triangle[i].Draw(window);
				triangle[i].RotateMove(window);
			}


		}

		window.display();
	}

	return 0;
}