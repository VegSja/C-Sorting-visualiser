#pragma once
#include "includes.h"

class Rectangle{
    //Variables
    public:
        sf::RectangleShape rect;
    private:
    //Functions
    public:
        sf::RectangleShape getRect();
        Rectangle(sf::Vector2f widthAndHeight, sf::Color color, sf::Vector2f rectanglePos);
    private:

};