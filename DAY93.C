def insertion_sort(arr, n):

    for i in range(1, n):

        key = arr[i]
        j = i - 1

        # Move elements greater than key one position ahead
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key


# Input
n = int(input())
arr = list(map(int, input().split()))

# Sort array
insertion_sort(arr, n)

# Output
print(*arr)