from cs50 import get_int

# Prompt user for height between 1 and 8
height = 0
while height < 1 or height > 8:
    height = get_int("Height: ")

# Build pyramid
for i in range(height):
    for j in range(height):
        if (i + j) < (height - 1):
            print(" ", end="")
        else:
            print("#", end="")
    # Print out space between pyramids
    print("  ", end="")
    # Print out left-aligned hashes
    for k in range(i + 1):
        print("#", end="")
    print()
