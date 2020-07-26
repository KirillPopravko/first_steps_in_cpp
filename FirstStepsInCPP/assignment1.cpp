#include "std_lib_facilities.h"

// Make a number guessing game;
// a random number is generated between 1 and 10 (inclusive)
// the user must guess which number it is.
// After each guess, we tell the user whether their guess was too high or too low.
// When the user guesses correctly, we tell the user how many guesses it took,
// and give a congratulatory message

int main()
{
  int answer = randint(1,10);
  cout << "I have thought of a number between 1 and 10. Can you guess what it is?" << endl;
  while (true) {
    int guess;
    cout << "> ";
    cin >> guess;
    if (guess == answer) {
      break;
    } else {
      // TODO
      cout << "Too high?" << endl;
      cout << "Too low?" << endl;

      // TODO track number of guesses so we can print it just before 'congratulations'
    }
  }
  cout << "Congratulations!" << endl;
}
