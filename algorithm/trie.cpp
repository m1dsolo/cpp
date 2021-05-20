#include <iostream>
#include <vector>

using namespace std;


class Trie {
private:
    struct Node {
	bool is_end = false;
	Node *next[26] = {nullptr};
    };
    Node *head;
public:
    Trie(const vector<string> &v) {
	head = new Node;
	for (string s : v) {
	    insert(s);
	}
    }

    void insert(const string &s) {
	Node *ptr = head;
	for (char c : s) {
	    if (!ptr->next[c - 'a']) {
		ptr->next[c - 'a'] = new Node;
	    }
	    ptr = ptr->next[c - 'a'];
	}
	ptr->is_end = true;
    }

    bool search(const string &s) {
	Node *ptr = head;
	for (char c : s) {
	    if (!ptr->next[c - 'a']) return false;
	    ptr = ptr->next[c - 'a'];
	}
	return ptr->is_end;
    }

    bool start_with(const string &s) {
	Node *ptr = head;
	for (char c : s) {
	    if (!ptr->next[c - 'a']) return false;
	    ptr = ptr->next[c - 'a'];
	}
	return true;
    }    
};

int main() {
    Trie t(vector<string> {"app"});
    cout << t.search("apple") << endl;
    cout << t.start_with("app") << endl;

    return 0;
}
