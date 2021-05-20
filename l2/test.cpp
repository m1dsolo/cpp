#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int arr[2];
    memset(arr, 127, sizeof(int));

    cout << arr[0] << " " << arr[1] << endl;

    return 0;
}
