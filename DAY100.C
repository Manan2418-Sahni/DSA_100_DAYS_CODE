def merge(enum, left, mid, right, counts):
    temp = []

    i = left
    j = mid + 1
    right_count = 0

    while i <= mid and j <= right:

        if enum[j][1] < enum[i][1]:
            temp.append(enum[j])
            right_count += 1
            j += 1
        else:
            counts[enum[i][0]] += right_count
            temp.append(enum[i])
            i += 1

    while i <= mid:
        counts[enum[i][0]] += right_count
        temp.append(enum[i])
        i += 1

    while j <= right:
        temp.append(enum[j])
        j += 1

    for k in range(len(temp)):
        enum[left + k] = temp[k]


def merge_sort(enum, left, right, counts):

    if left >= right:
        return

    mid = (left + right) // 2

    merge_sort(enum, left, mid, counts)
    merge_sort(enum, mid + 1, right, counts)

    merge(enum, left, mid, right, counts)


# Input
n = int(input())
arr = list(map(int, input().split()))

# Store index with value
enum = list(enumerate(arr))

counts = [0] * n

# Merge Sort
merge_sort(enum, 0, n - 1, counts)

# Output
print(*counts)