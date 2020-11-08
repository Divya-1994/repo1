Problem Statement : assume that the new requirement is that (if not already taken care of) - your program
must output the time in microseconds. How to achieve the same ? What approach you
are able to devise as the solution to this question?

NOTE : While compiling attached source file please ensure that input.h and input.cpp files are in the same directory. (Given in input folder)

There are invocation of three functions "generateRandomNumbers", "checkIfDuplicateAndRoundOff" 
lrand48() function is used to generate random numbers of size 1 million.


Empirical Time Analysis : 

printDuplicates() : 1.2 seconds
checkIfDuplicateAndRoundOff() : 2.9 seconds


Asysmptotic Analysis :

printDuplicates() : O(n) = 1 seconds
checkIfDuplicateAndRoundOff() : O(pow(n,2)) (worst case)