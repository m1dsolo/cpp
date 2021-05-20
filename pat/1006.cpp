#include <iostream>
#include <algorithm>

using namespace std;

inline int get_time() {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
}

int main() {
    int m;
    string rst1, rst2, id;
    int time, time1 = 1000000, time2 = -1;
    scanf("%d", &m);
    while (m--) {
	cin >> id;
	time = get_time();	
	if (time < time1) {
	    time1 = time;
	    rst1 = id;
	}
	time = get_time();
	if (time > time2) {
	    time2 = time;
	    rst2 = id;
	}
    }

    cout << rst1 << " " << rst2 << endl;

    return 0;
}
