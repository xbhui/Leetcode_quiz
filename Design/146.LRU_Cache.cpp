#include <iostream>
#include "stdio.h"
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#include <map>


using namespace std;


class LRUCache {
public:
	int cap = 0;	
	vector<int> vec;
	map<int,int> map;

	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		map<int, int>::iterator it = find(key);
		if (it == map.end()) {
			return -1;
		}
		movetoend(key);
		return it->second;
	}
	
	void movetoend(int key) {
		vector<int>::iterator it = vec.find(key);
		vec.erase(*it);
		vec.push_back(key);
	}

	void put(int key, int value) {
	
		if (map.count(key)) {
			movetoend(key);
			return ;
		}	
	
		if(vec.size() >= cap ) {
			map.erase(key);;
			vec.erase(0);
		}

		map.insert(key, value);
		vector.push_back(key);
	}
};

int main() {
	LRUCache cache = LRUCache( 2 /* capacity */ );
	cache.put(1, 1);
    cache.put(2, 2);
    int ret1 = cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    int ret2 = cache.get(2);       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    int ret3 = cache.get(1);       // returns -1 (not found)
    int ret4 = cache.get(3);       // returns 3
    int ret5 = cache.get(4);       // returns 4

	return 0;
}

