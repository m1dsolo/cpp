#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// sort二维数组不管是局部变量还是全局变量都不行（会segment fault）（因为是栈区和全局区不允许交换？），但是如果new成堆区就可以
int main() {
    char strs[5][10] = {"Wo", "Ai", "Lan", "Qiao", "Bei"};
    sort((char **)strs, (char **)(strs + 5), [](char s1[10], char s2[10]) {
	return strcmp(s1, s2) < 0;
    });
    for (int i = 0; i < 5; i++)
	cout << strs[i] << endl;

    for (int i = 0; i < 5; i++) {
	cout << strs[i] << " " << upper_bound(strs, strs + 5, strs[i], [](const char s1[10], const char s2[10]) {
	    return strcmp(s1, s2) < 0;
	}) - strs << endl;
    }

    return 0;
}
