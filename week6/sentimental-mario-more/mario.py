# TODO

def main():
    while True:
        try :
            height = int(input("Enter a height between 1 and 8 inclusive: "))
            if height>0 and height<9 :
                break
        except ValueError :
            continue

    for i in range(height):
        print(" "*(height-i-1) + "#"*(i+1) + "  " + "#"*(i+1), end= "")
        print()

main()