#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#define PI 3.1415926
#define T 4.3333f


using namespace sf;



int main()
{
    RenderWindow window;
    window.create(VideoMode(1024, 768), "IT\'s works");
    window.setSize(Vector2u(1024.f, 768.f));
    
    RectangleShape player1;
    player1.setSize(Vector2f(75.f, 50.f));
    player1.setOrigin(Vector2f(37.5f, 25.f));
    player1.setPosition(Vector2f(50, 50));
    player1.setFillColor(Color::Green);

    RectangleShape player2;
    player2.setSize(Vector2f(75.f, 50.f));
    player2.setOrigin(Vector2f(37.5f, 25.f));
    player2.setPosition(Vector2f(50, 50));
    player2.setFillColor(Color::Red);

    CircleShape ball(15.f);
    ball.setOrigin(Vector2f(25.f, 25.f));
    ball.setPosition(Vector2f(512.f, 384.f));

    sf::ConvexShape polygon;
polygon.setPointCount(3);
polygon.setPoint(0, sf::Vector2f(0, 0));
polygon.setPoint(1, sf::Vector2f(0, 10));
polygon.setPoint(2, sf::Vector2f(25, 5));
polygon.setOutlineColor(sf::Color::Red);
polygon.setOutlineThickness(5);
polygon.setPosition(10, 20);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        
        player1.rotate( 0.05 * T * (Keyboard::isKeyPressed(Keyboard::D) - Keyboard::isKeyPressed(Keyboard::A)) );
        
        Vector2f behind (cos(player1.getRotation()*PI/180.f) * 0.05f,  sin(player1.getRotation()*PI/180.f) * 0.05f);
        
        player1.move(T * behind * (float)(Keyboard::isKeyPressed(Keyboard::S) - Keyboard::isKeyPressed(Keyboard::W)));
		

		player2.rotate( 0.05 * T * (Keyboard::isKeyPressed(Keyboard::L) - Keyboard::isKeyPressed(Keyboard::J)) );

        Vector2f behind2 (cos(player2.getRotation()*PI/180.f) * 0.05f,  sin(player2.getRotation()*PI/180.f) * 0.05f);

        player2.move(T * behind2 * (float)(Keyboard::isKeyPressed(Keyboard::K) - Keyboard::isKeyPressed(Keyboard::I)));
		

        window.clear();

        window.draw(player1);
        window.draw(player2);
        window.draw(ball);
        window.draw(polygon);

        window.display();
    }

    return 0;
}
