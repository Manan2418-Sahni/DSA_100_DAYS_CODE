def merge(arr, left, mid, right):
    temp = []

    i = left
    j = mid + 1
    inversions = 0

    while i <= mid and j <= right:

        if arr[i] <= arr[j]:
            temp.append(arr[i])
            i += 1
        else:
            temp.append(arr[j])
            inversions += (mid - i + 1)
            j += 1

    while i <= mid:
        temp.append(arr[i])
        i += 1

    while j <= right:
        temp.append(arr[j])
        j += 1

    for k in range(len(temp)):
        arr[left + k] = temp[k]

    return inversions


def merge_sort(arr, left, right):

    inversions = 0

    if left < right:

        mid = (left + right) // 2

        inversions += merge_sort(arr, left, mid)
        inversions += merge_sort(arr, mid + 1, right)

        inversions += merge(arr, left, mid, right)

    return inversions


# Input
n = int(input())
arr = list(map(int, input().split()))

# Count inversions
result = merge_sort(arr, 0, n - 1)

# Output
print(result)