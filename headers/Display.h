#pragma once
#include "includes.h"
#include "Array.h"

class Display{
    //Variables
    private:
        Array array;
        std::vector<int>* vectorPtr;
        int* comparedIndexPtr;
    public:
        int width;
        int height;
    //Functions
    private:
    public:
        void createDisplay();
        Display(int width, int height, std::vector<int>* vector, int* comparedNumberIndexPtr);
};