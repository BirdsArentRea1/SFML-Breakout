#include <SFML/Graphics.hpp>

//#include<iostream>
//using namespace std;
#include <stdlib.h>

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
		xvel = 0.3;
		yvel = 0.3;
		radius = 15;

		shape.setRadius(radius);
		shape.setPosition(xpos, ypos);
		shape.setFillColor(sf::Color::White);
	}
	void move(float windowWidth, float windowHeight) {
		xpos += xvel*0.7;
		ypos += yvel;
		//cout << "xpos is"<<xpos << endl;
		
		if (xpos <= 0 || xpos + radius * 2 >= windowWidth) {
			xvel = -xvel;
		}
		
		if (ypos <= 0 || ypos + radius * 2 >= windowWidth) {
			yvel = -yvel;
		}

		shape.setPosition(xpos, ypos);
	}
	bool brickCollision(Brick& brick) {
		return brick.checkCollision(xpos + radius, ypos + radius, radius);
	}


	/*bool paddleCollision(Paddle& paddle) {
		return paddle.checkCollision(paddle.getX(), paddle.getY(), paddle.getW(), paddle.getH());

	}*/

	bool paddleCollision(int PaddleX, int PaddleY, int PaddleW, int PaddleH) {
		/*system("CLS");
		printf("Ball: X: %f, Y: %f, \nPaddle: X:%d, Y:%d\nballY > paddleY: xpos + radius > PaddleX: %d\nxpos - radius < PaddleX + PaddleW: %d\nypos + radius > PaddleY && ypos: %d\nypos - radius < PaddleY + PaddleH: %d",
			xpos, ypos, PaddleX, PaddleY, xpos + radius > PaddleX, xpos - radius < PaddleX + PaddleW, ypos + radius > PaddleY, ypos - radius < PaddleY + PaddleH);*/
		if (xpos + radius > PaddleX && xpos - radius < PaddleX + PaddleW &&
			ypos + radius > PaddleY && ypos - radius < PaddleY + PaddleH) {
			yvel *= -1;
			return true;
		}
		return false;
	}

	

	void draw(sf::RenderWindow& window) {

		window.draw(shape);

	}

};

class Paddle {
private:
	float width;
	float height;
	float xpos;
	float ypos;
	float speed;
	sf::RectangleShape shape;

public:
	Paddle(float x, float y, float w, float h) {
		xpos = x;
		ypos = y;
		width = w;
		height = h;
		speed = 0.3;

		shape.setSize(sf::Vector2f(width, height));
		shape.setPosition(xpos, ypos);
		shape.setFillColor(sf::Color::Blue);
	}

	void moveRight() {
		xpos += speed;
		if (xpos > 620) xpos = 620;
		shape.setPosition(xpos, ypos);
	}

	void moveLeft() {
		xpos -= speed;
		if (xpos < 0) xpos = 0;
		shape.setPosition(xpos, ypos);
	}

	bool checkCollision(float paddleX, float paddleY, float paddleW, float paddleH) {
		if(paddleX > xpos&& paddleX < xpos + paddleW &&
			paddleY > ypos&& paddleY < ypos + paddleH) {
				return true;
		}
		return false;
	}

	void draw(sf::RenderWindow& window) {
		window.draw(shape);
	}
	//accessor functions
	float getX() { return xpos; }
	float getY() { return ypos; }
	float getW() { return width; }
	float getH() { return height; }
};

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "BREAKOUT");

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

	Ball ball(400, 400, 10, 10);
	Paddle Paddle(300, 550, 180, 20);




	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			Paddle.moveRight();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			Paddle.moveLeft();
		}

		//physics
		ball.brickCollision(brick1);
		ball.brickCollision(brick2);
		ball.brickCollision(brick3);
		ball.brickCollision(brick4);
		ball.brickCollision(brick5);
		ball.brickCollision(brick6);
		ball.brickCollision(brick7);
		ball.brickCollision(brick8);
		ball.brickCollision(brick9);
		ball.brickCollision(brick10);
		ball.brickCollision(brick11);
		ball.brickCollision(brick12);
		ball.brickCollision(brick13);
		ball.brickCollision(brick14);
		ball.brickCollision(brick15);
		ball.brickCollision(brick16);
		ball.brickCollision(brick17);
		ball.brickCollision(brick18);
		ball.brickCollision(brick19);
		ball.brickCollision(brick20);
		ball.brickCollision(brick21);
		ball.brickCollision(brick22);
		ball.brickCollision(brick23);
		ball.brickCollision(brick24);
		ball.brickCollision(brick25);
		ball.brickCollision(brick26);
		ball.brickCollision(brick27);
		ball.brickCollision(brick28);
		ball.brickCollision(brick29);
		ball.brickCollision(brick30);

		
		ball.move(800,600);
		ball.paddleCollision(Paddle.getX(), Paddle.getY(), Paddle.getW(), Paddle.getH());

		//render
		window.clear();

		ball.draw(window);
		Paddle.draw(window);

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
