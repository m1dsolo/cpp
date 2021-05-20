#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

unordered_map<string, int> map;

int main() {
    vector<string> v1{"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu"}, 
		v2 {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
    for (int i = 0; i < v1.size(); i++)
	map[v1[i]] = i;

    char buf[10];
    int n, a, b, c;
    scanf("%d", &n);
    cout << n << endl;

    for (int i = 0; i < n; i++) {
	memset(buf, 0, sizeof(buf));
	scanf("%d. %s %d", &a, buf, &c);
	b = map[buf];

	int days = c * 365 + b * 20 + a + (b == 17 ? -15 : 0);

	cout << days % 13 + 1 << " " << v2[days % 20] << " " << days / 260 << endl;
    }


    return 0;
}
