from cs50 import get_string


# User's text input
text = get_string("Text: ")

i = 0
j = 1
k = 0
l = 0

for i in range(len(text)):
    if (ord(text[i]) > 64 and ord(text[i]) < 91) or (ord(text[i]) > 96 and ord(text[i]) < 123):
        # Count the letters
        k = k + 1

    # Count the words
    if text[i] == ' ':
        j = j + 1

    if text[i] in ['!', '.', '?']:
        # Count the sentences
        l = l + 1

# Coleman-Liau index
index = 0.0588 * k / j * 100 - 0.296 * l / j * 100 - 15.8

if (index < 1):
    # Grades smaller than 1
    print("Before Grade 1")
elif (index > 15):
    # Grades bigger than 16
    print("Grade 16+")
else:
    # The rest
    print(f"Grade {int(round(index, 0))}")