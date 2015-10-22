BLAST project

Blast app:
The application is using dichotomy method to calculate shock wave propagation.
The algorithm is the following:
1. Calculate the maximum squared range of wave propagation by:
1.1 Computing the maximum squared length for all bombs between bomb position and 
space cube vertices.
1.2 Taking minimum of these lengths.
2. Dichotomy. While-loop for extrapolating squared range = (rangeMin + rangeMax)/2 
to sought-for value. Counts affected points of space by calling shockWave method.
Exits when the number of non affected points less than MAX*MAX 
3. Method shockWave(int i, unsigned long int r) simulates wave propagation
for i-th bomb at distance r. Affected points of space are marked "1" in 
world[k][l][m] array. Method returns the number of affected points.
4. For-loop on all non affected points of last dichotomy range (less than MAX*MAX).
Finding the maximum squared length.

By default reads from "in" file and write output to "out" file. 
Options can be altered by passing command line parameters (see -h help option).

Auxiliary scripts:
random.sh - generate random input data for blast program.

Unit tests:
Reside in test directory. Testing performed by using Google Test framework.

Tested on:
Linux 3.8.3-203.fc18.x86_64
gcc (GCC) 4.7.2
Google Test (gtest-1.6.0-1)
