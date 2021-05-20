#include <iostream>

using namespace std;
using ll = long long;

inline ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

inline ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a * b / gcd(a, b);
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    cout << lcm(a, lcm(b, c)) << endl;;

    return 0;
}
