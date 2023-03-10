/*Devolver todas as distâncias em ORDEM CRESCENTE
e associando a cada distância o código de cada objecto respectivo*/

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
            // sumDistances += distance(vector[i], vector[j]);

            d = distance(vector[i], vector[j]);
            printf("Cada distancia devolvida temos: %f", d);

            if (d > max)
            {
                max = d;
                MaxIndex = j;
            }
        }
    }

    // // printf("Furthest away object is %.2f, with its index of %d", max, MaxIndex);
    // for (int i = 0; i < ARRAY_SIZE; i++)
    // {
    //     for (int j = i + 1; j < ARRAY_SIZE; j++)
    //     {
    //         // Returning the distances
    //         printf("Cada distancia devolvida temos: %f", d[j]);
    //     }
    // }

    printf("\n");

    return 0;
}