// Assignment 1: Alternating disks problem, left-to-right algorithm
// Russell Richardson and Jose Urrutia
// Given 2n alternating disks (dark, light) the program reads the number of single color disks
// (light or dark), arranges the disks in the correct order and outputs the number of swaps
// INPUT: a positive integer n and a list of 2n disks of alternating colors dark-light, starting with dark
// OUTPUT: a list of 2n disks, the first n disks are light, the next n disks are dark,
// and an integer m representing the number of moves to move the dark ones after the light ones

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// YOU NEED TO IMPLEMENT THIS FUNCTION
// function to print the list of disks, given the number of single color disks and the actual list
// n represents the number of single color disks
// disks represents the list of disks (index 0 being the first disk) where
// 0 = a light color disks
// 1 = a dark color disks
void print_disks(int n, char *disks) {
     cout << "   ";
     for (int i = 0; i < 2 * n; i++) {
          if (disks[i] == '0')
               cout << "l ";
          else if (disks[i] == '1')
               cout << "d ";
     }
}

int main() {
     int n, m, k, i;
     char *disks;
     
     // display the header
     cout << endl << "CPSC 335-03 - Programming Assignment #1" << endl;
     cout << "Russell Richardson and Jose Urrutia" << endl;
     cout << "The alternating disks problem: left-to-right algorithm" << endl;
     cout << "Enter the number of single color disks (light or dark)" << endl;
     
     // read the number of disks
     cin >> n;

     // allocate space for the disks
     disks = new char[2 * n];

     // set the initial configuration of the list of disks
     for (i = 0; i < n; i++) {
          disks[2 * i] = '1';
          disks[2 * i + 1] = '0';
     }

     // print the initial configuration of the list of disks
     cout << "\nInitial configuration" << endl;
     cout << "   List of disks" << endl;
     print_disks(n, disks);

     // PART OF CODE MISSING
     // loop to push light one before the dark ones
     m = 0;
     for (k = 0; k < n; k++) {

     // YOU NEED TO COMPLETE THIS PART OF CODE FOR GOING LEFT TO RIGHT
          for (i = 0; i < 2 * n - 1; i++) {
               if (disks[i] > disks[i + 1]) {
                    int temp = disks[i];
                    disks[i] = disks[i + 1];
                    disks[i + 1] = temp;
                    m = m + 1;
               }
          }
     }

     // after shuffling them
     cout << "\n\nAfter moving darker ones to the right" << endl;
     cout << "   List of disks" << endl;
     print_disks(n, disks);

     // print the total number of moves
     cout << "\n\nNumber of swaps is " << m << endl << endl;

     // de-allocate the dynamic memory space
     delete [] disks;
     return EXIT_SUCCESS;
}
