from cs50 import get_float
cents = -1

# This is where we get the interlocutor change
while cents < 0:
    # Do while we get a number between 1 and 8
    cents = get_float("Change owed: ")

quarter = 25
dime = 10
nickel = 5
penny = 1

n = int(cents * 100)

i = n % quarter
j = n // quarter
# Get the number of quarters
nmb = j

if i == 0:
    print(nmb)
else:
    # Get the number of dimes
    j = i // dime
    i = i % dime
    # Get the number of dimes + quarters
    nmb = nmb + j

    if i == 0:
        print(nmb)
    else:
        # Get the number of nickels
        j = i // nickel
        i = i % nickel
        # Get the number of nickels + dimes + quarters
        nmb = nmb + j

        if i == 0:
            print(nmb)
        else:
            # Get the number of pennies + nickels + dimes + quarters
            nmb = nmb + i
            print(nmb)