import sys

class Candidates():
    '''A class representing a candidate'''

    def __init__(self, candidate):
        self.candidate = candidate
        self.votes = 0

    def increment_vote(self):
        self.votes += 1

