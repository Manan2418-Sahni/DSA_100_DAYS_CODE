def counting_sort(arr, n):

    # Find maximum element
    maximum = max(arr)

    # Frequency array
    count = [0] * (maximum + 1)

    # Store frequencies
    for num in arr:
        count[num] += 1

    # Prefix sums
    for i in range(1, len(count)):
        count[i] += count[i - 1]

    # Output array
    output = [0] * n

    # Build output array (stable sort)
    for i in range(n - 1, -1, -1):
        output[count[arr[i]] - 1] = arr[i]
        count[arr[i]] -= 1

    return output


# Input
n = int(input())
arr = list(map(int, input().split()))

# Counting Sort
sorted_arr = counting_sort(arr, n)

# Output
print(*sorted_arr)