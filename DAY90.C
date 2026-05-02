def is_possible(boards, n, k, max_time):
    painters = 1
    total = 0

    for i in range(n):

        # If a single board is greater than max_time
        if boards[i] > max_time:
            return False

        # Assign to next painter
        if total + boards[i] > max_time:
            painters += 1
            total = boards[i]

            if painters > k:
                return False
        else:
            total += boards[i]

    return True


def painter_partition(boards, n, k):

    low = max(boards)
    high = sum(boards)
    answer = high

    while low <= high:

        mid = (low + high) // 2

        if is_possible(boards, n, k, mid):
            answer = mid
            high = mid - 1
        else:
            low = mid + 1

    return answer


# Input
n, k = map(int, input().split())
boards = list(map(int, input().split()))

# Output
print(painter_partition(boards, n, k))