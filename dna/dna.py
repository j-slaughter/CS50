import csv
from sys import argv


def main():

    # Check for command-line usage
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return

    # TODO: Read database file into a variable
    database = list()
    with open(argv[1], newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            database.append(row)

    # TODO: Read DNA sequence file into a variable
    f = open(argv[2], 'r')
    sequence = f.read()

    # Count number of STRs in the database (exclude 'name' key)
    num_str = -1
    for key in database[0]:
        num_str += 1

    # TODO: Find longest match of each STR in DNA sequence
    # Loop through each person in database list
    for person in range(len(database)):
        match = 0
        # Loop through each STR key
        for subsequence in database[person]:
            # Skip the name key
            if subsequence != 'name':
                # Count number of STR repeats
                count = longest_match(sequence, subsequence)
                # Compare count to database
                if count == int(database[person][subsequence]):
                    match += 1
        # TODO: Check for matching profiles
        if match == num_str:
            # Print name of matching individual
            print(database[person]['name'])
            return
    # If no matching individual
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

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
            start = i + count * subsequence_length
            end = start + subsequence_length

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


main()
