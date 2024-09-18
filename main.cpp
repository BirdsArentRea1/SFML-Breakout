#include <SFML/Graphics.hpp>


	class Brick {
	private:
		float width;
		float height;
		float xpos;
		float ypos;
		bool Dead;
		sf::RectangleShape shape;

	public:
		Brick(float x, float y, float w, float h) {
			xpos = x;
			ypos = y;
			width = w;
			height = h;
			Dead = false;

			shape.setSize(sf::Vector2f(width, height));
			shape.setPosition(xpos, ypos);
			shape.setFillColor(sf::Color::Red);
		}
		void draw(sf::RenderWindow& window) {
			if (!Dead) {
				window.draw(shape);
			}
		}

		void killBrick() {
			Dead = true;
			shape.setFillColor(sf::Color::Transparent);
		}

		bool checkCollision(float ballX, float ballY, float ballRadius) {
			if (!Dead &&
				ballX + ballRadius > xpos && ballX - ballRadius < xpos + width &&
				ballY + ballRadius > ypos && ballY - ballRadius < ypos + height) {
				killBrick();
				return true;
			}
			return false;
			}
	}; 

	class Ball {
	private:
		float xpos;
		float ypos;
		float xvel;
		float yvel;
		float radius;
		sf::CircleShape shape;

	public:
		Ball(float x, float y, float w, float h) {
			xpos = x;
			ypos = y;
			xvel = 5;
			yvel = 5;
			radius = 20;

			shape.setRadius(radius);
			shape.setPosition(xpos, ypos);
			shape.setFillColor(sf::Color::White);
		}
		void move(float windowWidth, float windowHeight) {
			xpos += xvel;

			if (xpos <= 0 || xpos + radius * 2 >= windowWidth) {
				xvel = -xvel;
			}
		}
		bool brickCollision(Brick& brick) {
			return brick.checkCollision(xpos + radius, ypos + radius, radius);

		}
		void draw(sf::RenderWindow& window) {

			window.draw(shape);

		}
	};

	int main() {
		sf::RenderWindow window(sf::VideoMode(800, 600), "BREACKOUT");

		Brick brick1(100, 100, 50, 20);
		Brick brick2(160, 100, 50, 20);
		Brick brick3(220, 100, 50, 20);
		Brick brick4(280, 100, 50, 20);
		Brick brick5(340, 100, 50, 20);
		Brick brick6(400, 100, 50, 20);
		Brick brick7(460, 100, 50, 20);
		Brick brick8(520, 100, 50, 20);
		Brick brick9(580, 100, 50, 20);
		Brick brick10(640, 100, 50, 20);
		Brick brick11(100, 128, 50, 20);
		Brick brick12(160, 128, 50, 20);
		Brick brick13(220, 128, 50, 20);
		Brick brick14(280, 128, 50, 20);
		Brick brick15(340, 128, 50, 20);
		Brick brick16(400, 128, 50, 20);
		Brick brick17(460, 128, 50, 20);
		Brick brick18(520, 128, 50, 20);
		Brick brick19(580, 128, 50, 20);
		Brick brick20(640, 128, 50, 20);
		Brick brick21(100, 156, 50, 20);
		Brick brick22(160, 156, 50, 20);
		Brick brick23(220, 156, 50, 20);
		Brick brick24(280, 156, 50, 20);
		Brick brick25(340, 156, 50, 20);
		Brick brick26(400, 156, 50, 20);
		Brick brick27(460, 156, 50, 20);
		Brick brick28(520, 156, 50, 20);
		Brick brick29(580, 156, 50, 20);
		Brick brick30(640, 156, 50, 20);

		Ball ball(200, 200, 10, 10); //instantiation

		


		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();
			}
			//physics
			ball.brickCollision(brick1);
			ball.brickCollision(brick2);
			ball.brickCollision(brick3);


			//render
			ball.draw(window);

			brick1.draw(window);
			brick2.draw(window);
			brick3.draw(window);
			brick4.draw(window);
			brick5.draw(window);
			brick6.draw(window);
			brick7.draw(window);
			brick8.draw(window);
			brick9.draw(window);
			brick10.draw(window);
			brick11.draw(window);
			brick12.draw(window);
			brick13.draw(window);
			brick14.draw(window);
			brick15.draw(window);
			brick16.draw(window);
			brick17.draw(window);
			brick18.draw(window);
			brick19.draw(window);
			brick20.draw(window);
			brick21.draw(window);
			brick22.draw(window);
			brick23.draw(window);
			brick24.draw(window);
			brick25.draw(window);
			brick26.draw(window);
			brick27.draw(window);
			brick28.draw(window);
			brick29.draw(window);
			brick30.draw(window);

			window.display();
		}//end game loop

		return 0;
	}// end main
