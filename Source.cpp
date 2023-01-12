#include <SFML/Graphics.hpp>
#include<ctime>
#include <string>
#include <iostream>
#include"settings.h"
#include"func.h"

int main()
{

	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//������ �������
	RectangleShape r;
	initBat(r, batColor, leftBatStartPos);
	//����� �������

	CircleShape circl;
	initBall(circl, ballColor, BallStart);

	//����
	int score = 0;
	Font font;
	font.loadFromFile("arial.ttf");
	Text right_score_text(to_string(score), font, 64);
	right_score_text.setPosition(WINDOW_WIDTH / 2 - 25.f, 50.f);

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}

		//��
		//������ ����
		//������������ �� ������
		circl.move(dx, dy);
		if ((circl.getPosition().x + 2 * ballRadius >= WINDOW_WIDTH)) {
			dx = -dx;
		}
		if (circl.getPosition().x <= 0) {
			dx = -dx;
		}
		if ((circl.getPosition().y + 2 * ballRadius >= WINDOW_HEIGHT) or (circl.getPosition().y <= 0)) {
			dy = -dy;
		}
		//������������ �� ������� �� �
		float midLeftX = circl.getPosition().x;
		float midRightX = circl.getPosition().x + 2 * ballRadius;
		float midUpY = circl.getPosition().y;
		float midLowY = circl.getPosition().y + 2 * ballRadius;
		if ((midLeftX <= r.getPosition().x) and (midRightX >= r.getPosition().x)
			and (midUpY + ballRadius >= r.getPosition().y)
			and (midLowY - ballRadius <= r.getPosition().y + sizeh)) {
			dx = -dx;
		}
		//������������ �� ������� �� �
		if ((midLowY >= r.getPosition().y) and (midLeftX + ballRadius >= r.getPosition().x) and (midRightX <= r.getPosition().x + sizew)) {
			dy = -dy;
			score++;
			right_score_text.setString(to_string(score));
		}

		//�������� ����� �������

		if (Keyboard::isKeyPressed(Keyboard::D)) {
			r.move(batDy, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::A)) {
			r.move(-batDy, 0);
		}
		if ((r.getPosition().x + sizew >= WINDOW_WIDTH)) {
			r.setPosition(WINDOW_WIDTH - sizew, WINDOW_HEIGHT - otstup);
		}
		if ((r.getPosition().x <= 0)) {
			r.setPosition(0, WINDOW_HEIGHT - otstup);
		}

		// ��������� ����  
		window.clear();
		window.draw(r);
		window.draw(circl);
		window.draw(right_score_text);
		window.display();
	}
	return 0;
}