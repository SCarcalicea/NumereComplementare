#include <iostream>
#include <fstream>
#include <vector>
#include "NumereComplementare.h"

using namespace std;

ifstream inputFile("numere.in");
ofstream outfile("numere.out");

int main() {

    if (inputFile) {
        int nr = 0;
        vector<int> numbers;
        vector<int> cifre {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> complementNrs;

        // Read numbers into vectors
        inputFile >> nr;
        int temp;
        while (inputFile >> temp) {
            numbers.push_back(temp);
        }
        
        // Find complementary numbers: 3 steps
        // 1. remove elements from cifre that are contained in our number
        int origNr = nr;
        int cifra = origNr % 10;
        while (cifra != 0) {
            for (auto j = cifre.begin(); j != cifre.end(); ++j) {
                if (cifra == *j) {
                    cifre.erase(j);
                    break;
                }
            }
            origNr = origNr / 10;
            cifra = origNr % 10;
        }

        // 2. find out complementary numbers
        for (auto i = numbers.begin(); i != numbers.end(); ++i) {
            int complement = *i;
            int digit = complement % 10;

            if (complement > nr) {
                do {

                    // Find out if digit from complement is an allowed digit
                    bool digitOk = false;
                    for (auto j = cifre.begin(); j != cifre.end(); ++j) {
                        if (digit == *j) { // Digit not allowed
                            digitOk = true;
                            break;
                        }
                    }

                    // Do not evaluate further
                    if (!digitOk) { 
                        digit = -1;
                        break;
                    }

                    complement = complement / 10;
                    digit = complement % 10;
                } while (complement > 0);

                // Complement found, save it into vector
                if (digit != -1) {
                    complementNrs.push_back(*i);
                }
            }
        }

        // 3. find out if the number of even digits is equal with the number of odd digits for both number and complementary number (remove complementary number if otherwhise)
        //calculateOddAndEvenDigits(complementNrs, nr);

        // 4. find the larger number of complement and print it out
        int max = 0;
        for (auto it = complementNrs.begin(); it != complementNrs.end(); ++it) {
            if (max < *it) {
                max = *it;
            }
        }

        cout << "Largest number is: " << max << endl;

    } else {
        cout << "Error opening file!!!" << endl;
        return -1;
    }
    
    return 0;
}

// find out if the number of even digits is equal with the number of odd digits for both numberand complementary number
// (remove complementary number if otherwhise)
void calculateOddAndEvenDigits(std::vector<int>& complementNrs, int nr)
{
    int odd = 0;
    int even = 0;
    for (auto it = complementNrs.begin(); it != complementNrs.end(); ++it) {

        // Evaluate complement
        int complement = *it;
        int digit = complement % 10;
        do {
            if (digit % 2 == 0) {
                even++;
            }
            else {
                odd++;
            }
            complement = complement / 10;
            digit = complement % 10;
        } while (complement > 0);


        // Evaluate number
        int number = nr;
        digit = number % 10;
        do {
            if (digit % 2 == 0) {
                even--;
            }
            else {
                odd--;
            }
            number = number / 10;
            digit = number % 10;
        } while (number > 0);

        // The number of even or odd digits is not the same in both numbers
        if (odd != 0 || even != 0) {
            complementNrs.erase(it);
            it--;
        }

    }
}
