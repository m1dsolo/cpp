#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    bool map[n] = {false};
    map[0] = true;
    queue<int> q;
    q.push(0);
    int level = 0;
    int index;
    while (q.size()) {
	int tmp = q.size();
	while (tmp--) {
	    int time = q.front(); q.pop();
	    index = (time + 1) % n;
	    if (!map[index]) {
		q.push(index);
		map[index] = true;
	    }
	    index = (time + k) % n;
	    if (!map[index]) {
		q.push(index);
		map[index] = true;
	    }
	}
	level++;
    }

    cout << level - 1 << endl;

    return 0;
}
