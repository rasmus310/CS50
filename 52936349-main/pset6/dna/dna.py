import sys
import csv


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        exit("Error: python dna.py data.csv sequence.txt")

    # Read database file into a variable
    database = [] # Initialize database list to store each row of database
    with open(sys.argv[1], 'r') as databaseFile:
        reader = csv.DictReader(databaseFile)
        for row in reader:
            database.append(row) # Add each row of database to database list
            #print(row) # Print each row of database

    # Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as sequenceFile:
        dna_sequence = sequenceFile.read()
        #print(dna_sequence) # Print DNA sequence

    # Find longest match of each STR in DNA sequence
    subsequences = list(database[0].keys())[1:]
    #print(subsequences) # prints the subsequences

    result = {}
    for subsequence in subsequences:
        result[subsequence] = longest_match(dna_sequence, subsequence) # Store longest match of each STR in result dictionary
        #print(result[subsequence])

    # Check database for matching profiles
    for person in database:
        match = 0
        for subsequence in subsequences:
            if int(person[subsequence]) == result[subsequence]:
                match += 1
                #print(match)
                #print(len(subsequences))

        # If all subsequences match, print persons name and exit
        if match == len(subsequences):
            print(person["name"])
            return

    # If no match found, print this
    print("No match")
    return

# Function to find longest match of subsequence in sequence
def longest_match(sequence, subsequence):

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length #
            end = start + subsequence_length #

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main() # ensure main function is called when program is run