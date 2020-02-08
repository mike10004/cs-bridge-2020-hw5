// <author>
// Question 2

#include <iostream>

using namespace std;

const int MAX_GUESS_COUNT = 5;
const int RANDOM_MIN = 1;
const int RANDOM_MAX = 100;

int main() {
    int userGuess, userGuessLowerBound = RANDOM_MIN, userGuessUpperBound = RANDOM_MAX, numGuesses = 0;
    int randomNumber = 25;
    cerr << "hello" << endl;
    cout << "I thought of a number between 1 and 100! Try to guess it.\n";
    
    do {
        cout << "Range: [" << userGuessLowerBound << ", " << userGuessUpperBound << "], ";
        cout << "Number of guesses left: " << (MAX_GUESS_COUNT - numGuesses) << endl;
        cout << "Your guess: ";
        cin >> userGuess;
        numGuesses++;
        if (userGuess != randomNumber) {
            if (numGuesses >= MAX_GUESS_COUNT) {
                cout << "Out of guesses! My number is " << randomNumber << endl;
            } else {
                cout << "Wrong! My number is ";
                if (userGuess < randomNumber) {
                    if (userGuess > userGuessLowerBound) {
                        userGuessLowerBound = userGuess + 1;
                    }
                    cout << "bigger.\n\n";
                } else {
                    if (userGuess < userGuessUpperBound) {
                        userGuessUpperBound = userGuess - 1;
                    }
                    cout << "smaller.\n\n";
                }
            }
        } else {
            cout << "Congrats! You guessed my number in " << numGuesses << " guesses.\n";
        }
    } while (userGuess != randomNumber && numGuesses < MAX_GUESS_COUNT);

    return 0;
}
