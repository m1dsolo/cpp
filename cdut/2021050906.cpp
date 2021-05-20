#include <iostream>

using namespace std;

const int N = 2e5 + 10;

char s[N];
int size;

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    char c;
    for (int i = 0; i < n; i++) {
	scanf("%c", &c);
	if (size >= 2 && c == 'd' && s[size - 1] == 'b' && s[size - 2] == 'c')
	    size -= 2;
	else
	    s[size++] = c;
    }

    printf("%d\n", size);

    return 0;
}
