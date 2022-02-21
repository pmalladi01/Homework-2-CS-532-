# CS-532 - Systems Programming: Homework 2

## Purpose:
implementing a search program in C program using system calls for files and 
directories.

## How to Compile:

//Compiling the source code homework2.c.

//gcc -Wall -0 <codefilename> -o <codefilename.c>

gcc -Wall -o homework2 -o homework2.c


## How to Execute:

//Displaying all files and file Size : ./search -S

./homework2   <filepath> -S

//./search -f <string>

./homework2 <filepath> -f <string>

// ./search -S -s -f

./homework2 <filepath> -S -s 1024 -t <string>
./homework2 <filepath> -t f
./homework2 <filepath> -t d



## Author
Pranay Kumar Reddy Malladi

## Credits:
I'd like to thank Dr. Unan and the TA's.

