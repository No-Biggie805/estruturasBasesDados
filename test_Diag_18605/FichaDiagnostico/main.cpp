
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// #include <stdio.h>

// #define ARRAY_SIZE 9

// // define the struct to hold the array
// typedef struct FloatArray {
//     float values[ARRAY_SIZE];
// } FloatArray;

// int main() {
//     // create an instance of the FloatArray struct and initialize its values
//     FloatArray floatArray = {{10.2, 13.3, 7, 45.7, 23.7, 12.1, 16, 19}};

//     // iterate through the elements of the array and print them
//     for (int i = 0; i < ARRAY_SIZE; i++) {
//         printf("%.1f ", floatArray.values[i]);
//     }
//     printf("\n");

//     return 0;
// }

// #define ARRAY_SIZE 9

// typedef struct FloatArray {
// // define the struct to hold the array
//     float values[ARRAY_SIZE];
// } FloatArray;

// int main() {
//     // create an instance of the FloatArray struct and initialize its values
//     FloatArray floatArray = {{10.2, 13.3, 7, 45.7, 23.7, 12.1, 16, 19}};

//     // iterate through the elements of the array and print them
//     for (int i = 0; i < ARRAY_SIZE; i++) {
//         printf("%.1f ", floatArray.values[i]);
//     }
//     printf("\n");

//     return 0;
// }

// In this example, we define the FloatArray struct which contains an array of floating point values. We then create an instance of this struct and initialize its values using an initializer list. Finally, we iterate through the elements of the array and print them using a for loop and the %f format specifier. Note that we use the .values member to access the array within the FloatArray struct.

/*exercio b:*/

// #define ARRAY_SIZE 9

// // define the struct to hold each element of the array
// typedef struct ArrayElement {
//     float value;
// } ArrayElement;

// // calculate the distance between two array elements
// float distance(ArrayElement a, ArrayElement b) {
//     return fabs(b.value - a.value);
// }

// int main() {
//     // create the array of array elements
//     ArrayElement array[ARRAY_SIZE] = {{10.2}, {13.3}, {7}, {45.7}, {23.7}, {12.1}, {16}, {19}};

//     // calculate the sum of all pairwise distances
//     float sumDistances = 0;
//     for (int i = 0; i < ARRAY_SIZE; i++) {
//         for (int j = i + 1; j < ARRAY_SIZE; j++) {
//             sumDistances += distance(array[i], array[j]);
//         }
//     }

//     // calculate the average distance
//     int numPairs = ARRAY_SIZE * (ARRAY_SIZE - 1) / 2;
//     float averageDistance = sumDistances / numPairs;

//     printf("Average distance between elements of the array: %.2f\n", averageDistance);

//     return 0;
// }

// #define ARRAY_SIZE 9

// typedef struct n
// {
//     /* data */
//     // float x;
//     float valores;
// } n;

// // calculate the distance between two objects
// float distance(n a, n b)
// {
//     // return sqrt(pow(b.x - a.x, 2));
//     return fabs(b.valores - a.valores); // this function will return |(b-a)|
// }

// int main()
// {

//     n vector[ARRAY_SIZE] = {{10.2}, {13.3}, {3}, {7}, {45.7}, {23.7}, {12.1}, {16}, {19}};
//     float sumDistances = 0;

//     for (int i = 0; i < ARRAY_SIZE; i++) // irá permanecer no ponto 0 do array, sem mudança, como ciclo de fora

//     {
//         for (int j = i + 1; j < ARRAY_SIZE; j++) // irá percorrer como o ciclo de dentro
//         {
//             // printf("%.1f", vector[i]);

//             sumDistances += distance(vector[i], vector[j]);
//         }
//     }

//     // calculate the average distance
//     int numPairs = ARRAY_SIZE * (ARRAY_SIZE - 1) / 2;
//     float averageDistance = sumDistances / numPairs;

//     printf("Average distance between elements of the array: %.2f\n", averageDistance);

//     printf("\n");

//     return 0;
// }

/*Exercio c:*/
// //Versao antiga a atualizacao ocorre ao longo do percurso das linhas
// #define ARRAY_SIZE 9

// // float distance(n a, n b);

// typedef struct n
// {
//     /* data */
//     // float x;
//     float valores;
// } n;

// // calculate the distance between two objects
// float distance(n a, n b)
// {
//     // return sqrt(pow(b.x - a.x, 2));
//     return fabs(b.valores - a.valores);
// }

// // Versao atualizada, o percurso sera feito ao longo do ciclo das colunas (2D).

// #define ARRAY_SIZE 8

// // float distance(n a, n b);

// typedef struct n
// {
//     /* data */
//     // float x;
//     float valores;
// } n;

// // calculate the distance between two objects
// float distance(n a, n b)
// {
//     // return sqrt(pow(b.x - a.x, 2));
//     return fabs(b.valores - a.valores);
// }

// int main()
// {
//     float max = 0;
//     int MaxIndex;
//     n vector[ARRAY_SIZE] = {{10.2}, {13.3}, {3}, {7}, {45.7}, {23.7}, {12.1}, {16}, {19}};
//     float sumDistances = 0;

//     for (int i = 0; i < ARRAY_SIZE; i++)

//     {
//         for (int j = i + 1; j < ARRAY_SIZE; j++)
//         {
//             // if (i != j)
//             // {
//                 sumDistances += distance(vector[i], vector[j]);
//                 if (sumDistances > max) // Updating the value constatly..
//                 {
//                     max = sumDistances; // we store any new value inside the max value
//                     MaxIndex = i;       // and update the index
//                 }
//             // }
//         }
//     }

//     // print the element with the maximum distance
//     /*adding vector[MaxIndex].valores to call the correct maximum out of the array which is being used recurring from the data structure,
//     and then the MaxIndex to such print where is the index of how max distanced value*/
//     printf("The element with the maximum distance is %f at the index of %d: ", vector[MaxIndex].valores, MaxIndex);
//     printf("\n");

//     return 0;
// }

// #define ARRAY_SIZE 8

// typedef struct ArrayElement
// {
//     float value;
// } ArrayElement;

// // calculate the distance between two array elements
// float distance(ArrayElement a, ArrayElement b)
// {
//     return fabs(b.value - a.value); // Fabs returns an operation with only positive results -->(|b-a|)
// }

// int main()
// {
//     ArrayElement array[ARRAY_SIZE] = {{10.2}, {13.3}, {7}, {45.7}, {23.7}, {12.1}, {16}, {19}};

//     float maxDistance = 0;
//     int maxIndex = -1;
//     int i_index = -1;
//     for (int i = 0; i < ARRAY_SIZE; i++) // Linhas, so tem 1 que dara index 0
//     {
//         for (int j = i + 1; j < ARRAY_SIZE; j++) // Colunas, tem 8 que ira de 1-8
//                                                  // Obs: podemos claro considera i como 0, ou seja i + 1 ou 0 + 1, serao a mesma coisa
//         {
//             float d = distance(array[i], array[j]); // distance is diference between index of i and j to prevent wrong calculations, unlike just using "i" or "j"
//             if (d > maxDistance)
//             {
//                 maxDistance = d;
//                 maxIndex = j; //(d == distance(array[i], array[maxIndex])) ? i : j;
//                 i_index = i;
//                 // if (d == distance(array[i], array[maxIndex]))
//                 // {
//                 //     maxIndex = i;
//                 // }
//                 // else
//                 // {
//                 //     maxIndex = j;
//                 // }
//             }
//         }
//     }

//     printf("The element with the maximum distance is %.2f at index %d and i index %d.\n", array[maxIndex].value, maxIndex, i_index);

//     return 0;
// }
// // fim da alínea C

// Colocar numa função que consiga devolver os resultados mostrados em b) e c)
#define ARRAY_SIZE 8

typedef struct n
{
    float value;
} n;

// calculate the distance between two array elements
float distance(n a, n b)
{
    return fabs(b.value - a.value); // Fabs returns an operation with only positive results -->(|b-a|)
}

int main()
{

    n vector[ARRAY_SIZE] = {{10.2}, {13.3}, {7}, {45.7}, {23.7}, {12.1}, {16}, {19}};
    float sumDistances = 0, d = 0;
    float max = 0;
    int MaxIndex = -1;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j = i + 1; j < ARRAY_SIZE; j++)
        {
            sumDistances += distance(vector[i], vector[j]);
            d = distance(vector[i], vector[j]);
            if (d > max)
            {
                max = d;
                MaxIndex = j;
            }
        }
    }
    // calculate the average distance
    int numPairs = ARRAY_SIZE * (ARRAY_SIZE - 1) / 2;
    float averageDistance = sumDistances / numPairs;

    printf("Average distance between elements of the array: %.2f\n", averageDistance);
    printf("\n");
    printf("Furthest away object is %.2f, with its index of %d", max, MaxIndex);
    printf("\n");

    return 0;
}