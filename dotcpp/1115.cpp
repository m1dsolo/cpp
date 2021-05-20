#include<iostream>
using namespace std;

// eg: X___X n:5, a:5
// eg: _X_X_ n:5, a:3
void draw_row(int n, int a) {
    if (a == 1) {
        for (int i = 0; i < n / 2; i++) cout << ' ';
        cout << 'X';
        for (int i = 0; i < n / 2; i++) cout << ' ';
        cout << endl;
    }
    else {
        for (int i = 0; i < (n - a) / 2; i++) cout << ' ';
        cout << 'X';
        for (int i = 0; i < a - 2; i++) cout << ' ';
        cout << 'X';
        for (int i = 0; i < (n - a) / 2; i++) cout << ' ';
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        int j = b + 1;
        int val = a;
        bool down = true;
        while (j) {
            draw_row(a, val);
            if (val == a) j--;
            if ((val == a && !down) || (val == 1 && down)) down = !down;
            val = (down) ? val - 2 : val + 2;
        }
        cout << endl;
    }
    return 0;
}
