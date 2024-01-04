import sys
import csv

# Exit if there are not exactly 3 command-line arguments.
if len(sys.argv) != 3:
    print("Missing command-line arguments")
    exit(1)

# Read the CSV file (specified in the first command-line argument) into memory.
with open(sys.argv[1], 'r') as dna_csv:
    csv_reader = csv.reader(dna_csv)
    str_sequences_name = next(csv_reader)  # Extract the STR sequence names from the first row
    individual_data = list(csv_reader)  # Store the individuals' data in a list
    #print(individual_data)
# Read the DNA sequence file (specified in the second command-line argument) into memory.
with open(sys.argv[2], 'r') as sequence_file:
    sequence = sequence_file.read()

# Create a dictionary to store the counts of each STR in the DNA sequence.
STR = {} # Create a dictionary to store the counts of each STR in the DNA sequence.

# Loop through the STR sequences.
for str_sequence in str_sequences_name: # Loop through the STR sequences.
    longest_STR = 0 # Initialize the longest STR count
    i = 0 # Initialize the index
    while i < len(sequence): # While there are still characters to check in the sequence
        if sequence[i:i + len(str_sequence)] == str_sequence: # Check for consecutive matches
            STR_count = 1 # Initialize the STR count
            # While there are consecutive matches, increment the STR count and move the index
            while sequence[i:i + len(str_sequence)] == sequence[i + len(str_sequence):i + 2*len(str_sequence)]: # Check for consecutive matches
                STR_count += 1
                i += len(str_sequence)
            if STR_count > longest_STR: # Update the longest STR count
                longest_STR = STR_count
        i += 1 # Move to the next character
        #print(f"STR count: {i}, Longest STR: {longest_STR}")
    STR[str_sequence] = longest_STR # Store the longest STR count

# Use a flag to track whether a match has been found.
match_found = False

# Compare the STR counts to the individuals in the CSV file.
for person in individual_data: # Loop through the individuals in the CSV file.
    match = True # Initialize the match variable to True
    for i in range(1, len(person)): # Loop through the STR counts for each individual.
        if int(person[i]) != STR[str_sequences_name[i]]: # Compare the STR counts to the individuals in the CSV file.
            match = False # Set match to False if the counts don't match
            break # Break out of the loop if the counts don't match
    if match:  # Check if all STR counts match.
        print(person[0])  # Print the name of the matching individual.
        match_found = True
        break  # Exit the loop as a match has been found

# If no match is found, print a message indicating no match.
if not match_found:
    print("No match.")








