#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums){

		int lastNoZeroIndex = 0;
		for(int i=0;i<nums.size();i++){
			if(nums[i]!=0){
				nums[lastNoZeroIndex++]=nums[i];
			}
		}
	
		for(int i=lastNoZeroIndex;i<nums.size();i++){
			nums[i]=0;
		}
	}

};


int main(){
    
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(12);

	Solution so;
	so.moveZeroes(nums);

	vector<int>::iterator itor;

	for(itor=nums.begin();itor!=nums.end();itor++){
		cout<< *itor <<endl;
	}
	return 0;
}
