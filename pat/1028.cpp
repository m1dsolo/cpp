#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

struct student {
    int id;
    char name[9];
    int score;
} students[N];

int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++)
	scanf("%d %s %d", &students[i].id, &students[i].name, &students[i].score);

    sort(students, students + n, [&c](const student &s1, const student &s2) {
	switch (c) {
	    case 1: return s1.id < s2.id;
	    case 2: return strcmp(s1.name, s2.name) ? strcmp(s1.name, s2.name) < 0 : s1.id < s2.id;
	    case 3: return s1.score != s2.score ? s1.score < s2.score : s1.id < s2.id;
	}
    });

    for (int i = 0; i < n; i++)
	printf("%06d %s %d\n", students[i].id, students[i].name, students[i].score);

    return 0;
}
