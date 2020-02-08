// mac937@nyu.edu
// HW5 Question 1

#include <iostream>

using namespace std;

const char TAB = '\t';

int main() {
    int inputNumber;
    cout << "Please enter a positive integer:\n";
    cin >> inputNumber;
    for (int row = 1; row <= inputNumber; row++) {
        for (int col = 1; col <= inputNumber; col++) {
            if (col > 1) {
                cout << TAB;
            }
            cout << row * col;
        }
        cout << endl;
    }
    return 0;
}
