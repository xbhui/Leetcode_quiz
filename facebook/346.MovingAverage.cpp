#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class MovingAverage {
	
public:
	int wsize;
    vector <int> wnum;	
	MovingAverage(int size){
		wsize = size;
	}
	double next(int val){
		if (wnum.size() < wsize){
			wnum.push_back(val);	
		}else if(wnum.size()==wsize){
			wnum.erase(wnum.begin()+0);
			wnum.push_back(val);
		}
		
		int snum = 0;
		for(int i=0;i<wnum.size();i++){
			snum+=wnum.at(i);	
		}
		
		double ret = 0;
		if (wnum.size() > 0){
		 ret = (double)snum/wnum.size();
		}
				
		return ret;		
	}
};

int main(){

	MovingAverage *ma = new MovingAverage(3);
	cout << "result:" << endl;
	cout<<ma->next(1)<<endl;
	cout<<ma->next(10)<<endl;
	cout<<ma->next(3)<<endl;
	cout<<ma->next(5)<<endl;
	return 0;
} 
