#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();
    char buf[1000];
    for (int i = 0; i < n; i++) {
        cin.getline(buf, 1000);
        cout << buf << endl << endl;
    }
    
    string s;
    while (cin >> s) {
        cout << s << endl << endl;
    }
    
    return 0;
}
