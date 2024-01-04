# Import the get_int function from the cs50 library. This function is likely used to get an integer input from the user.
from cs50 import get_int

# Create an infinite loop that will keep asking the user for a card number until a valid length is provided (13, 15, or 16 digits).
while True:
    number = get_int("Card number: ")  # Get the card number from the user as an integer.
    if len(str(number)) in [13, 15, 16]:  # Check if the length of the card number is 13, 15, or 16 digits.
        break  # Exit the loop if the length is valid.

# Convert the card number to a list of its individual digits.
digits = [int(d) for d in str(number)]

# Iterate through the digits of the card number in reverse order, starting from the second-to-last digit.
for i in range(len(digits) - 2, -1, -2):
    # Double each digit in the even positions and adjust the result if it's greater than or equal to 10.
    digits[i] *= 2
    if digits[i] >= 10:
        digits[i] -= 9

# Check if the sum of all the digits in the modified card number is divisible by 10 (Luhn's Algorithm).
if sum(digits) % 10 == 0:
    print("valid card")  # If the sum is divisible by 10, the card is considered valid.
else:
    print("invalid card")  # If the sum is not divisible by 10, the card is considered invalid.

if str(number).startswith("4") and (len(str(number)) == 13 or len(str(number)) == 16):
    print("Visa")

elif str(number).startswith("34") or str(number).startswith("37") and (len(str(number)) == 15):
    print("American Express")

elif len(str(number)) == 16 and any(str(number).startswith(str(i))
    for i in range(51, 56)):
        print("Master card")