#include <cstdio>

using namespace std;

int helper() {
    int hour, minute, second;
    int time[2];
    for (int i = 0; i < 2; i++) { 
	scanf("%02d:%02d:%02d", &hour, &minute, &second);
	time[i] = (hour * 60 + minute) * 60 + second;
    }
    int d;
    char c;
    scanf("%c", &c);
    if (c != '\n') {
	scanf("(+%d)", &d);
	time[1] += d * 24 * 3600;
    }

    return time[1] - time[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int hour, minute, second;
    while (n--) {
	int time = (helper() + helper()) / 2;
	second = time % 60; time /= 60;
	minute = time % 60; time /= 60;
	hour = time;

	printf("%02d:%02d:%02d\n", hour, minute, second);
    }

    return 0;
}
