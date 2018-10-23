#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#define PI 3.1415926
#define T 4.3333f


using namespace sf;

float nol(float a){
	if(a > 0)
		return 1;
	else if(a == 0)
		return 0;
	else
		return -1;
}


float isConstain(Vector2f p1, Vector2f p2, Vector2f point){
	return (p1.y-p2.y)*point.x + (p2.x-p1.x)*point.y + (p1.x*p2.y - p2.x*p1.y);
}

bool inShape(ConvexShape shape, Vector2f point){
	int n = shape.getPointCount();
	for(int i = 0; i < n; i++){
		if(
			nol(
				isConstain(
					shape.getPoint(i) + shape.getPosition(),
					shape.getPoint((i + 1) % n) + shape.getPosition(),
					point
				)
			)
			!=
			nol(
				isConstain(
					shape.getPoint(i) + shape.getPosition(),
					shape.getPoint((i + 1) % n) + shape.getPosition(),
					shape.getPoint((i + 2) % n) + shape.getPosition()
				)
			)
		){
			return false;
		}
	}
	return true;
}

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
    ball.setFillColor(Color::Green);
    ball.setOrigin(Vector2f(15.f, 15.f));
    ball.setPosition(Vector2f(512.f, 384.f));

    sf::ConvexShape polygon;
	polygon.setPointCount(3);
	polygon.setPoint(0, sf::Vector2f(0, 0));
	polygon.setPoint(1, sf::Vector2f(0, 100));
	polygon.setPoint(2, sf::Vector2f(350, 100));
	polygon.setOutlineColor(sf::Color::Red);
	polygon.setOutlineThickness(5);
	polygon.setPosition(400, 200);

	Vector2f ballm(0.f, 50.f);
	ball.setPosition(450.f, 50.f);
	bool k = false;
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
		if(inShape(polygon, ball.getPosition()) && !k){
			ballm = Vector2f(0, 0);
		}
		
		ball.move(ballm * 0.005f);

        window.clear();

        window.draw(player1);
        window.draw(player2);
        window.draw(polygon);
        window.draw(ball);

        window.display();
    }

    return 0;
}
