## Radix Sort Algorithm with Time Analysis Summary

This project implements a **Radix Sort** algorithm in C++ and includes time analysis for sorting arrays of various sizes using different bases. The program sorts arrays of size 10, 100, 1000, and 10,000, filled with random numbers, and measures the time it takes to perform the sorting. The average time for ten passes is calculated for each array size.

### Key Functions in the Code:
1. **radixSort(int arr[], int size, int base)**:
   - Implements the radix sort algorithm, where numbers are sorted based on each digit from least significant to most significant, using a base defined by the user. It repeatedly calls the `countSort()` function for each digit.

2. **countSort(int arr[], int n, int key, int base)**:
   - A helper function that performs **counting sort** on the array based on the current digit. It organizes elements according to their place values using the provided base.

3. **max(int a[], int n)**:
   - Returns the maximum element from the array, used to determine the number of digits required for the sorting process.

### Time Analysis:
For each array size, the program runs the radix sort algorithm 10 times and records the time taken for each pass using the `chrono` library to measure the duration in nanoseconds. The average time of the 10 passes is then calculated for each array size, providing a performance overview of the radix sort algorithm under different conditions.

The results include:
- **Unsorted and Sorted Arrays**: The program prints the unsorted and sorted arrays for the first pass of each array size.
- **Execution Time for Each Pass**: The program outputs the time taken for each of the 10 passes for each array size.
- **Average Time**: After completing 10 passes for a given array size, the program calculates and displays the average time taken.

This project provides a clear demonstration of how radix sort performs on various array sizes, and the time analysis helps illustrate the efficiency of the algorithm.

### How To Run The Program:
Save files in linux machine and then run the following

g++ -o radix radixSort.c
./radix <base>

Example to run with base 10:
g++ -o radix radixSort.c
./radix 10
