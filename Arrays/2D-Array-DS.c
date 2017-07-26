#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
Problem from advanced challenge in Hackerrank

Calculate the hourglass sum for every hourglass in array A, then print the maximum hourglass sum.

Hourglass is just a name for a special format/shape of values:

* * *
  *
* * *

*/

int main(void){
    int arr[6][6];
    for(int arr_i = 0; arr_i < 6; arr_i++){
       for(int arr_j = 0; arr_j < 6; arr_j++){
          
          scanf("%d",&arr[arr_i][arr_j]);
       }
    }
    
    int max = -50; // any REALLY negative number (theoretically neg. infinity)
    int curr;
    for(int a = 0; a < 4; a++){
        for(int b = 0; b < 4; b++){
            curr = arr[a][b] + arr[a][b+1] + arr[a][b+2] + arr[a+1][b+1] + arr[a+2][b] + arr[a+2][b+1] + arr[a+2][b+2];
          // This internal line ^ could be written into a loop of itself if we decided to redefine the "shape"
            if(curr >= max){
                max = curr;
            }
        }
    }
    printf("%d", max);
    
    return 0;
}

// helper function for calculating curr (line 33)
