#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"
#include <limits.h>  // Include this at the top of your file

#define INF INT_MAX

int min(int a, int b) {
    return (a < b) ? a : b;
}

// get int for any element of the matrix
void GetInfoMatrix(int** Mat, int len){
    for (int i =0; i<len; i++){
        for(int j = 0; j<len; j++){
            scanf("%d", &Mat[i][j]);
        }
    }
}
int ShortestPath (int** Mat, int st, int end, int len){
     // Distance matrix
    int dist[len][len];
    int i, j, k;

    // Initialize the solution matrix same as input graph matrix.
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = (Mat[i][j] == 0) ? INF : Mat[i][j];
            }     
       }
    }

    // Add all vertices one by one to the set of intermediate vertices.
    for (k = 0; k < len; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < len; i++) {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < len; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance between st and end
    if (dist[st][end] == 0 || dist[st][end] == INF ) {
        return -1;
    } else {
        return dist[st][end];
    }
}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   


int IsThereWay(int** Mat,int i, int j, int len){
    int ans = ShortestPath(Mat, i , j , len);

    if (ans>0){
        return true;
    }
    else{
        return false;
    }

   
}

