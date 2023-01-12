#pragma once
#include"settings.h"
#include <iostream>
#include <ctime>

using namespace sf;
using namespace std;
const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 800;
const string WINDOW_TITLE = "SFML Lesson 3";
const float FPS = 120;
const float batDy = 5.f;
float dx = 2.5;
float dy = 2.5;
float sizew = 80.f;
float sizeh = 20.f;
float otstup = 50.f;
const sf::Vector2f batSize(sizew, sizeh);
const float ballRadius = 15.f;
//íà÷àëüíàÿ ïîçèöèÿ
const sf::Vector2f leftBatStartPos{ (WINDOW_WIDTH - sizew) / 2, WINDOW_HEIGHT - otstup };
//
const sf::Vector2f BallStart{ WINDOW_WIDTH / 2 - ballRadius, WINDOW_HEIGHT / 2 - ballRadius };

const sf::Color ballColor{ sf::Color::Yellow };
const sf::Color batColor{ sf::Color::Magenta };