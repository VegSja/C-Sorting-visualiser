#include "headers/Display.h"
#include "headers/Rectangle.h"

Display::Display(int width, int height, std::vector<int>* vector, int* comparedNumberIndexPtr){
    Display::width = width;
    Display::height = height;
    Display::vectorPtr = vector;
    Display::comparedIndexPtr = comparedNumberIndexPtr;
}

void Display::createDisplay(){
    sf::RenderWindow window(sf::VideoMode(Display::width, Display::height), "Window");
    
    //This is where everything happens.
    while(window.isOpen()){
        window.clear();
        //--------------------Draw array---------------------------
        int comparedIndex = *comparedIndexPtr;

        std::vector<int> arrayToUse = *vectorPtr;
        int rectWidth = width/arrayToUse.size();
        for(int i = 0; i<arrayToUse.size(); i++){
            Rectangle rectangle(sf::Vector2f(rectWidth, -arrayToUse.at(i)), sf::Color::White, sf::Vector2f(rectWidth * i, Display::height));
            if(int i = comparedIndex){
                Rectangle rectangle(sf::Vector2f(rectWidth, -arrayToUse.at(i)), sf::Color::Red, sf::Vector2f(rectWidth * i, Display::height));
                window.draw(rectangle.rect);
            }
            window.draw(rectangle.rect);
        }
        
        //---------------------------------------------------
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.display();
    }
}