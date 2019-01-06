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
	int cap;
	vector<int> vec;
	map<int, int> mapCache;

	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
//		cout<<"get("<<key<<")="<<mapCache.count(key)<<endl;
		if(0==mapCache.count(key)) {
			return -1;
		}
		movetoend(key);
		for(int i=0; i<vec.size(); i++) {
	//		cout<<"i:"<<i<<",val:"<<vec[i]<<endl;
		}

	//	cout<<"map:"<<endl;
		map<int,int>::iterator it;
		for(it=mapCache.begin();it!=mapCache.end();it++){
		//	cout <<"key:"<<it->first <<",value:"<< it->second<<endl;
		}
		return mapCache[key];
	}

	void movetoend(int key) {
		vector<int>::iterator it;
		for(it=vec.begin(); it!=vec.end(); it++) {
			if(*it==key) {
				vec.erase(it);
				vec.push_back(key);
			}
		}
	}

	void put(int key, int value) {
	//	cout<<"put:" << key <<","<< value<<endl;
		if (mapCache.count(key)) {
			movetoend(key);
			return ;
		}

		if(vec.size() >= cap) {
			vector<int>::iterator it=vec.begin();
	//		cout<<"erase("<<*it<<"):"<<mapCache.erase(*it) <<endl;;
			mapCache.erase(*it);
			vec.erase(it);
		}

		mapCache[key]=value;
		vec.push_back(key);

//		cout<<"map:"<<endl;
		map<int,int>::iterator it;
		for(it=mapCache.begin();it!=mapCache.end();it++){
	//		cout <<"key:"<<it->first <<",value:"<< it->second<<endl;
		}

		for(int i=0; i<vec.size(); i++) {
//			cout<<"i:"<<i<<",val:"<<vec[i]<<endl;
		}
	}
};
/*
	0 - 8    -> 0 - 2   ->  3 - 3  ->  0 - 8 -> 4 - 4
	1 - 2		1 - 8		8 - 8	   1 - 3    3 - 4

	put(8,8)    get(8)      put(3,3)            put(4,4)
    put(2,2)

*/
int main() {

	LRUCache *obj = new LRUCache(2);
	obj->put(1,1);
	obj->put(2,2);
	int param_1 = obj->get(1);
	obj->put(3,3);
	int param_2 = obj->get(2);
	obj->put(4,4);

	int param_3 = obj->get(1);
	int param_4 = obj->get(3);
	int param_5 = obj->get(4);

	cout<< param_1 <<endl;
	cout<< param_2 <<endl;
	cout<< param_3 <<endl;
	cout<< param_4 <<endl;
	cout<< param_5 <<endl;

/*

	cache.put(1,1);
	cache.put(2,2);

	int ret1 = cache.get(1);

	cache.put(3,3);

	int ret2 = cache.get(2);

	cache.put(4,4);

	int ret3 = cache.get(1);

	int ret4 = cache.get(3);

	int ret5 = cache.get(4);

	cout<<"1:"<<ret1<<", 2:"<<ret2<<", 1:"<<ret3<<", 3:"<<ret4<<", 4:"<<ret5<<endl;
*/

/*;
	cache.put(8, 8);
    cache.put(2, 2);
    int ret1 = cache.get(8);       // returns 8
    cache.put(3, 3);    // evicts key 2
    int ret2 = cache.get(2);       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 8
    int ret3 = cache.get(8);       // returns -1 (not found)
    int ret4 = cache.get(3);       // returns 3
    int ret5 = cache.get(4);       // returns 4


	cache.put(6,6);
	int ret6 = cache.get(3);


	std::cout<<"ret1:"<<ret1<<";ret2:"<<ret2<<";ret3:"<<ret3 <<endl;
	std::cout<<"ret4:"<<ret4<<";ret5:"<<ret5<<";ret6:"<<ret6<<endl;
*/
	return 0;
}
