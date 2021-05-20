#include <iostream>

using namespace std;

template<typename T0>
void print(T0 val) {
    cout << val << endl;
}

template<typename T, typename... Ts>
void print(T val, Ts... args) {
    cout << val << " ";
    print(args...);
}

int main() {
    print(1, 2, 3);
    print(1, "niubi", 20.0);

    return 0;
}
