#include <iostream>
#include "stdio.h"

using namespace std;

class Solution {
	public:
		int hammingDistance(int x,int y){
			int dis = 0;
			int num = x^y;
			while(num>0){
				if((num&1) == 1) dis++;
				num=num>>1;
			}
			return dis;
		}
};

int main(){

	Solution so;
//	int x = 1,y=4;
//	int x = 1,y=8;
//	int x = 4,y=8;
    int x = 93,y=73;

	int result = so.hammingDistance(x,y);
	cout<< result <<endl;
}
