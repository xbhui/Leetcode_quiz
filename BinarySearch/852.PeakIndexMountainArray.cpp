#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	int peakIndexInMountainArray2(vector<int>& a,int l,int h){
		int mid = l+(h-l)/2;

		if(a[mid]>a[mid-1] && a[mid]>a[mid+1]) return mid;

		if(a[mid]>a[mid-1] && a[mid]<a[mid+1]) return peakIndexInMountainArray2(a,mid+1,h);

		else
			return peakIndexInMountainArray2(a,l,mid-1);  	
		

	}

	int peakIndexInMountainArray(vector<int>& A)
	{
		return peakIndexInMountainArray2(A,0,A.size()-1);
	}
};

int main(){

	vector<int> v;
	v.insert(2);
	v.insert(3);
	v.insert(4);
	v.insert(1);
	v.insert(0);	

	Solution so;
	so.peakIndexInMountainArray2(v);
	return 0;
}
