def is_possible(books, n, m, max_pages):
    students = 1
    pages_sum = 0

    for i in range(n):
        # If a single book has more pages than max_pages
        if books[i] > max_pages:
            return False

        if pages_sum + books[i] > max_pages:
            students += 1
            pages_sum = books[i]

            if students > m:
                return False
        else:
            pages_sum += books[i]

    return True


def allocate_books(books, n, m):
    if m > n:
        return -1

    low = max(books)
    high = sum(books)
    answer = high

    while low <= high:
        mid = (low + high) // 2

        if is_possible(books, n, m, mid):
            answer = mid
            high = mid - 1
        else:
            low = mid + 1

    return answer


# Input
n, m = map(int, input().split())
books = list(map(int, input().split()))

# Output
print(allocate_books(books, n, m))