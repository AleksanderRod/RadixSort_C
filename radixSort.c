/*
Name: Aleksander Rodriguez
Section: 001 
Date: 11/10/2023
Description: The code in the radixSort.c takes an argument at execution which will be the base for the radix sort
and passed to the count sort to perform the sort of the array. For every execution, the program will create an array
with a size 10, 100, 1000, and 10000. It will store each array with random values and we will then perform a radix
sort to sort the number in the array. For each size, we will do ten passes to see the time for each radix sort and 
we will then calculate the average time at the end of all the passes for each array size. There are comments on explaining 
the code for radix and counting sort within the code. The chrono library is used in the code and is used to determine the time each radix sort takes to complete its sort.
*/
#include <iostream>
#include <cstdlib> 
#include <chrono>

using namespace std::chrono;
using namespace std;

int max(int [], int);
void radixSort(int [], int, int);
void countSort(int [], int , int, int);

// find the max of the array of numbers
int max(int a[], int n)
{
    int max= a[0];
    for (int x = 1; x < n; x++)
        if (a[x] > max)
        {
            max = a[x];
        }
    return max;
}
 
// The main function that sorts arr[]
void radixSort(int arr[], int size, int base)
{
    // find max to then know max digits out of all nums
    int digits = max(arr, size);
 

    // To accomplish the radix sort we will need to 
    // pass the base along to the count and the key 
    // be mutiplied by the base each iteration
    for (int key = 1; digits / key > 0; key *= base)
        countSort(arr, size, key, base);
}

// perform counting sort
void countSort(int arr[], int n, int key, int base)
{
 
    int newArr[n];
    int i, count[base] = { 0 };
 
    // count occurrences of each digit 
    for (i = 0; i < n; i++)
        count[(arr[i] / key) % base]++;
 
    // shift the number each subscript has to the right 
    for (i = 1; i < base; i++)
        count[i] += count[i - 1];
 
    // Build the new array according to the count array
    for (i = n - 1; i >= 0; i--) {
        newArr[count[(arr[i] / key) % base] - 1] = arr[i];
        count[(arr[i] / key) % base]--;
    }
 
    // Copy the new array to arr[],
    // so that arr[] now contains sorted
    // numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = newArr[i];
}
 
int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <num of base>\n", argv[0]);
        exit(1);
    }
    int size= 10;
    int base = atoi(argv[1]);
    int count = 0, pass = 1;
    time_t start, stop;

    // helps get the average of passes for each sizes
    double elapSum;
    
    

   while (size <= 10000)
    {
        cout << "Radix sort: base = " << base << " size = " << size << endl;
        
        pass =1;

        // for every new size restart the elapsed sum 
        elapSum = 0;

        for (int i = 0; i < 10; i++)
        {
            int *arr = new int[size]();
            
            //create the array with random numbers
            for(int x= 0 ; x < size ; x++)
            {
                arr[x]= (rand() % 9999);
            }

            // this if used for printing our first pass.
            // Once count is not 0 we will default to the else statment
            if(count == 0 )
            {
                //print the unsorted array
                cout << "Unsorted: ";
                for (int i = 0; i < size; i++)
                cout << arr[i] << " ";

                cout << endl;

                // start time
                auto beg = high_resolution_clock::now();

                radixSort(arr, size, base);

                // end time 
                auto end = high_resolution_clock::now();
                auto dur = duration_cast<nanoseconds>(end - beg);
                elapSum += dur.count();

                
                // print the sorted array
                cout << "Sorted: ";
                for (int i = 0; i < size; i++)
                cout << arr[i] << " ";

                cout <<endl;

                //Print the time of the pass
                cout << "pass " << pass << ": " << dur.count() << " nanoseconds" << endl ;

                count++;
                
                pass++;



            }
            else 
            {
                // dynamically allocated array 
                int *arr = new int[size]();

                // create array with random numbers
                for(int x= 0 ; x < size ; x++)
                {
                    arr[x]= (rand() % 9999);
                }

                // start time
                auto beg = high_resolution_clock::now();

                radixSort(arr, size, base);

                // end time 
                auto end = high_resolution_clock::now();
                auto dur = duration_cast<nanoseconds>(end - beg);
                elapSum += dur.count();

                // print the time of the pass
                cout << "pass " << pass << ": " << dur.count() << " nanoseconds" << endl ;
                pass++;


            }


        }
        // calculate the avg time for all passes
        double avg = elapSum/10;
        cout << "Average: " << avg  << " nanoseconds"<< endl;
        cout << endl;
        

        size *= 10;
    }

    
    
    return 0;
}

