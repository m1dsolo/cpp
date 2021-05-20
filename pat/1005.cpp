#include <iostream>
#include <vector>

using namespace std;

string map[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    char c;
    int sum = 0;
    while (scanf("%c", &c) != EOF) {
	if (isdigit(c))
	    sum += c - '0';
    }

    vector<int> nums;
    if (sum) {
	while (sum) {
	    nums.emplace_back(sum % 10);
	    sum /= 10;
	}
    }
    else
	nums.emplace_back(0);
    for (int i = nums.size() - 1; i > 0; i--)
	cout << map[nums[i]] << " ";
    cout << map[nums[0]] << endl;

    return 0;
}
