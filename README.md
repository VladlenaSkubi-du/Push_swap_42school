# Push_swap_42school
The project push_swap that sorts integers given as arguments with the help of two stacks and limited number of operations (pdf file attached).

Thanks to kmills (https://github.com/soldatsolt) for explaining the algorithm and helping in the beginning. 
The project was done only for the level in School 21.

# Usage
You need to compile the program and then give the program integers that you want to sort.

So, your steps -

Clone the repository:

    git clone https://github.com/VladlenaSkubi-du/Push_swap_42school.git [folder's name you want]

Get into it and compile the checker and push-swap-programs:

    cd [folder's name you want]
    make

## CHECKER PART
After you make:

    ./checker [numbers you want]

...and then input 2 or 3 letters for operations to be done. To finish the input, you send ctrl + D signal (EOF in Unix, ^D on Mac OS)

For example:

    ./checker 5 10 2 8 4 15

and then:

    pb
    pb
    pb
    sa
    pa
    rra
    pa
    rra
    pa
    rra
    rra
    ^D

Checker can give you answers: "OK" if such operations will sort the stack, "KO" if not and "Error" if the following is true:
 - there are not integers in the array input;
 - there are dublications in the array input;
 - "-5-", "--4", "+6+" and other mistakes with signs;

## PUSH SWAP PART
Or you make:

    ./push_swap 5 10 2 8 4 15
    
And get output:
    
    pb
    pb
    pb
    sa
    pa
    rra
    pa
    rra
    pa
    rra
    rra

Push swap answers you what operations have to be done to sort the stack. Can also give you "Error" in the same situations as checker.

Go and try. Good luck!

# Algorithm
The beginning of the algorithm and the main points are explained here: https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a.

The algorithm is based on rotations with the following steps:
1) push all the numbers from input to the a-stack
2) leave only three numbers in the a-stack and everything else push to the b-stack
3) chose the best b-stack-number to move to the a-stack-number and do that using only rotations
4) move according to the chosen parameters and than repeat untill b-stack is empty

# Grade
98/100:
- 10 numbers are sorted in less than 12 operations
- 100 numbers are sorted in less than 700 operations
- 500 numbers are sorted in less than 7000 operations (the best grade for "less than 5500 operations")
