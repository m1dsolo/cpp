#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

const int N = 110;

int arr[2][N][N], ij[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int v[N];

int get_cnt(int i, int j, int k, int n) {
    int cnt = 0;
    for (int l = 0; l < 8; l++) {
	int ii = (i + ij[l][0] + n) % n, jj = (j + ij[l][1] + n) % n;
	cnt += arr[k][ii][jj];
    }
    return cnt;
}

string get_string(int n, int k) {
    stringstream ss;
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++)
	    ss << arr[k][i][j] << ',';
    }
    return ss.str();
}

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++)
		scanf("%d", &arr[0][i][j]);
	}

	int k = 0, num = 0;
	unordered_map<string, int> map;
	stringstream ss;
	for (int i = 0; i < n * n; i++)
	    ss << '0' << ',';
	map[ss.str()] = num++;
	for (int l = 0; l <= m; l++) {
	    string s = get_string(n, k);
	    if (!map.count(s)) map[s] = num++;
	    v[l] = map[s];
	    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		    int cnt = get_cnt(i, j, k, n);
		    if (cnt == 3) arr[k ^ 1][i][j] = 1;
		    else if (cnt < 2 || cnt > 3) arr[k ^ 1][i][j] = 0;
		    else arr[k ^ 1][i][j] = arr[k][i][j];
		}
	    }
	    k ^= 1;

	}

	int i = 1;
	for (; i < n; i++) {
	    if (v[i] <= v[i - 1]) {
		break;
	    }
	}
	if (i == n || !v[i])
	    printf("NO\n");
	else
	    printf("YES\n%d\n", i);
    }

    return 0;
}
