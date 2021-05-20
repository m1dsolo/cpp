#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int t;
    cin >> t;
    stringstream rst;

    int h = t / 3600;
    rst << t / 3600 << ':' << (t % 3600) / 60 << ':' << t % 60;
 
    cout << rst.str() << endl;

    return 0;
}

