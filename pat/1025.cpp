// 坑：id如果用long long需要补前导0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 110;

struct testee {
    string id;
    int score;
    int frank;
    int num;
    int lrank;
};

vector<testee> vec;

bool cmp(const testee &t1, const testee &t2) {
    return t1.score != t2.score ? t1.score > t2.score : t1.id < t2.id;
}

int main() {
    ios::sync_with_stdio(false);
    int n, k, score;
    cin >> n;
    for (int i = 1; i <= n; i++) {
	cin >> k;
	vector<testee> v(k);
	for (int j = 0; j < k; j++) {
	    cin >> v[j].id >> v[j].score;
	    v[j].num = i;
	}
	sort(v.begin(), v.end(), cmp);
	v[0].lrank = 1;
	vec.emplace_back(v[0]);
	for (int j = 1; j < k; j++) {
	    v[j].lrank = (v[j].score == v[j - 1].score ? v[j - 1].lrank : j + 1);
	    vec.emplace_back(v[j]);
	}
    }

    sort(vec.begin(), vec.end(), cmp);
    cout << vec.size() << endl;

    vec[0].frank = 1;
    cout << vec[0].id << " " << vec[0].frank << " " << vec[0].num << " " << vec[0].lrank << endl;
    for (int i = 1; i < vec.size(); i++) {
	vec[i].frank = (vec[i].score == vec[i - 1].score ? vec[i - 1].frank : i + 1);
	cout << vec[i].id << " " << vec[i].frank << " " << vec[i].num << " " << vec[i].lrank << endl;
    }

    return 0;
}
