#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
Calculate the hourglass sum for every hourglass in array A, then print the maximum hourglass sum.

Hourglass format:
* * *
  *
* * *


*/

int main(){
    int arr[6][6];
    for(int arr_i = 0; arr_i < 6; arr_i++){
       for(int arr_j = 0; arr_j < 6; arr_j++){
          
          scanf("%d",&arr[arr_i][arr_j]);
       }
    }
    
    int max = -50;
    int curr;
    for(int a = 0; a < 4; a++){
        for(int b = 0; b < 4; b++){
            curr = arr[a][b] + arr[a][b+1] + arr[a][b+2] + arr[a+1][b+1] + arr[a+2][b] + arr[a+2][b+1] + arr[a+2][b+2];
            if(curr >= max){
                max = curr;
            }
        }
    }
    printf("%d", max);
    return 0;
}