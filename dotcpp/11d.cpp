#include <iostream>

using namespace std;

int get_day_by_year(int year) {
    return ((!(year % 4) && (year % 100)) || !(year % 400)) ? 366 : 365;
}

int get_day_by_month(int month, int year) {
    switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
	case 2: return get_day_by_year(year) == 366 ? 29 : 28;
	default: return 30;
    }
}

int main() {
    // day
    int rst = 1;
    for (int i = 2000; i < 2020; i++)
	rst += get_day_by_year(i);
    for (int i = 1; i < 10; i++)
	rst += get_day_by_month(i, 2020);

    // 2000~2019 extra
    int week = 6;
    for (int year = 2000; year < 2020; year++) {
	for (int month = 1; month <= 12; month++) {
	    int max_day = get_day_by_month(month, year);
	    for (int day = 1; day <= max_day; day++) {
		if ((day == 1) || (week == 1))
		    rst++;
		week = (week + 1) % 7;
	    }
	}
    }

    // 2020 extra
    for (int month = 1; month < 10; month++) {
	int max_day = get_day_by_month(month, 2020);
	for (int day = 1; day <= max_day; day++) {
	    if ((day == 1) || (week == 1))
		rst++;
	    week = (week + 1) % 7;
	}
    }

    // 2020.10.1
    cout << rst + 1 << endl;

    return 0;
}
