/*
Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.
*/

#include <stdio.h>

int main() {
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    if (n == 0) return 0;
    
    // Remove duplicates from sorted array
    int j = 0;  // Index for unique elements
    
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    
    // Print unique elements
    printf("Unique elements: ");
    for (int i = 0; i <= j; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    
    return 0;
}