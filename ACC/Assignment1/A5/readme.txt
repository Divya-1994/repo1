Problem Statement : Do a bit of research and find out on what factors does the actual time taken by a program
depends on. Use these factors as an argument to justify why it is not feasible to do empirical
analysis when the goal is to compare two algorithms.

 

We cannot do empirical analysis for any algorithm because it would be subjective decision. As there is no fix standard resources on which we assume that particular algorithm give optimal time.

While counting number of swaps I observed that it is based on how we are comparing and finalise the maximum or minimum. In every sorting technique except selection sort we are swapping for every comparison but in Selection sort we traverse to whole vector for each element and then do the swapping if needed.

Thats cause the swap time of selection sort O(n) 