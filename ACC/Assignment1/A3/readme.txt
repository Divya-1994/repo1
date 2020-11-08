Problem Statement : time the function you have written using the structure timeval as discussed in class/-
explained in the lab.

t y p e d e f s t r u c t tim e v al {
l o n g t v s e c ;
l o n g t v u s e c ;
} tim e v al ;

Use the program microresolutiontimer.c uploaded on the LMS. Compare the time obtained
here with the approaches to time that you have used in the Problem #1 and 2. Give an
analysis/critique of your comparison.


NOTE : While compiling attached source file please ensure that input.h and input.cpp files are in the same directory. (Given in input folder)

There are invocation of three functions "checkIfDuplicateAndRoundOff" 
lrand48() function is used to generate random numbers of size 1 million.


Empirical Time Analysis : 

checkIfDuplicateAndRoundOff() : 3 seconds


Asymptotic Analysis :

checkIfDuplicateAndRoundOff() : O(pow(n,2)) (worst case)