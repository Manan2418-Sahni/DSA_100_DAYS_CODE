/*
Problem: Write a program to find the maximum and minimum values present in a given array of integers.
*/
#include <stdio.h>
int main(){
    int n,min,max;
    printf("Enter the no. of array elements: ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
  
    max=arr[0];
    min=arr[0];

    for(int i=0;i<n;i++){
        if (arr[i]>max)
        max=arr[i];
        if (arr[i]<min)
        min=arr[i];
    }
    printf("min is %d and max is %d", min, max);
    return 0;
}