#include <iostream>

using namespace std;

int year, month;

int get_day_by_year(int year) {
    return ((!(year % 4) && (year % 100)) || !(year % 400)) ? 366 : 365;
}

int get_day_by_month(int month) {
    if (month == 2)
	return ((!(year % 4) && (year % 100)) || !(year % 400)) ? 29 : 28;
    else
	return ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) ? 31 : 30;
}

int main() {
    cin >> year >> month;

    int day = 0;
    for (int i = 2007; i < year; i++) {
	day += get_day_by_year(i);
    }

    for (int i = 1; i < month; i++) {
	day += get_day_by_month(i);
    }

    int week = (1 + day) % 7;

    cout << "---------------------" << endl;
    cout << " Su Mo Tu We Th Fr Sa" << endl;
    cout << "---------------------" << endl;
    
    day = get_day_by_month(month);
    int cnt = 1;
    cout << " ";
    for (int i = 0; i < week; i++) 
	cout << "   ";

    for (int i = 1; i <= day; i++) {
	if (!(week++ % 7))
	    cout << endl << " ";
	if (i < 10) 
	    cout << " ";
	cout << i << " ";
    }
    cout << endl << "---------------------" << endl;

    return 0;
}
