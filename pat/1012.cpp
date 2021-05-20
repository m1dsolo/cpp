#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> vc, vm, ve, va;

struct grades {
    int c;
    int m;
    int e;
    int a;
};

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    unordered_map<int, grades> map;

    int id, c, m, e, a;
    for (int i = 0; i < n; i++) {
	scanf("%d %d %d %d", &id, &c, &m, &e);
	a = (c + m + e) / 3;
	map[id] = {c, m, e, a};
	vc.emplace_back(c);
	vm.emplace_back(m);
	ve.emplace_back(e);
	va.emplace_back(a);
    }

    sort(vc.begin(), vc.end(), greater<int>());
    sort(vm.begin(), vm.end(), greater<int>());
    sort(ve.begin(), ve.end(), greater<int>());
    sort(va.begin(), va.end(), greater<int>());

    int rc, rm, re, ra;
    for (int i = 0; i < k; i++) {
	scanf("%d", &id);
	int max_rank = 1000000;
	char course;
	if (map.find(id) != map.end()) {
	    if ((ra = lower_bound(va.begin(), va.end(), map[id].a, greater<int>()) - va.begin()) < max_rank) {
		max_rank = ra;
		course = 'A';
	    }
	    if ((rc = lower_bound(vc.begin(), vc.end(), map[id].c, greater<int>()) - vc.begin()) < max_rank) {
		max_rank = rc;
		course = 'C';
	    }
	    if ((rm = lower_bound(vm.begin(), vm.end(), map[id].m, greater<int>()) - vm.begin()) < max_rank) {
		max_rank = rm;
		course = 'M';
	    }
	    if ((re = lower_bound(ve.begin(), ve.end(), map[id].e, greater<int>()) - ve.begin()) < max_rank) {
		max_rank = re;
		course = 'E';
	    }
	    cout << max_rank + 1 << " " << course << endl;
	}
	else
	    cout << "N/A" << endl;
    }

    return 0;
}
