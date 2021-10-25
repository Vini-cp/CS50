from cs50 import get_int
# This is where we get the number of rows
n = 0

# Do while we get a number between 1 and 8
while n < 1 or n > 8:
    n = get_int("Height: ")

# In this section we're going to print the "#"
for i in range(n):
    for j in range(n-1, -1, -1):
        if j > i:
            # This is where we print the space symbol
            print(" ", end='')
        elif j <= i:
            # This is where we print the "#" symbol
            print("#", end='')

    # This is where we jump to the next line
    print("\n", end='')