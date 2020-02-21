#include <iostream>
#include <fstream>

using namespace std;

ifstream inputFile("numere.in");
ofstream outfile("numere.out");

int main() {

    if (inputFile) {
        int nr = 0;
        int numbers[6];
        int cifre[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        inputFile >> nr;

        for (int i = 0; i < 6; i++) {
            inputFile >> numbers[i];
        }

    } else {
        cout << "Error opening file!!!" << endl;
        return -1;
    }
    
    return 0;
}
