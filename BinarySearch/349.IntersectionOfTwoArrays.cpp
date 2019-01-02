#include "stdio.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> intersection1(vector<int>& nums1,vector<int>& nums2) {
		vector<int> res;
		map<int,int> m;
		for(int i=0;i<nums1.size();i++) m[nums1[i]]++;
		for(int i=0;i<nums2.size();i++){
			if(m[nums2[i]]>0) res.push_back(nums2[i]);
			m[nums2[i]]=0;
		}
		return res;
	}
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
				
		vector<int> vec;
		
		set<int> set1;
		int i=0; 
		while(i<nums1.size()){
			set1.insert(nums1[i]);
			i++;
		}
		cout <<"set1:"<<set1.size()<<endl;
	
		set<int> set2;
		i=0;
		while(i<nums2.size()){
			set2.insert(nums2[i]);
			i++;
		}
		cout<<"set2:"<<set2.size()<<endl;
						
		if(set1.empty() || set2.empty() )
			return vec;

		vector<int> set_vec2;
		for(set<int>::iterator it=set2.begin();it!=set2.end();it++){
				set_vec2.push_back(*it);
		} 
		cout<<"set_vec2:"<<set_vec2.size()<<endl;			

		for(set<int>::iterator it=set1.begin();it!=set1.end();it++){
			cout<<"set1:"<<*it<<endl;
		
			if(intersection_search(*it,0,set_vec2.size()-1,set_vec2)){
				vec.push_back(*it);
			}
		
		}
		
		cout << "init nums:"<< vec.size() << endl;		
		return vec;		
	}
	
	int intersection_search(int num,int left,int right,vector<int>& vec){
		cout <<"is_num:"<<num<<"left:"<<left<<"right:"<<right<<endl;	
		if(left > right){
			return 0;
		}
		if(vec[right]<num || vec[left]>num){
			return 0;
		}		
		
		int mid =left+(right-left)/2;
		if(num==vec[mid]){
			return 1;
		}

		if(num<vec[mid]){
			return intersection_search(num,left,mid-1,vec);
		}else{		
		    return intersection_search(num,mid+1,right,vec);
		}
	}
};

int main() {

	vector<int> nums1;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(2);
	nums1.push_back(1);
		
	vector<int> nums2;
	nums2.push_back(2);
	nums2.push_back(2);
/*
	vector<int> nums1;
	nums1.push_back(4);
	nums1.push_back(9);
	nums1.push_back(5);
		
	vector<int> nums2;
	nums2.push_back(9);
	nums2.push_back(4);
	nums2.push_back(9);
	nums2.push_back(8);
	nums2.push_back(4);
*/
	Solution so;
	vector<int> nums = so.intersection1(nums1,nums2);
	for(int i=0;i<nums.size();i++){
		cout<<"nums:"<<nums[i] <<endl;
	}
	return 0;
} 
