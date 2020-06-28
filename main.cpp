#include "headers/Array.h"
#include "headers/Display.h"
#include "headers/Sort.h"
#include "headers/includes.h"



void printVector(std::vector<int> vector){
    for(int i = 0; i<vector.size(); i++){
        std::cout << vector.at(i) << " ";      
    }
    std::cout << '\n';
}

int getChoice(){
    int choice;
    std::cout << "Which sorting algorithm would you like to visualise?: \n 1. Bubblesort \n 2. Insertionsort \n 3. Cocktailsort \n 4. Random sort \n" << std::endl;
    std::cin >> choice;
    return choice;
}

int main(){
    //Currently the program is stuck in a loop inside this object. Go to createDisplay() for more info.
    Array array;
    array.createVector(100, 600);
    int comparedNumberIndex;
    Sort sorter = Sort(&array.vector, &comparedNumberIndex);
    Display display = Display(800, 600, &array.vector, &comparedNumberIndex);
    std::thread sortingThread;
    std::thread displayThread;
    int choice = getChoice();
    switch (choice)
    {
    case 1:{
        sortingThread = std::thread(&Sort::bubbleSort, &sorter);
        displayThread = std::thread(&Display::createDisplay, &display);
        displayThread.join();
        break;
    }
    case 2:{
        sortingThread = std::thread(&Sort::insertionSort, &sorter);
        displayThread = std::thread(&Display::createDisplay, &display);
        displayThread.join();
        break;
    }   
    case 3:{
        sortingThread = std::thread(&Sort::cocktailSort, &sorter);
        displayThread = std::thread(&Display::createDisplay, &display);
        displayThread.join();
        break;
    }  
    case 4:{
        sortingThread = std::thread(&Sort::randomSort, &sorter);
        displayThread = std::thread(&Display::createDisplay, &display);
        displayThread.join();
        break;
    }   
    default:
        break;
    }

    return 0;
}

