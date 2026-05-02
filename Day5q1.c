/*
Problem: A system receives two separate logs of user arrival times from two different servers.
 Each log is already sorted in ascending order. Your task is to create a single chronological log that
preserves the correct order of arrivals.
*/

#include <stdio.h>

int main() {
    int p, q;

    // Read size of first log
    printf("Enter number of entries in server log 1: ");
    scanf("%d", &p);

    int a[p];

    printf("Enter %d sorted arrival times for log 1:\n", p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // Read size of second log
    printf("Enter number of entries in server log 2: ");
    scanf("%d", &q);

    int b[q];

    printf("Enter %d sorted arrival times for log 2:\n", q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int i = 0, j = 0;

    printf("Merged chronological log:\n");

    // Merge both arrays
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    // Print remaining elements of a[]
    while (i < p) {
        printf("%d ", a[i]);
        i++;
    }

    // Print remaining elements of b[]
    while (j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
}
