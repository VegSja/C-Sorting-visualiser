#include "headers/Array.h"


void Array::createVector(int size, int highest_value){
    int generatedNumber = 0;
    for(int i = 0; i<size; i++){
        generatedNumber = rand() % highest_value + 1;
        vector.push_back(generatedNumber);
    }
}

void Array::printVector(){
    for(int i = 0; i<vector.size(); i++){
        std::cout << vector.at(i) << " ";      
    }
    std::cout << '\n';
}
