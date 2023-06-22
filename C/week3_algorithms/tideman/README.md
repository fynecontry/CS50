### Tideman
A ranked-choice voting system which uses The [Tideman algorithm](https://en.wikipedia.org/wiki/Ranked_pairs) in determining the winner of an election by considering the preferences of voters and calculating a "strongest path" between candidates.

In the "tideman.c" program, the main objective is to simulate an election where candidates are ranked in order of preference by voters. The program takes input from the user, including the number of candidates, the number of voters, and the preferences of each voter. Based on the preferences, the program determines the winner using the ranked-choice voting method, also known as the Tideman method or the Schulze method.

The Tideman method takes into account the ranked preferences of voters and eliminates candidates in a series of rounds until a winner is determined. It avoids the problems associated with [plurality voting](https://github.com/fynecontry/CS50/blob/main/C/week3_algorithms/plurality.c), such as the spoiler effect or the possibility of a candidate winning despite having a majority of voters who prefer other candidates.

The "tideman.c" program demonstrates various programming concepts, including data structures (such as arrays and graphs), sorting algorithms, recursion, and graph theory, while addressing the problem of implementing a ranked-choice voting system.

```
./tideman Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Charlie
```