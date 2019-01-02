#include <iostream>
#include <queue>

using namespace std;

int main(){

	queue<int> q;
	int num;
	cout<<"Please enter some integers\n"; 
	do {
		cin>>num;
		q.push(num);
	}while(num);

	cout<<"q contains:";
	while(!q.empty()){
		cout<<q.front();
		q.pop();
	}
	cout<<'\n';
	
	return 0;
}
