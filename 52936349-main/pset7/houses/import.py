# TODO
from cs50 import SQL
import sys

db = SQL("sqlite:///students.db")

if len((sys.argv) != 2)
    print('Ikke validt')
    sys.exit(1)

#this opens the CSV file
csv_characters = sys.argv[1]

#Connect to the database

conn = sqlite3.connect('students.db')

db = conn.cursor()

# read the CSV file

with open('characters.csv', 'r') as file:
    #create a CSV reader
    reader = csv.reader(file)
    # Iterate over the rows in the CSV file.
    for row in reader:
        print(row['name'])



