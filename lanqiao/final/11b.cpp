#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

int xy[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int get_hash(int x, int y) {
    //return to_string(x) + "," + to_string(y);
    return x * 100000 + y;
}

// bfs一定要进的时候visited = true!!!
int main() {
    unordered_set<int> set;
    queue<pair<int, int>> q;
    q.push({0, 0});
    q.push({2020, 11});
    q.push({11, 14});
    q.push({2000, 2000});
    set.insert(get_hash(0, 0));
    set.insert(get_hash(2020, 11));
    set.insert(get_hash(11, 14));
    set.insert(get_hash(2000, 2000));

    long long rst = 0;
    for (int i = 0; i <= 2020; i++) {
	rst += q.size();
	int size = q.size();
	while (size--) {
	    int x = q.front().first, y = q.front().second; q.pop();
	    for (int i = 0; i < 4; i++) {
		int xx = x + xy[i][0], yy = y + xy[i][1];
		if (!set.count(get_hash(xx, yy))) {
		    set.insert(get_hash(xx, yy));
		    q.push({xx, yy});
		}
	    }
	}
    }
    cout << rst << endl;

    return 0;
}
