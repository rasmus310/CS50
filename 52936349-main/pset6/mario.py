from cs50 import get_int

while True:
    height = get_int("Height: ") # get height from user
    if 0 < height and height <= 8: # check if height is between 1 and 8
        break # if height is between 1 and 8, break out of the loop

# print the pyramid
for i in range(height): # i means the row number and range(height) means the number of rows
 # height - i - 1 equals the number of spaces in each row before the pyramid. since range doesn't accept negative nubmer it treats it as 0
    for j in range(height - i - 1):
        # print spaces, end="" prevents a new line from being printed
        print(" ", end="")
         # i + 1 equals the number of hashes in each row
    for k in range (i + 1):
        # print hashes, end="" prevents a new line from being printed
        print("#", end="")
        # print spaces between the two pyramids
    print("  ",end="")
    # number of hashes in each row after the spaces between the pyramids
    for n in range(i + 1):
        # print hashes
        print("#", end="")
    print()
