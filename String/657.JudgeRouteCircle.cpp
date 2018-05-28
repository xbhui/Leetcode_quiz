#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "stddef.h"

using namespace std;

class Solution {

	public:

		Solution(){

		}

		bool judgeCircle(std::string moves) {

			std:map<char,int> m;
			m['U'] = 1;
			m['D'] = -1;
			m['L'] = -1;
			m['R'] = 1;

			if(0==moves.size()){
				return false;
			}

			int ret=0;

			for(int i=0;i<moves.size();i++) {
					char v = moves[i];
					ret+=m[v];
			}

			if(ret==0){
				return true;
			}else{
				return false;
			}
		};
};

int main(){

	Solution so;
	bool ret = so.judgeCircle("LDRRLRUULR");
	cout<<"ouput the result here:"<<ret<<"\n"<<endl;
	return 0;
}
