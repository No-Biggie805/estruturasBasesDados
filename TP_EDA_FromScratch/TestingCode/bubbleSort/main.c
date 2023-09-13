// Bubble Sort: https://www.programiz.com/dsa/bubble-sort
/*
Bubble sort is a sorting algorithm that compares
two adjacent elements and swaps them until
they are in the intended order.

Just like the movement of air bubbles in the water that rise up to the surface, each element
of the array move to the end in each iteration. Therefore, it is called a bubble sort.
*/

// How it works??
// For demonstration porpouses its gonna be used an example in ascending order.
// 1st iteration, compare and swap.
/*
1)Starting from the first index, compare the first and the second elements.
2)If the first element is greater than the second element, they are swapped.
3)Now, compare the second and the third elements. Swap them if they are not in order.
4)The above process goes on until the last element.
*/

// Visually speaking the bubble sort algorithm will take each iteration and until every
// member of the the array has been sorted, the loop will always go through the same process continously
// across all its own iterations.

// In our example, since we are using in ascending order if a smaller is found after a
// bigger one the smaller one will be swapped, the swap process should only stop when the
// member variables are put in its right place.

#include <stdio.h>

// Performing bubble sort
void bubbleSort(int array[], int size)
{

    // loop to access each array element
    for (int step = 0; step < size - 1; step++)
    {

        // loop to compare array elements
        for (int i = 0; i < size - step - 1; i++)
        {
            // compare the two adjacent elements
            // changing > to < will sort to the descending order
            if (array[i] > array[i + 1])
            {
                // swapping oocurs if elements are not in the intended order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int main()
{
    int data[] = {-9, -2, 4, 2, 1, 0};
    // find the array's length
    int size = sizeof(data) / sizeof(data[0]);//sizeof() calculates the total size in bytes 
                                            //occupied by the entire array 'data', inc. its elements  

                                            //data[0] calculates the size in bytes of a single element,
                                            //being the 1st element the one calculated.


    bubbleSort(data, size);
    // printing the sorted array now..
    printArray(data, size);
    return 0;
}
