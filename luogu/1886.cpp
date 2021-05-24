#include <iostream>
#include <deque>

using namespace std;

const int N = 1e6 + 10;

int n, k;
int arr[N];
deque<int> q;

void min_queue() {
    for (int i = 0; i < n; i++) {
	if (i < k - 1) {
	    while (q.size() && arr[q.back()] > arr[i])
		q.pop_back();
	    q.emplace_back(i);
	}
	else {
	    while (q.size() && arr[q.back()] > arr[i])
		q.pop_back();
	    q.emplace_back(i);
	    printf("%d ", arr[q.front()]);
	    if (q.front() == i - k + 1)
		q.pop_front();
	}
    }
    printf("\n");
}

void max_queue() {
    for (int i = 0; i < n; i++) {
	if (i < k - 1) {
	    while (q.size() && arr[q.back()] < arr[i])
		q.pop_back();
	    q.emplace_back(i);
	}
	else {
	    while (q.size() && arr[q.back()] < arr[i])
		q.pop_back();
	    q.emplace_back(i);
	    printf("%d ", arr[q.front()]);
	    if (q.front() == i - k + 1)
		q.pop_front();
	}
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i]);

    min_queue();
    q.clear();
    max_queue();

    return 0;
}
