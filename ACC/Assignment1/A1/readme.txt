Problem Statement : This assignment concerns creating a data set consisting of a vector of integer values. Create
this data set - consisting of at least a million integer values in a vector using the functions
and appropriate additional functions, as follows: Use the random number generator functions
srand48(), lrand48() and/or nrand48(), to populate a vector with a million entries to serve
as input data set to test your program. The vector must consist of only the positive integers.
Now, write another function to print the number of duplicates found in the input, if any and
yet another function to round off the duplicate to the nearest free integral value. Edit your
program to measure time required to remove the duplicates. Discuss what could be various
approaches to time the programs, including the utilities available in Linux. Use an approach
that gives you the finest resolution in time.

NOTE : While compiling attached source file please ensure that input.h and input.cpp files are in the same directory. (Given in input folder)

There are three functions "generateRandomNumbers", "printDuplicates", "checkIfDuplicateAndRoundOff" 
lrand48() function is used to generate random numbers of size 1 million.


Empirical Time Analysis : 

printDuplicates() : 1.2 seconds
checkIfDuplicateAndRoundOff() : 2.9 seconds


Asysmptotic Analysis :

printDuplicates() : O(n) = 1 seconds
checkIfDuplicateAndRoundOff() : O(pow(n,2)) (worst case)