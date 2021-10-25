import cs50
import csv
import string
import sys

from sys import argv


def main():
    # Check for correct number of args
    if (len(argv) != 2):
        print("Usage: python import.py characters.csv")
        return 1

    # Csv file name
    csv_file = argv[1]

    # Create database
    open("students.db", "w").close()
    db = cs50.SQL("sqlite:///students.db")

    # Create tables
    db.execute("CREATE TABLE students (id INT, first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC, PRIMARY KEY(id))")

    # Open CSV file
    # https://datasets.imdbws.com/title.basics.tsv.gz
    with open(csv_file, "r") as students:

        # Create DictReader
        reader = csv.DictReader(students)

        i = 0

        # Iterate over TSV file
        for row in reader:

            # Trim prefix from tconst
            id = i
            i = i + 1

            name = row["name"].split()
            birthYear = int(row["birth"])

            # If middle name not missing
            if row["name"].count(" ") == 2:

                # Insert students
                db.execute("INSERT INTO students (id, first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?, ?)",
                           id, name[0], name[1], name[2], row["house"], birthYear)

            else:

                # Insert students
                db.execute("INSERT INTO students (id, first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?, ?)",
                           id, name[0], (None,), name[1], row["house"], birthYear)


main()