from cs50 import get_int

height = get_int("Height ")

while True:
    if height > 0 and height <= 8:
        for i in range(1, height):
            num_space = i
            print(" " * (height - i), end="")
            print("#" * i)
        break
    else:
        height = get_int("Height ")