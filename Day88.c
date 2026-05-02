/*
Problem Statement
Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.
This is an optimization problem where binary search on the answer is required.
*/
#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Function to check if cows can be placed
int canPlace(int stalls[], int n, int k, int distance)
{
    int cows = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - lastPos >= distance)
        {
            cows++;
            lastPos = stalls[i];
        }

        if (cows >= k)
            return 1;
    }

    return 0;
}

int main()
{
    int n, k;

    // Input n and k
    scanf("%d %d", &n, &k);

    int stalls[n];

    // Input stall positions
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stalls[i]);
    }

    // Sort the stall positions
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    // Binary Search on answer
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (canPlace(stalls, n, k, mid))
        {
            ans = mid;
            low = mid + 1; // Try for larger distance
        }
        else
        {
            high = mid - 1; // Reduce distance
        }
    }

    // Output maximum minimum distance
    printf("%d\n", ans);

    return 0;
}