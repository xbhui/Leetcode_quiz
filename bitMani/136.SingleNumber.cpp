#include <iostream>
#include "stdio.h"
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums){
		if(nums.size()<=0) return -1;
		
		int bnum=nums[0];
		for(int i=1;i<nums.size();i++){
			bnum = bnum^nums[i];
		}	
	
		return bnum;;
	}	
};


int main(){

	vector<int> a1 = {2,2,1};
	vector<int> a2 = {4,1,2,1,2};
	Solution so;
	int result = so.singleNumber(a2);
	
	cout << result <<endl;
	return 0;
}

