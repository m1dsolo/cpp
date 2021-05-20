#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRU {
private:
    unordered_map<int, list<pair<int, int>>::iterator> map;
    list<pair<int, int>> cache;
    int cap;
public:
    LRU(int cap) : cap(cap) {};
    void put(int key, int val) {
	if (map.find(key) == map.end()) {
	    // is list.size() time complexity == O(1)?
	    if (cache.size() == cap) {
		map.erase(cache.back().first);
		cache.pop_back();
	    }
	}
	else {
	    cache.erase(map[key]);
	}
	cache.push_front({key, val});
	map[key] = cache.begin();
    }
    int get(int key) {
	if (map.find(key) == map.end()) return -1;
	pair<int, int> p = *map[key];
	cache.erase(map[key]);
	cache.push_front(p);
	map[key] = cache.begin();
	
	return p.second;
    }
    void print() {
	int i = 0;
	for (auto it = cache.begin(); it != cache.end(); it++) {
	    cout << it->first << ":" << it->second << " ";
	    if (!(i = (i + 1) % 4))
		cout << endl;
	}
    }
};
int main() {
    LRU lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    lru.print();

    return 0;
}
