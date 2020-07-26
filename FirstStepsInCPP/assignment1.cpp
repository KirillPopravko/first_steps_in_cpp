#include "std_lib_facilities.h"

// Make a number guessing game;
// a random number is generated between 1 and 10 (inclusive)
// the user must guess which number it is.
// After each guess, we tell the user whether their guess was too high or too low.
// When the user guesses correctly, we tell the user how many guesses it took,
// and give a congratulatory message


int get_guess(){
    int guess;
    cout << "> ";
    cin >> guess;
    return guess;
  }

bool check_guess(int guess, int antwoord, int guess_nr){
  if (guess == antwoord) {
    cout << "Gefelicifalpstaart" << endl;
    return true;
  }
  if (guess < antwoord){
    cout << "Te laag." << endl;
  } else {
    cout << "Te hoog." << endl;
  }
  if ( guess_nr == 7 ){
    cout << "last try" << endl;
  }
  return guess_nr == 8;
}

int main()
{
  int answer = randint(1,100);
  cout << "I have thought of a number between 1 and 100. Can you guess what it is?" << endl;
  int g = 0;
  while (true) {
    g++;
    int guess = get_guess();
    if (guess == answer) {
      break;
    } else {
      bool should_stop = check_guess(guess, answer, g);
      if (should_stop) {
        break;
      }
    }
  }
}
