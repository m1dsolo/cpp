#include <iostream>
#include <iomanip>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

set<string> st;

bool leap(int year) {
    return (!(year % 4) && year % 100) || (!(year % 400));
}

int get_max_day(int month, bool flag) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	return 31;
    else if (month == 2)
	return flag ? 29 : 28;
    else
	return 30;
}

void helper(int year, int month, int day) {
    year = (year >= 60) ? year + 1900 : year + 2000;
    bool flag = leap(year);
    if (month < 1 || month > 12) return;
    int max_day = get_max_day(month, flag);
    if (day < 1 || day > max_day) return;

    stringstream ss;
    ss.fill('0');
    ss << year << '-' << setw(2) << month << '-' << setw(2) << day;

    st.insert(ss.str());
}

int main() {
    string s;
    cin >> s;
    int a = stoi(s.substr(0, 2));
    int b = stoi(s.substr(3, 2));
    int c = stoi(s.substr(6, 2));

    helper(a, b, c);
    helper(c, a, b);
    helper(c, b, a);

    for (string s : st)
	cout << s << endl;

    return 0;
}
