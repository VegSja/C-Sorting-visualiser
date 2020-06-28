#include "headers/Sort.h"

Sort::Sort(std::vector<int>* vectorPtr, int* comparedNumberIndex){
    Sort::vectorPtr = vectorPtr;
    Sort::vector = *vectorPtr;

    Sort::comparedNumberIndexPtr = comparedNumberIndex;
}

void Sort::swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

void Sort::bubbleSort(){
    int i,j;
    for(i = 0; i<Sort::vector.size()-1; i++){
        for(j = 0; j < Sort::vector.size()-1-i; j++){
            if(Sort::vector.at(j) > Sort::vector.at(j+1))

                swap(&Sort::vector.at(j), &Sort::vector.at(j+1));
                *comparedNumberIndexPtr = j;
                *vectorPtr = Sort::vector;

                std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}

/* Function to sort an array using insertion sort*/
void Sort::insertionSort()  
{  
    int i, key, j;  
    for (i = 1; i < Sort::vector.size(); i++) 
    {  
        key = vector.at(i);  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && vector.at(j) > key) 
        {  
            vector.at(j + 1) = vector.at(j);  
            j = j - 1;
            *vectorPtr = Sort::vector;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }  
        vector.at(j + 1) = key;  
        *comparedNumberIndexPtr = j+1;
    }  
}  

void Sort::cocktailSort(){
    bool swapped = true; 
    int start = 0; 
    int end = vector.size() - 1; 
  
    while (swapped) { 
        // reset the swapped flag on entering 
        // the loop, because it might be true from 
        // a previous iteration. 
        swapped = false; 
  
        // loop from left to right same as 
        // the bubble sort 
        for (int i = start; i < end; ++i) { 
            if (vector.at(i) > vector.at(i+1)) { 
                swap(&vector.at(i), &vector.at(i + 1)); 
                *vectorPtr = Sort::vector;
                *comparedNumberIndexPtr = i;
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                swapped = true; 
            } 
        } 
  
        // if nothing moved, then array is sorted. 
        if (!swapped) 
            break; 
  
        // otherwise, reset the swapped flag so that it 
        // can be used in the next stage 
        swapped = false; 
  
        // move the end point back by one, because 
        // item at the end is in its rightful spot 
        --end; 
  
        // from right to left, doing the 
        // same comparison as in the previous stage 
        for (int i = end - 1; i >= start; --i) { 
            if (vector.at(i) > vector.at(i+1)) { 
                swap(&vector.at(i), &vector.at(i + 1)); 
                *vectorPtr = Sort::vector;
                *comparedNumberIndexPtr = i;
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                swapped = true; 
            } 
        } 
  
        // increase the starting point, because 
        // the last stage would have moved the next 
        // smallest number to its rightful spot. 
        ++start; 
    } 
}

void Sort::randomSort(){
    for(int i = 0; i < this->vector.size(); i++){
        if(i != this->vector.size() - 1){
            if(this->vector.at(i) > this->vector.at(i+1)){
                //std::cout << "Randomised at: " << i << std::endl;
                i=0;
                std::random_shuffle(this->vector.begin(), this->vector.end());
                *this->vectorPtr = this->vector;
                //std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        }

    }
    std::cout << "Sorted!";
}