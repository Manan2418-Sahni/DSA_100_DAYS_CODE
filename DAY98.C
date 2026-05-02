def merge_intervals(intervals):

    # Sort intervals by start time
    intervals.sort(key=lambda x: x[0])

    merged = [intervals[0]]

    for i in range(1, len(intervals)):

        current = intervals[i]
        last = merged[-1]

        # Overlapping intervals
        if current[0] <= last[1]:
            last[1] = max(last[1], current[1])

        else:
            merged.append(current)

    return merged


# Input
n = int(input())

intervals = []

for _ in range(n):
    start, end = map(int, input().split())
    intervals.append([start, end])

# Merge intervals
result = merge_intervals(intervals)

# Output
for interval in result:
    print(interval[0], interval[1])