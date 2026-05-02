/*
Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.
*/


#include <stdio.h>

int main() {
    int n;

    // Ask for size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Ask for array elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Two-pointer reverse
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    // Print result
    printf("Reversed array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
