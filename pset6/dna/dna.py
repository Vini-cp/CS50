import csv
import sys

from cs50 import get_string
from csv import DictReader
from sys import argv


def main():

    # Check for correct number of args
    if (len(argv) != 3):
        print("Usage: python dna.py data.csv sequence.txt")
        return 1

    # Check for correct number of args
    database = argv[1]
    dna = argv[2]

    dna_file = open(dna, "r")

    # Check if file opens
    if (dna_file is None):
        print(f"Could not open {dna}")
        return 1

    dna_text = ''

    # Copy the DNA text
    for line in dna_file:
        dna_text = line.rstrip("\n")


# open file in read mode
    with open(database, 'r') as read_obj:

        # pass the file object to DictReader() to get the DictReader object
        csv_dict_reader = DictReader(read_obj)

        # Check if file opens
        if csv_dict_reader is None:
            print(f"Could not open {database}")
            return 1

        # Number of DNA to check
        STR_nmb = len(csv_dict_reader.fieldnames)

        dnaSTR_count = [0] * (STR_nmb - 1)

        # Checking the max sequence of a DNA
        for i in range(1, STR_nmb):
            dna_size = len(csv_dict_reader.fieldnames[i])
            max_rep = 0
            j = 0
            while j < len(dna_text) - dna_size:
                if dna_text[j: dna_size + j] == csv_dict_reader.fieldnames[i]:
                    dnaSTR_count[i - 1] = dnaSTR_count[i - 1] + 1
                    j = j + dna_size
                else:
                    j = j + 1
                    if max_rep < dnaSTR_count[i - 1]:
                        max_rep = dnaSTR_count[i - 1]
                    dnaSTR_count[i - 1] = 0

                if j == len(dna_text) - dna_size:
                    if max_rep > dnaSTR_count[i - 1]:
                        dnaSTR_count[i - 1] = max_rep
        
        # Checking if the sequence is well-suited with someone on the list
        for row in csv_dict_reader:
            for i in range(1, STR_nmb):
                if int(row[csv_dict_reader.fieldnames[i]]) == dnaSTR_count[i - 1]:
                    if i == STR_nmb - 1:
                        print(row["name"])
                        return 0
                else:
                    break

    dna_file.close()

    read_obj.close()

    print("No match")

    return 1


main()