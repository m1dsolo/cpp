#include <iostream>

using namespace std;

int arr[1010];

bool is_bst(int l, int r) {
    if (l > r) return true;
    int ll = l + 1, rr = r - 1;
    while (ll <= r && arr[ll] < arr[l]) ll++;
    while (rr >= l && arr[rr] >= arr[l]) rr--;
    cout << l << " " << " " << r << " " << ll << " " << rr << endl;
    if (rr != ll - 1) return false;
    return is_bst(l, rr) && is_bst(ll, r);
}

void print_mid(int i) {
    //if ()
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d", &arr[i]);

    //if (is_bst()) {
	//printf("YES\n");
	//print_mid();
    //}

    cout << is_bst(0, n - 1) << endl;

    return 0;
}
