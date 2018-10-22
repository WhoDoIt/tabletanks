#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#define PI 3.1415926

using namespace sf;

int main()
{
    RenderWindow window;
    window.create(VideoMode(1024, 768), "IT\'s works");
    window.setSize(1024.f, 768.f);
    
    RectangleShape shape;
    shape.setSize(Vector2f(75.f, 50.f));
    shape.setOrigin(Vector2f(37.5f, 25.f));
    shape.setPosition(Vector2f(50, 50));
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        shape.rotate( 0.05 * (Keyboard::isKeyPressed(Keyboard::D) - Keyboard::isKeyPressed(Keyboard::A)) );

        Vector2f behind (cos(shape.getRotation()*PI/180.f) * 0.05f,  sin(shape.getRotation()*PI/180.f) *0.05f);


        shape.move(behind * (float)(Keyboard::isKeyPressed(Keyboard::S) - Keyboard::isKeyPressed(Keyboard::W)));

        window.clear();

        window.draw(shape);

        window.display();
    }

    return 0;
}