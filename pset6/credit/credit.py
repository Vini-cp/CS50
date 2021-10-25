from cs50 import get_int


def main():

    credit = 0

    # This is where we get the interlocutor card number
    while credit < 1:
        # Do while we get a positive number
        credit = get_int("Number: ")

    nmb_lenght = get_int_len(credit)

    even_sum = 0
    odd_sum = 0
    # int aux, nmb_lenght, card, card_1, card_2;

    # Starting at the end of the number
    for i in range(nmb_lenght):
        if i == nmb_lenght - 1:
            card_1 = credit

        if i == nmb_lenght - 2:
            card_2 = credit % 10

        if even_odd(i):
            # Add the sum to the sum of the digits that weren’t multiplied by 2
            aux = credit % 10
            credit = credit - aux
            credit = credit // 10
            even_sum = even_sum + aux
        else:
            # Multiply every other digit by 2
            aux = credit % 10
            credit = credit - aux
            credit = credit // 10
            aux = aux * 2

            if aux > 9:
                # Sum each digit
                odd_sum = odd_sum + aux % 10
                aux = (aux - (aux % 10)) // 10
                odd_sum = odd_sum + aux
            else:
                odd_sum = odd_sum + aux

    card = card_1 * 10 + card_2

    if (even_sum + odd_sum) % 10 == 0:
        # If the total’s last digit is 0 the number is valid

        if (card == 34 or card == 37) and nmb_lenght == 15:
            # Starting with 3
            print("AMEX\n")
        elif card_1 == 4 and (nmb_lenght > 12 and nmb_lenght < 17):
            # Starting with 4
            print("VISA\n")
        elif (card == 51 or card == 52 or card == 53 or card == 54 or card == 55) and nmb_lenght == 16:
            # Starting with 5
            print("MASTERCARD\n")
        else:
            print("INVALID\n")

    else:
        print("INVALID\n")


# Check if is Even or Odd
def even_odd(n):
    if (n % 2 == 0):
        # Even
        return 1
    else:
        # Odd
        return 0


def get_int_len(value):
    l = 1

    while value > 9:
        l += 1
        value //= 10

    return l


main()