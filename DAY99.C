def car_fleet(target, position, speed):

    # Pair position and speed
    cars = list(zip(position, speed))

    # Sort by position descending
    cars.sort(reverse=True)

    fleets = 0
    prev_time = 0

    for pos, spd in cars:

        # Time to reach target
        time = (target - pos) / spd

        # New fleet
        if time > prev_time:
            fleets += 1
            prev_time = time

    return fleets


# Input
target = int(input())

n = int(input())

position = list(map(int, input().split()))
speed = list(map(int, input().split()))

# Output
print(car_fleet(target, position, speed))