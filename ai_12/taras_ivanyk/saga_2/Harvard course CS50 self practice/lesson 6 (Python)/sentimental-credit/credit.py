from cs50 import get_int

def main():
    while True:
        number = get_int("Number: ")
        if is_valid_card_number(number):
            get_card_type(number)
            break
        else:
            print("INVALID")
            break

def is_valid_card_number(num):
    total_sum = 0
    alternate = False
    while num > 0:
        digit = num % 10

        if alternate:
            digit *= 2
            if digit > 9:
                digit = (digit % 10) + (digit // 10)

        total_sum += digit
        alternate = not alternate
        num //= 10

    return (total_sum % 10) == 0

def get_card_type(num):
    start = num
    length = len(str(num))

    while start >= 100:
        start //= 10

    if length == 15 and (start == 34 or start == 37):     # Check Amex
        print("AMEX")
    elif length == 16 and (51 <= start <= 55):           # Check MasterCard
        print("MASTERCARD")
    elif (length == 13 or length == 16) and (start // 10 == 4):  # Check Visa
        print("VISA")
    else:
        print("INVALID")

main()
