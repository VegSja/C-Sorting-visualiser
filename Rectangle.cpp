#include "headers/Rectangle.h"

Rectangle::Rectangle(sf::Vector2f widthAndHeight, sf::Color color, sf::Vector2f rectanglePos){
    Rectangle::rect = sf::RectangleShape(widthAndHeight);
    rect.setFillColor(color);
    rect.setPosition(rectanglePos);
}