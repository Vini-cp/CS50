import cs50
import csv
import string
import sys

from sys import argv


def main():
    # Check for correct number of args
    if (len(argv) != 2):
        print("Usage: python roster.py family")
        return 1

    # Csv file name
    family_name = argv[1]

    # Create database
    open("students.db", "r").close()
    db = cs50.SQL("sqlite:///students.db")

    # Select names
    rows = db.execute("SELECT first, middle, last, house, birth FROM students WHERE house = ? ORDER BY last asc, first asc", family_name)

    # case when middle is not null then middle end as middle
    for row in rows:
        print(row["first"], end=' ')

        if row["middle"] is not None:
            print(row["middle"], end=' ')

        print(row["last"], end=', born ')

        print(row["birth"])


main()
