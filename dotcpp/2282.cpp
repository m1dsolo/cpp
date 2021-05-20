#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 2 * n + (n - 2) * 2;
    stringstream ss;
    int num = 1;
    for (int i = 0; i < sum; i++) {
	ss << num++;
    }
    int left = 0, right = sum - 1;
    string s = ss.str();

    for (int i = 0; i < n - 1; i++)
	printf(".");
    printf("%c\n", s[left++]);
    num = 1;
    int tmp = 1;
    for (int i = n - 2; i >= 1; i--) {
	for (int j = 0; j < i; j++)
	    printf(".");
	printf("%c", s[left++]);
	for (int j = 0; j < tmp; j++)
	    printf(".");
	printf("%c\n", s[right--]);
	tmp += 2;
    }
    while (left <= right) {
	printf("%c", s[left++]);
    }
    printf("\n");

    return 0;
}
