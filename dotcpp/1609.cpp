#include <iostream>

using namespace std;

int get_day_by_year(int year) {
    return ((!(year % 4) && (year % 100)) || !(year % 400)) ? 366 : 365;
}

int get_week(int year) {
    int days = 0;
    for (int i = 1998; i < year; i++)
	days += get_day_by_year(i);

    return (days + 4) % 7;
}

int main() {
    int year; cin >> year;
    int week = (get_week(year) + 12) % 7;
    int day;
    
    int rst = 0;
    for (int month = 1; month <= 12; month++) {
	rst += (week == 5);
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	    day = 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	    day = 30;
	else
	    day = (get_day_by_year(year) == 365) ? 28 : 29;
	week = (week + day) % 7;
    }

    cout << rst << endl;

    return 0;
}
