#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[21];
bool adj[21][21], visited[21];
vector<int> path, rst_path;
int rst, sum;

void dfs(int begin) {
    visited[begin] = true;
    path.push_back(begin);
    sum += arr[begin];
    if (sum > rst) {
	rst = sum;
	rst_path = path;
    }

    for (int end = begin + 1; end <= n; end++) {
	if (adj[begin][end] && !visited[end])
	    dfs(end);
    }

    sum -= arr[begin];
    path.pop_back();
    visited[begin] = false;
}
int main() {
    int flag;
    cin >> n;
    for (int i = 1; i <= n; i++)
	cin >> arr[i];
    for (int i = 1; i <= n; i++) {
	for (int j = i + 1; j <= n; j++) {
	    cin >> flag;
	    if (flag) {
		adj[i][j] = true;
	    }
	}
    }
    for (int i = 1; i <= n; i++)
	dfs(i);
    
    for (int a : rst_path)
	cout << a << " ";
    cout << endl << rst << endl;

    return 0;
}
