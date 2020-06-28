#include "includes.h"

class Sort{
    //Variables
    public:
    private:
        std::vector<int>* vectorPtr;
        std::vector<int> vector;

        int* comparedNumberIndexPtr;
        int comparedNumberIndex;
    //Functions
    public:
        Sort(std::vector<int>* vectorPtr, int* comparedNumberIndex);
        void bubbleSort();
        void insertionSort();
        void cocktailSort();
        void randomSort();
    private:
        void swap(int *xp, int *yp);
};