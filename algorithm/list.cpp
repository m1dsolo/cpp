#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class List {
private:
    class ListNode {
    public:
	T val;
	ListNode *next;
	ListNode(T _val) {
	    val = _val;
	};
    };

    ListNode *dummy;

    ListNode *reverse(ListNode *head) {
	if (!head || !head->next) return head;
	ListNode *rst = reverse(head->next);
	head->next->next = head;
	head->next = nullptr;

	return rst;
    };
public:
    List(const vector<T> &v) {
	dummy = new ListNode(0);
	ListNode *tmp = dummy;
	for (int i = 0; i < v.size(); i++) {
	    tmp->next = new ListNode(v[i]);
	    tmp = tmp->next;
	}
	cout << dummy->next->val << endl;
    }

    void print() {
	ListNode *ptr = dummy;
	while (ptr = ptr->next) {
	    cout << ptr->val << " ";
	}
	cout << endl;
    };

    void reverse() {
	dummy->next = reverse(dummy->next);	
    };

    // reverse from node that val == left to node that val == right
    void reverse(int left, int right) {
	ListNode *ptr = dummy;
	ListNode *front = nullptr, *back = nullptr;
	while (ptr->next) {
	    if (ptr->next->val == left) 
		front = ptr;
	    if (ptr->next->val == right) {
		back = ptr->next->next;
		ptr->next->next = nullptr;
	    }
	    ptr = ptr->next;
	}
	if (front) {
	    ptr = front->next;
	    front->next = reverse(front->next);
	    ptr->next = back;
	}	
    }
};

int main() {
    List<int> l(vector<int> {1});
    l.print();
    l.reverse(1, 1);
    l.print();

    return 0;
}
