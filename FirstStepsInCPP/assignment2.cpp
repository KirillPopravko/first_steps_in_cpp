#include <iostream>
using namespace std;

struct date {
  int year;
  int month;
  int day;
};

bool is_leap_year(int year){
  return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

int days_in_month(int month, int year){
  int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  if ( is_leap_year(year) ){
    days_in_month[1] = 29;
  }
  return days_in_month[month];
}

void decrement_month(date & input_date){
  input_date.month -= 1;
  if (input_date.month < 1) {
    input_date.month = 12;
    input_date.year -= 1;
  }
}

void increment_month(date & input_date){
  input_date.month += 1;
  if (input_date.month > 12) {
    input_date.month = 1;
    input_date.year += 1;
  }
}

int get_difference(date input_date, date root_sunday){
  int month_offset = 0;
  while( input_date.year > root_sunday.year || input_date.month > root_sunday.month ){
    decrement_month(input_date);
    month_offset += days_in_month(input_date.month, input_date.year);
  }
  while( input_date.year < root_sunday.year || input_date.month < root_sunday.month ){
    month_offset -= days_in_month(input_date.month, input_date.year);
    increment_month(input_date);
  }
  int day_offset = input_date.day - root_sunday.day;
  return month_offset + day_offset;
}

string get_day_of(date input_date) {
  // root sunday is Sunday the 26th of July 2020 - all dates are calculated from here
  date root_sunday = { 2020, 7, 26 };
  int days_different = get_difference(input_date, root_sunday);
  string days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
  if (days_different < 0) {
    days_different += (-(days_different / 7) + 1) * 7;
  }
  return days[days_different % 7];
}

int main()
{
  int year;
  cout << "Enter a year:" << endl;
  cin >> year;
  int month;
  cout << "Enter a month (1-12):" << endl;
  cin >> month;
  int day;
  cout << "Enter a day (1-31):" << endl;
  cin >> day;

  cout << day << "-" << month << "-" << year << " was/is a " << get_day_of(date { year, month, day }) << endl;
  return 0;
}
