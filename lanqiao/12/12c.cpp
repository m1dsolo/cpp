#include <iostream>
#include <functional>
#include <unordered_set>

using namespace std;

//struct pair_hash {
    //size_t operator()(const pair<int, int> &p) const {
	//return hash<int>
    //};
//};

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    unordered_set<string> set;
    for (int x0 = 1; x0 <= 20; x0++) {
	for (int y0 = 1; y0 <= 21; y0++) {
	    for (int x1 = 1; x1 <= 20; x1++) {
		for (int y1 = 1; y1 <= 21; y1++) {
		    if (x0 == x1) continue;
		    int a1 = y1 - y0;
		    int b1 = x1 - x0;
		    int a2 = x1 * y0 - x0 * y1;
		    int b2 = x1 - x0;
		    int g1 = gcd(a1, b1);
		    //cout << "g1" << a1 << ' ' << b1 << " " << g1 << endl;
		    a1 /= g1; b1 /= g1;
		    int g2 = gcd(a2, b2);
		    //cout << "g2" << a2 << ' ' << b2 << " " << g2 << endl;
		    a2 /= g2; b2 /= g2;
		    set.insert(to_string(a1) + ',' + to_string(b1) + ',' + to_string(a2) + ',' + to_string(b2));
		}
	    }
	}
    }
    cout << set.size() << endl;

    return 0;
}
