#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

struct Node {
    Node *next[26] = {nullptr};
    bool end = false; 
};

Node *head = new Node; 

void insert(string &s) {
    Node *node = head;
    for (char c : s) {
        if (!node->next[c - 'a'])
           node->next[c - 'a'] = new Node;
        node = node->next[c - 'a'];
    }
    node->end = true;
}

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
	cin >> s;
	insert(s);
    }

    for (int i = 0; i < m; i++) {
	cin >> s;
        queue<int> q;
        q.push(0);
        int rst = 0;
	unordered_set<int> visited;
	visited.insert(0);
        while (int size = q.size()) {
            while (size--) {
                int begin = q.front(); q.pop();
		rst = max(rst, begin);
                Node *node = head;
                int ptr = begin;
		if (begin >= s.length()) break;
                while (Node *next = node->next[s[ptr] - 'a']) {
                    if (next->end && !visited.count(ptr + 1)) {
			visited.insert(ptr + 1);
                        q.push(ptr + 1);
                    }
		    ptr++;
                    node = next;
                }
            }
        }
        cout << rst << endl;
    }
    return 0;
}
