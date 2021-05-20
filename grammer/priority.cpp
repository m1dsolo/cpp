// ?????
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1{5, 5, 5}, v2(v1), v3(v1);
    int i = 1;
    bool flag = true;
    // 先右面
    v1[i++] = (flag ? i + 1 : i - 1);

    int j = 1;
    // 先左面
    v2[j++] = j + 1;

    int k = 1;
    // 先右面
    v3[k++] = k++;

    for (int num : v1)
	cout << num << " ";
    cout << endl;
    for (int num : v2)
	cout << num << " ";
    cout << endl;
    for (int num : v3)
	cout << num << " ";
    cout << endl;

    return 0;
}
