#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int>	twoSum(vector<int>& nums,int target){
		vector<int> result;
		for(int i=0;i<nums.size();i++){
			for(int j=i+1;j<nums.size();j++){
				if(nums[i]==target-nums[j]){
					result.push_back(i);
					result.push_back(j);
				}
			}
		}
		return result;
	}
};

int main(){

	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);

	Solution so;
	vector<int> result = so.twoSum(nums,18);
	for(int i=0;i<result.size();i++){
		cout<< result[i] <<endl;
	}

	return 0;
}
