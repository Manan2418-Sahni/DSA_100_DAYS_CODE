/*
Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, 
traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.
*/
#include <stdio.h>

int main() {
    int r, c;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int a[r][c];

    printf("Enter %d x %d matrix elements:\n", r, c);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    printf("Spiral traversal:\n");

    while (top <= bottom && left <= right) {

        // left → right
        for (int j = left; j <= right; j++)
            printf("%d ", a[top][j]);
        top++;

        // top → bottom
        for (int i = top; i <= bottom; i++)
            printf("%d ", a[i][right]);
        right--;

        // right → left
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                printf("%d ", a[bottom][j]);
            bottom--;
        }

        // bottom → top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", a[i][left]);
            left++;
        }
    }

    return 0;
}
