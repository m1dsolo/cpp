// 单调队列求固定区间大小最值O(n) (比线段树，st表O(logn)快)
// 单调递增(从front到back)是求最大值(因为中间小的值没有用丢掉了)
// 参考https://zhuanlan.zhihu.com/p/346354943
#include <iostream>
#include <deque>

using namespace std;

int arr[(int)1e6 + 10];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    deque<int> d;
    for (int i = 0; i < n; i++) {
	scanf("%d", &arr[i]);
	if (d.size() && i - d.front() >= m)	// 退役
	    d.pop_front();
	while (d.size() && arr[i] < arr[d.back()])	// 被新生虐了，当场退役(求最大值只需改大于小于号)
	    d.pop_back();
	d.emplace_back(i);

	if (i >= m - 1)
	    printf("%d\n", arr[d.front()]);
    }

    return 0;
}
