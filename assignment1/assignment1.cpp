#include "std_lib_facilities.h"

// Make a number guessing game;
// a random number is generated between 1 and 10 (inclusive)
// the user must guess which number it is.
// After each guess, we tell the user whether their guess was too high or too low.
// When the user guesses correctly, we tell the user how many guesses it took,
// and give a congratulatory message

int get_guess() {
    int guess;
    cout << ">";
    cin >> guess;
    return guess;
}

enum class Continue_Or_Stop {
    Continue,
    Stop
};

Continue_Or_Stop check_guess(int guess, int answer, int numoftries) {
    if (guess == answer) {
        cout << "Congratulations!" << numoftries << "times!" << endl;
        return Continue_Or_Stop::Stop;
    }
    else if (guess < answer) {
        cout << "Too low." << endl;
    }
    else {
        cout << "Too high." << endl;
    }
    return Continue_Or_Stop::Continue;
}

int main()
{
  int answer = randint(1,100);
  cout << "I have thought of a number between 1 and 10. Can you guess what it is?" << endl;
  int numoftries = 0;
  int guess;
  do {
    numoftries = numoftries + 1;
    if (numoftries == 7) {
        cout << "Its your last try" << endl;
    }
    if (numoftries > 7) {
        cout << "You lost." << endl;
        break;
    }
    guess = get_guess();
  } while (check_guess(guess, answer, numoftries) == Continue_Or_Stop::Continue);
  
}
