adm_8_9
=======

ADM Ch 8 Exercise 9

The *knapsack problem* is as follows: given a set of integers S = {s1, s2, ..., sn}, and a given target number *T*, find a subset of S that adds up exactly to *T*.  For example, within *S* = {1,2,5,9,10} there is a subset that adds up to T=22 but not T=23.  

Give a correct programming algorithm for knapsack that runs in *O(nT)* time.




Basically, this problem is the same as Exercise 7, the coin changing problem.  Instead of finding a numerical value, though, we're finding a boolean value, so we just store bools in the lookup table instead of values.  

