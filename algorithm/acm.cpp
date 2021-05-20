#include <iostream>

#define isdigit(x) ((x) >= '0' && (x) <= '9')

int read() {
    int res = 0;
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) res = (res << 1) + (res << 3) + c - 48, c = getchar();
    return res;
}

void printi(int x) {
    if(x / 10) printi(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    for (int i = 0; i < 5; i++) {
	printi(read());
    }
}
