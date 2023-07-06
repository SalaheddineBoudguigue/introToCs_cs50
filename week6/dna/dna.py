import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3: # sys.argv is a list of command arguments
        sys.exit("python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    file0 = open(sys.argv[1], 'r')
    reader_individuals = csv.DictReader(file0)
    STRS = reader_individuals.fieldnames[1:]

    # TODO: Read DNA sequence file into a variable
    file1 = open(sys.argv[2], 'r')
    DNA = file1.read()

    # TODO: Find longest match of each STR in DNA sequence
    # We define a dict, where keys are STRS and values are there counts in DNA
    strsCount = {}
    for STR in STRS :
        strsCount[STR] = str(longest_match(DNA, STR)) # Because data nbrs in the file are strings

    # TODO: Check database for matching profiles
    # We make a dictionnary, with keys as STRS, and values as their count for each individual, since values are mutable
    d = {}
    for individual in reader_individuals:
        for STR in STRS:
            d[STR] = individual[STR]

        # If the two dictionnary corresponds, then we print the name and exit the loops
        if d == strsCount:
            file0.close()
            file1.close()
            sys.exit(individual["name"])

    file0.close()
    file1.close()
    sys.exit("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length - subsequence_length + 1):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length                # WHAT A PROBLEM SOLVING ALGORITHM

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
