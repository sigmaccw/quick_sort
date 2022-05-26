#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_array(const char * keyword, int *array, int arraySize)
{
    int i = 0;
    printf("%s = [", keyword);
    for(i = 0; i < arraySize; i++){
        printf("%d", array[i]);
        if(i >= arraySize - 1){
            printf("]\n");
        }
        else{
            printf(", ");
        }
    }
}

int quicksort(int *array, int arraySize)
{
    int i = 0;
    int j = arraySize - 1;
    int pivot = 0;
    int tmp = 0;

    if(arraySize <= 1){
        // filter the array size less than 1, no need to sort
        return 0;
    }

    while(i != j){
        if(array[j] >= array[pivot]){
            // array[j] larger than pivot, no need to move, shift pointer left 
            j--;
        }
        else{
            // array[j] smaller than pivot, should be one the left hand side, find the swap target
            if(array[i] <= array[pivot]){
                // array[i] smaller than pivot, no need to move, shift pointer to right
                i++;
            }
            else{
                // array[i] larger than pivot, should be on the right hand side, swap array[i] and array[j]
                tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
            }
        }
    }
    // pivot should be in the place of i, so swap array[i] and array[pivot]
    tmp = array[pivot];
    array[pivot] = array[i];
    array[i] = tmp;
    // sort the left hand side of the pivot
    quicksort(&array[0], i);
    // sort the right hand side of the pivot
    quicksort(&array[i + 1], arraySize - i - 1);
    return 0;
}

int main(int argc, char *argv[])
{
    int array[] = { 2, 5, 1, 4, 3, 11, 10 };
    int i = 0;
    int size = sizeof(array)/sizeof(int);
    
    print_array("input", array, size);
    quicksort(array, sizeof(array)/sizeof(int));
    print_array("output", array, size);
    return 0;
}
