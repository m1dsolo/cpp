#include <iostream>
#include <unordered_set>
#include <vector>
#include <typeinfo>

using namespace std;


struct h {
    size_t operator()(const vector<int> &v) const {
	return hash<int>()(v[0]) ^ hash<int>()(v[1]);
    }
};

int main() {
    unordered_set<vector<int>, h> set;
    set.insert({0, 0});
    
    cout << set.count({0, 0}) << endl;
    cout << set.count({0, 1}) << endl;

    return 0;
}
