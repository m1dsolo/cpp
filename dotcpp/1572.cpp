#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int val;
    cin >> hex >> val;
    cout << setiosflags(ios::uppercase) << hex << val << " " << dec << val << " " << oct << val << endl;

    return 0;
}
