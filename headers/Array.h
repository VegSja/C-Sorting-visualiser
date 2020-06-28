#pragma once
#include "includes.h"

class Array{
    //Variables
    public:
        std::vector< int > vector;
        std::vector<int>* arrayPtr;
        bool changed;
    private:
        int size = 0;
        int highest_value = 0;
    //Functions
    public:
        void createVector(int size, int highest_value);
    private:
        void printVector();
        void swap(int *a, int *b);
};