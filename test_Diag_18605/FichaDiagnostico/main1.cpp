
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// //exercio 1)a

// // #include <stdio.h>

// // #define ARRAY_SIZE 9

// // // define the struct to hold the array
// // typedef struct FloatArray {
// //     float values[ARRAY_SIZE];
// // } FloatArray;

// // int main() {
// //     // create an instance of the FloatArray struct and initialize its values
// //     FloatArray floatArray = {{10.2, 13.3, 7, 45.7, 23.7, 12.1, 16, 19}};

// //     // iterate through the elements of the array and print them
// //     for (int i = 0; i < ARRAY_SIZE; i++) {
// //         printf("%.1f ", floatArray.values[i]);
// //     }
// //     printf("\n");

// //     return 0;
// // }

// //fim ex a)

// /*exercio b:*/


// // #define ARRAY_SIZE 9

// // // define the struct to hold each element of the array
// // typedef struct ArrayElement {
// //     float value;
// // } ArrayElement;

// // // calculate the distance between two array elements
// // float distance(ArrayElement a, ArrayElement b) {
// //     return fabs(b.value - a.value);
// // }

// // int main() {
// //     // create the array of array elements
// //     ArrayElement array[ARRAY_SIZE] = {{10.2}, {13.3}, {7}, {45.7}, {23.7}, {12.1}, {16}, {19}};

// //     // calculate the sum of all pairwise distances
// //     float sumDistances = 0;
// //     for (int i = 0; i < ARRAY_SIZE; i++) {
// //         for (int j = i + 1; j < ARRAY_SIZE; j++) {
// //             sumDistances += distance(array[i], array[j]);
// //         }
// //     }

// //     // calculate the average distance
// //     int numPairs = ARRAY_SIZE * (ARRAY_SIZE - 1) / 2;
// //     float averageDistance = sumDistances / numPairs;

// //     printf("Average distance between elements of the array: %.2f\n", averageDistance);

// //     return 0;
// // }

// // #define ARRAY_SIZE 9

// // // float distance(n a, n b);

// // typedef struct n
// // {
// //     /* data */
// //     // float x;
// //     float valores;
// // } n;

// // // calculate the distance between two objects
// // float distance(n a, n b)
// // {
// //     // return sqrt(pow(b.x - a.x, 2));
// //     return fabs(b.valores - a.valores);
// // }

// // int main()
// // {

// //     n vector[ARRAY_SIZE] = {{10.2}, {13.3}, {3}, {7}, {45.7}, {23.7}, {12.1}, {16}, {19}};
// //     float sumDistances = 0;

// //     for (int i = 0; i < ARRAY_SIZE; i++)

// //     {
// //         for (int j = i+1; j < ARRAY_SIZE; j++)
// //         {
// //             // printf("%.1f", vector[i]);

// //             sumDistances += distance(vector[i], vector[j]);
// //         }
// //     }

// //     // calculate the average distance
// //     int numPairs = ARRAY_SIZE * (ARRAY_SIZE - 1) / 2;
// //     float averageDistance = sumDistances / numPairs;

// //     printf("Average distance between elements of the array: %.2f\n", averageDistance);

// //     printf("\n");

// //     return 0;
// // }

// ///fim exb
// /*Exercio c:*/

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

// int main()
// {
//     int max=0, min=-99;
//     n vector[ARRAY_SIZE] = {{10.2}, {13.3}, {3}, {7}, {45.7}, {23.7}, {12.1}, {16}, {19}};
//     float sumDistances = 0;

//     for (int i = 0; i < ARRAY_SIZE; i++)

//     {
//         for (int j = i+1; j < ARRAY_SIZE; j++)
//         {
//             // printf("%.1f", vector[i]);

            
//             sumDistances += distance(vector[i], vector[j]);
//         }
//     }

    

//     // calculate the average distance
//     int numPairs = ARRAY_SIZE * (ARRAY_SIZE - 1) / 2;//using a, b pairing
//     float averageDistance = sumDistances / numPairs;
//     // int max=

//     printf("Average distance between elements of the array: %.2f\n", averageDistance);

//     printf("\n");

//     return 0;
// }
