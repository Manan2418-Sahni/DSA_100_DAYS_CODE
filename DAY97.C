import heapq


def min_meeting_rooms(intervals):

    # Sort meetings by start time
    intervals.sort(key=lambda x: x[0])

    # Min-heap to store end times
    heap = []

    # Add first meeting end time
    heapq.heappush(heap, intervals[0][1])

    for i in range(1, len(intervals)):

        start, end = intervals[i]

        # Reuse room if meeting ended
        if start >= heap[0]:
            heapq.heappop(heap)

        # Allocate current meeting
        heapq.heappush(heap, end)

    return len(heap)


# Input
n = int(input())

intervals = []

for _ in range(n):
    start, end = map(int, input().split())
    intervals.append([start, end])

# Output
print(min_meeting_rooms(intervals))