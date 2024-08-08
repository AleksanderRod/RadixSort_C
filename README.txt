Name: Aleksander Rodriguez

Description of Code: The code in the radixSort.c takes an argument at execution which will be the base for the radix sort and passed to the count sort to perform the sort of the array. For every execution, the program will create an array with a size 10, 100, 1000, and 10000. It will store each array with random values and we will then perform a radix sort to sort the number in the array. For each size, we will do ten passes to see the time for each radix sort and we will then calculate the average time at the end of all the passes for each array size. There are comments on explaining the code for radix and counting sort within the code. The chrono library is used in the code and is used to determine the time each radix sort takes to complete its sort.


How To Run The Program:
Save files in linux machine and then run the following

g++ -o radix radixSort.c
./radix <base>

Example to run with base 10:
g++ -o radix radixSort.c
./radix 10
