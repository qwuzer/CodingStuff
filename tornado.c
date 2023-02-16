#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int m, n;
    printf("Please enter the width: ");
    scanf("%d", &m);
    printf("Please enter the height: ");
    scanf("%d", &n);

    // Check for valid input
    if (m <= 0 || n <= 0) {
        fprintf(stderr, "Invalid input\n");
        exit(1);
    }

    int arr[m][n]; // Create a 2D array to hold the output

    int i = 0, j = 0, num = 1, layer = 0;

    while ( num <= n*m )
    {
        //left to right layer = 1 m = 3 n = 3
        for( int k = layer ; k < n - layer ; k++ )
        {
            arr[layer][k] = num;

            num++;
        }

        //up to down layer  = 1 
        for( int k = layer + 1 ; k < m - layer ; k++ )
        {
            arr[k][n - layer - 1] = num;
            num++;
        }

        //right to left
        for( int k = n - layer - 2; k >= layer && m - layer - 1 != i; k-- )
        {
            arr[m - layer - 1][k] = num;
            num++;
        }

        //down to up
        for( int k = m - layer - 2; k > layer && n - layer - 1 != j; k-- )
        {
            arr[k][layer] = num;
            num++;
        }

        layer++;
        i++;
        j++;
    }

    for( int i = 0 ; i < m ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            printf("%2d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
