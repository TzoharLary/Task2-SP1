#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

int main() {
    int i, j;
    char choose;

    // Allocate memory
    int **Matrix = (int**) malloc(MAT_SIZE * sizeof(int*));

    for (int i = 0; i < MAT_SIZE; ++i)
        Matrix[i] = (int*) malloc(MAT_SIZE * sizeof(int));


    // int G [4][4] = {
    // {0,1,0,4}D
    // {1,0,1,0}
    // {0,1,0,1}
    // {4,0,1,0}
    // };

    do 
    {
        scanf("%c", &choose);

        switch (choose)
        {
            case 'A':
            {
                GetInfoMatrix(Matrix, MAT_SIZE);
                break;
            }

            case 'B':
            {
                scanf("%d%d", &i, &j);
                printf("%s\n", IsThereWay(Matrix, i, j, MAT_SIZE) ? "True":"False");
                break;
            }
            

            case 'C':
            {
                scanf("%d%d", &i, &j);
                printf("%d\n", ShortestPath(Matrix, i, j, MAT_SIZE));
                break;
            }

            default:
                break;
        }
    }

    while(choose != 'D');

    // Free memory to end program
    for (int i = 0; i < MAT_SIZE; ++i)
        free(Matrix[i]);

    free(Matrix);

    return 0;
}