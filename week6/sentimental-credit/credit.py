# TODO
from sys import exit

def main():
    while True: # We keep asking the user for the right answer until it's done
        try :
            nbr = input("Number: ")
            break
        except ValueError :
            continue
    # We check the first numbers fit
    if check_start(nbr) and check_len(nbr) and check_sum(nbr):
        print_card(nbr)
        exit(0)
    else :
        print("INVALID")
        exit(1)

def check_start(nbr):
    possibilities = [34, 37, 4]
    possibilities += list(range(51,56))

    if int(nbr[0:2]) in possibilities or int(nbr[0]) in possibilities :
        return True
    else : return False


def check_len(nbr):
    possibilities = [13, 15, 16]

    return True if len(nbr) in possibilities else False

# A MORE PYTHONISTIC CHECKSUM FUNCTION
def check_sum(nbr):
    sum = 0
    digits = ""

    for digit in nbr[-2::-2]:
        digits += str(int(digit)*2)

    for digit in nbr[-1::-2]:
        digits += digit

    for digit in digits:
        sum += int(digit)
    return sum % 10 == 0


# ANOTHER CHECKSUM FUNCTION
def check_sum2(nbr):
    N = int(nbr)
    sum = 0
    i = 0
    while N != 0:
        if i % 2 == 0:
            sum += N%10
        else :
            sum += ((N%10)*2)//10 + ((N%10)*2)%10
        N //= 10
        i += 1
    return sum % 10 == 0


def print_card(nbr):
    if len(nbr) == 15:
        print("AMEX")

    elif (len(nbr) in [13,16]) and nbr[0] == "4":
        print("VISA")

    else :
        print("MASTERCARD")

main()