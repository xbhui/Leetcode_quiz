#include "stdio.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numIslands(vector< vector<char> >& grid) {
		
		int num=0;
		for(int i=0;i<grid.size();++i){	
			for(int j=0;j<grid[i].size();++j){
				if(grid[i][j]=='1'){
					dfs(grid,i,j);
					num++;
				}
			}
		}

		return num;
	}

	void dfs(vector< vector<char> >& grid,int i,int j){

		if(i<0||j<0||i>grid.size()-1|| j>grid[i].size()-1){
			return;
		}
	
		if(grid[i][j]=='1'){ 
			cout <<"i:"<<i<<";j"<<j<<endl;	
			grid[i][j] = 0;
			dfs(grid,i,j-1);
			dfs(grid,i,j+1);
			dfs(grid,i-1,j);
			dfs(grid,i+1,j);
		}	
		return ;
	}

}; 

int main(){
	
	Solution so;
	vector<char> row0;
	row0.push_back('1');
	row0.push_back('1');
	row0.push_back('1');
	row0.push_back('1');
	row0.push_back('0');
	
	vector<char> row1;
	row1.push_back('1');
	row1.push_back('1');
	row1.push_back('0');
	row1.push_back('1');
	row1.push_back('0');

	vector<char> row2;
	row2.push_back('1');
	row2.push_back('1');
	row2.push_back('0');
	row2.push_back('0');
	row2.push_back('0');

	vector<char> row3;
	row3.push_back('0');
	row3.push_back('0');
	row3.push_back('0');
	row3.push_back('0');
	row3.push_back('0');

	vector< vector<char> > grid;
	grid.push_back(row0);
	grid.push_back(row1);
	grid.push_back(row2);
	grid.push_back(row3);

/*
	vector<char> row0;
	row0.push_back('1');
	row0.push_back('1');
	row0.push_back('0');
	row0.push_back('0');
	row0.push_back('0');
	
	vector<char> row1;
	row1.push_back('1');
	row1.push_back('1');
	row1.push_back('0');
	row1.push_back('0');
	row1.push_back('0');

	vector<char> row2;
	row2.push_back('0');
	row2.push_back('0');
	row2.push_back('1');
	row2.push_back('0');
	row2.push_back('0');

	vector<char> row3;
	row3.push_back('0');
	row3.push_back('0');
	row3.push_back('0');
	row3.push_back('1');
	row3.push_back('1');

	vector< vector<char> > grid;
	grid.push_back(row0);
	grid.push_back(row1);
	grid.push_back(row2);
	grid.push_back(row3);
*/
	int num = so.numIslands(grid);
	cout<<"num:"<<num<<endl;
	return 0;
}
