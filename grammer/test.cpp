#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1{3, 3, 3}, v2(v1);
    int i = 1;
    bool flag = true;
    //v1[i++] = (flag ? i + 1 : i - 1);
    v1[i++] = i++;

    int j = 1;
    v2[j++] = j + 1;

    for (int num : v1)
	cout << num << " ";
    cout << endl;
    for (int num : v2)
	cout << num << " ";
    cout << endl;

    return 0;
}
