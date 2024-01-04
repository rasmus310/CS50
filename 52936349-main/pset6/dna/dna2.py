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

# Read the DNA sequence file (specified in the second command-line argument) into memory.
with open(sys.argv[2], 'r') as sequence_file:
    sequence = sequence_file.read()

# Create a dictionary to store the counts of each STR in the DNA sequence.
STR = {}

# Loop through the STR sequences.
for str_sequence in str_sequences_name:
    longest_STR = 0
    STR_count = 0
    for i in range(len(sequence) - len(str_sequence)):
        if sequence[i:i + len(str_sequence)] == str_sequence:
            STR_count += 1
            if STR_count > longest_STR:
                longest_STR = STR_count
        else:
            STR_count = 0
    STR[str_sequence] = longest_STR

# Compare the STR counts to the individuals in the CSV file.
for person in individual_data:
    match = True
    for i in range(1, len(person)):
        if int(person[i]) != STR[str_sequences_name[i]]:
            match = False
            break
    if match:
        print(person[0])
        exit(0)
