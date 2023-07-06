# TODO
from cs50 import get_float

# We use main() to better control our code

def main():
    while True: # We keep asking the user for the right answer until it's done
        try :
            change = get_float("Change owed: ")
            if change > 0 :
                break
        except ValueError :
            continue
    change *= 100
    coins = 0
    for coin in [25, 10, 5, 1]:
        q = change // coin
        coins += q
        change = change - q*coin
    print(int(coins))

main()
