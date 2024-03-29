#include <stdio.h>
#include <stdlib.h>

#define W 20
#define NI 5

int max(int a, int b) { return (a > b) ? a : b; }


int knapSack(int weights[], int values[], int selected_bool[]) {
    int dp[NI+1][W+1];
    int i, w;

    // Initialize Dynamic Programming table and selected_bool array
    for (i = 0; i <= NI; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i-1] <= w)
                dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    // Initialize selected_bool
    for (i = 0; i < NI; i++) {
        selected_bool[i] = 0;
    }

    // Backtrack to find selected items
    i = NI, w = W;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i-1][w]) {
            selected_bool[i-1] = 1; // Include this item
            w = w - weights[i-1];
        }
        i--;
    }

    
    return dp[NI][W]; // Maximum value
}


int main() {
    char* labels[NI], result[NI];  // Array of pointers for item labels
    int val[NI], wt[NI], Sb[NI] = {0}; // Arrays for values, weights, and selection status
    for (int i = 0; i < NI; i++) {
        labels[i] = (char*)malloc(2 * sizeof(char)); // Allocate memory for each label
        
        // Scanf for label, value, and weight in one go
        scanf("%s %d %d", labels[i], &val[i], &wt[i]);
    }

    int maxProfit = knapSack(wt, val, Sb);
    
    printf("Maximum profit: %d\n", maxProfit);
    printf("Selected items:");
     for (int i = 0; i < NI; i++) {
        if (Sb[i] == 1) {
          result[i] = *labels[i];  
        }
        free(labels[i]); // Free the allocated memory for labels
    }
    for (int i = 0; i < NI; i++){
        if (Sb[i] == 1){
            printf(" %c", result[i]);   
        }   
    }    
    return 0;
}

