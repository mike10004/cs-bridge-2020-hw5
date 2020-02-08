#pragma clang diagnostic push                       // stage:remove                       
#pragma ide diagnostic ignored "hicpp-use-nullptr"  // stage:remove
#pragma ide diagnostic ignored "cert-msc30-c"       // stage:remove
#pragma ide diagnostic ignored "cert-msc32-c"       // stage:remove
// mac937@nyu.edu
// HW5 Question 2

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>  // stage:remove

using namespace std;

const int MAX_GUESS_COUNT = 5;
const int RANDOM_MIN = 1;
const int RANDOM_MAX = 100;
const char* ENV_NUM = "Q2_RANDOM_NUMBER";   // stage:remove

int main() {
    int userGuess;
    int userGuessLowerBound = RANDOM_MIN, userGuessUpperBound = RANDOM_MAX;
    int numGuesses = 0;
    int randomNumber;
    
    srand(time(0));
    randomNumber = (rand() % (RANDOM_MAX - RANDOM_MIN + 1)) + 1;
                                                                                                        // stage:remove
    const char* envNumStr = getenv(ENV_NUM);                                                           // stage:remove
    if (envNumStr != nullptr) {                                                                         // stage:remove
        long envNum = strtol(envNumStr, nullptr, 10);                                       // stage:remove
        if (envNum > 0 && envNum <= INT_MAX) {                                                          // stage:remove
            randomNumber = (int) envNum;                                                                // stage:remove
        } else {                                                                                        // stage:remove
            cerr << ENV_NUM << "=" << envNumStr << " but that is not a valid int for this program\n";   // stage:remove
        }                                                                                               // stage:remove
    }                                                                                                   // stage:remove
    
    cout << "I thought of a number between " << RANDOM_MIN << " and " << RANDOM_MAX << "! "; 
    cout << "Try to guess it.\n";
    
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

#pragma clang diagnostic pop   // stage:remove