#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct id {
    string all;
    string birth;
} Id;

bool cmp(Id a, Id b) {
    return (a.birth == b.birth) ? a.all > b.all : a.birth > b.birth;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Id> v;
    v.reserve(n);
    for (int i = 0; i < n; i++) {
	Id id;
	id.all.resize(19);
	cin >> id.all;
	id.birth = id.all.substr(6, 8);
	v.push_back(id);
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++) {
	cout << v[i].all << endl;
    }

    return 0;
}
