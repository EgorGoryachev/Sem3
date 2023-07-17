#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

bool Collide(Sprite s1, Sprite s2) {
	return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
}

int main() {

	srand(time(0));
    RenderWindow window(VideoMode(600, 500), "Arkanoid");

	Texture T1, T2, T3, T4;
	T1.loadFromFile("tdaf7QNn7XQ.PNG");
	T2.loadFromFile("fon.PNG");
	T3.loadFromFile("m.PNG");
	T4.loadFromFile("dv.PNG");

	Sprite Background(T2), Ball(T3), Paddle(T4);
	Paddle.setPosition(300, 480);
	Ball.setPosition(300, 300);

	Sprite block[1000];

	int n = 0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 10; j++) {
			block[n].setTexture(T1);
			block[n].setPosition(i * 59, j * 27);
			n++;
		}
	}
	float x = 6, y = 7;

	while (window.isOpen()) {
		Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == Event::Closed) {
				window.close();
			}
			Ball.move(x, 0);
			for (int i = 0; i < n; i++) {
				if (Collide(Ball, block[i])) {
					block[i].setPosition(-100, 0);
					x = -x;
				}
			}
			Ball.move(0, y);
			for (int i = 0; i < n; i++) {
				if (Collide(Ball, block[i])) {
					block[i].setPosition(-100, 0);
					y = -y;
				}
			}
			Vector2f b = Ball.getPosition();
			if (b.x < 0 || b.x > 580) {
				x = -x;
			}
			if (b.y < 0 || b.y > 500) {
				y = -y;
				if (b.y > 480) {
					window.close();
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				Paddle.move(8, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				Paddle.move(-8, 0);
			}
			if (Collide(Paddle, Ball)) {
				y = -(rand() % 5 + 2);
			}
			window.clear();
			window.draw(Background);
			window.draw(Ball);
			window.draw(Paddle);
			for (int i = 0; i < n; i++) {
				window.draw(block[i]);
			}
			window.display();
			window.setFramerateLimit(60);
		}
	}

	return 0;
}