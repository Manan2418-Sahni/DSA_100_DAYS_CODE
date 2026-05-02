def can_paint(boards, n, k, limit):
    painters = 1
    total = 0

    for i in range(n):

        # If one board itself exceeds limit
        if boards[i] > limit:
            return False

        # Assign new painter
        if total + boards[i] > limit:
            painters += 1
            total = boards[i]

            if painters > k:
                return False
        else:
            total += boards[i]

    return True


def minimum_time(boards, n, k):

    low = max(boards)
    high = sum(boards)
    ans = high

    while low <= high:

        mid = (low + high) // 2

        if can_paint(boards, n, k, mid):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1

    return ans


# Input
n, k = map(int, input().split())
boards = list(map(int, input().split()))

# Output
print(minimum_time(boards, n, k))