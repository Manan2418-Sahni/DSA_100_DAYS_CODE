/*
Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be
symmetric if it is a square matrix and is equal to its transpose 
(i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).
*/
#include <stdio.h>
int main(){
    
    int r,c;
    
    printf("Enter the matrix rows and columns\n");
    scanf("%d %d", &r, &c);

    int arr[r][c];
    int temp[c][r];

    printf("Enter the elements of the matrix\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    if(r==c){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                temp[j][i]= arr[i][j];

            }
        }
        printf("matrix is square and its transpose is:\n");
         for(int i=0;i<c;i++){
            for(int j=0;j<r;j++){
                printf("%d ", temp[j][i]);

            }
            printf("\n");
        }
    }else
    printf("Matrix is not square");
}