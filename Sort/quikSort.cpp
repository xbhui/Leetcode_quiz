#include "stdio.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution{
public:

	int partition(vector<int> &in,int low,int up ){
		int pivot = in[up];
		int i = low-1;

		for(int j=low;j<up;j++){

			if(in[j]<=pivot){
				i++;
				swap(in[i], in[j]);
			}

		}

		swap(in[i+1], in[up]);

		return i+1;
	}

	void quickSort(vector<int> &in,int low,int up){

		if(low<up){
			int mid = partition(in,low,up);
			quickSort(in, low, mid-1);
			quickSort(in, mid+1, up);
		}

	}
	
	void qSort(vector<int> &in) {
		
		quickSort(in, 0, in.size()-1);
	}
}; 


int main()
{
	int a[] = {3,5,7,9,2,3,1,0,7,5};
	vector<int> input(a,a+10);

	cout<<"Before quicksort:\n";	
	for(int x:input){
		cout<<x<<" ";
	}
	cout<<endl;

	Solution so;	
	so.qSort(input);

	cout<<"After quicksort:\n"<<endl;
	for(int x:input){
		cout<<x<<" ";
	}
	cout<<endl;
	
	return 0;
}


