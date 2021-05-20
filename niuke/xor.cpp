#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<vector<long long>> arr;
long long rst[100001];
const long long max_val = 2e10;
const int VAL = 1e9 + 1;
int main() {
    int n, m;
    cin >> n >> m;
    int a, b;
    bool flag = false;
    arr.push_back({0, 0});
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end());
    int ptr = 0;
    int val = 0;
    for (int i = 1; i <= m; i++) {
        if (arr[i][1]) {
            if (arr[i][0] == arr[i - 1][0]) {
                if (arr[i][1] != arr[i - 1][1]) {
                    cout << -1 << endl;
                    return 0;
                }
                continue;
            }
            for (int j = 0; j < arr[i][0] - arr[i - 1][0] - 1; j++) {
                val = val ^ VAL;
                rst[ptr++] = VAL;
            }
            val = val ^ arr[i][1];
            rst[ptr++] = val;
        }
        else {
            if (arr[i][0] == arr[i - 1][0] + 1 && !val) {
                cout << -1 << endl;
                return 0;
            }
            for (int j = 0; j < arr[i][0] - arr[i - 1][0] - 1; j++) {
                int tmp = (val == VAL) ? VAL + 1 : VAL;
                val = val ^ tmp;
                rst[ptr++] = tmp;
            }
            val = val ^ arr[i][1];
            rst[ptr++] = val;
        }
    }
    for (int i = 0; i < ptr; i++) {
        if (rst[i] < 1 || rst[i] > max_val) {
            cout << - 1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < ptr; i++) {
        printf("%d ", rst[i]);
    }
    while (ptr < n) {
        printf("1 ");
        ptr++;
    }
    printf("\n");
    int sb = 0;
    for (int i = 0; i < ptr; i++) {
        sb = sb ^ rst[i];
        cout << sb << endl;
    }
    
    return 0;
}
