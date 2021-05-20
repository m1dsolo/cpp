#include <iostream>

using namespace std;

int helper(int a) {
    int rst = 1;
    while (a != 1) {
        a = (a % 2) ? 3 * a + 1 : a / 2;
        rst++;
    }
    return rst;
}

int main()
{
    int a, b;
    while (cin >> a >> b) {
        bool flag = false;
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
            flag = true;
        }
        int rst = 0;
        for (int i = a; i <= b; i++) {
            rst = max(rst, helper(i));
        }
        
        if (!flag) 
            cout << a << " " << b << " " << rst << endl;
        else
            cout << b << " " << a << " " << rst << endl;
    }
    
    return 0;
}
