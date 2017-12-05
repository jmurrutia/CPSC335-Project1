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
     cout << "Jose Urrutia" << endl;
     cout << "The alternating disks problem: lawnmower algorithm" << endl;
     cout << "Enter the number of single color disks (light or dark)" << endl;

     // read the number of disks
     cin >> n;

     // allocate space for the disks
     disks = new char[2 * n];

     // set the initial configuration for the disks to alternate
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
     for (k = 0; k < (n / 2) + 1; k++) {

          // DEVELOP ONE FOR LOOP FOR GOING LEFT TO RIGHT
          for (i = 0; i < 2 * n - 1; i++) {
               if (disks[i] > disks[i + 1]) {
                    int temp = disks[i];
                    disks[i] = disks[i + 1];
                    disks[i + 1] = temp;
                    m = m + 1;
               }
          }
          // DEVELOP ANOTHER FOR LOOP FOR GOING RIGHT TO LEFT
          for (i = 2 * n - 1; i > 1; i--) {
               if (disks[i] < disks[i - 1]) {
                    int temp = disks[i];
                    disks[i] = disks[i - 1];
                    disks[i - 1] = temp;
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
     delete[] disks;
     return EXIT_SUCCESS;
}
