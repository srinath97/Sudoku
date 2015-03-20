PROBLEM: Sudoku is a game where we should solve a 9*9 matrix with values such that no two values can be repeated in that row or column or in sub-matrix of 3*3.

ALGORITHM: 
1. Accept the matrix with the unknown values as zero. 
2. Iterate through each value in the matrix. If that value is zero then push that row and column in a stack and start from 1 and check if the values in the corresponding row , column and the 
   sub-matrix are not that value. If so then change that value to the next value and repeat. 
3. If the value reaches 10 then backtracking is done. 
4. Pop values from the stack and increase that value and repeat the steps.
5. Repeat this until all the unknown values are found.
6. If the stack becomes empty then there is no solution for that sudoku.

This program works in DEV-C++ version 5.8.3.

Screenshots are attached in this folder