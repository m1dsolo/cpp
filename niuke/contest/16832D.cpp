// 只需第一个窗口([0 ~ k - 1]是平衡的，并且接下来每个i与i - k都满足(字符相等，或者其中有一个?))(这个思路是错误的why？)
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

char s[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    getchar();
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
	scanf("%c", &s[i]);
	if (s[i] == '0') a++;
	else if (s[i] == '1') b++;
    }

    bool rst = true;
    if (a > n / 2 || b > k / 2 || (k & 1))	// 初始窗口不满足
	rst = false;
    else {
	for (int i = k; i < n; i++) {
	    scanf("%c", &s[i]);
	    if (s[i] != '?' && s[i - k] != '?' && s[i] != s[i - k]) {	    // 最初写的不知道为什么错了
		rst = false;
		break;
	    }
	}
    }

    printf("%s\n", rst ? "Yes" : "No");

    return 0;
}
