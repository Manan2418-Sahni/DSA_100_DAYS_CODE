def bucket_sort(arr, n):

    # Create n empty buckets
    buckets = [[] for _ in range(n)]

    # Insert elements into buckets
    for num in arr:
        index = int(num * n)
        buckets[index].append(num)

    # Sort each bucket
    for bucket in buckets:
        bucket.sort()

    # Concatenate buckets
    result = []

    for bucket in buckets:
        result.extend(bucket)

    return result


# Input
n = int(input())
arr = list(map(float, input().split()))

# Perform Bucket Sort
sorted_arr = bucket_sort(arr, n)

# Output
print(*sorted_arr)