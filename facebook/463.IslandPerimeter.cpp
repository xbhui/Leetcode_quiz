#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	Solution(){
	}

	int islandPerimeter(vector< vector<int> >& grid){
		int perimeter = 0;
		for(int i=0;i<grid.size();i++){
			for(int j=0;j<grid[i].size();j++){
				if(grid[i][j]){
					perimeter += isCoast(grid,i-1,j);
					perimeter += isCoast(grid,i+1,j);
					perimeter += isCoast(grid,i,j-1);
					perimeter += isCoast(grid,i,j+1);
				}
			}
		}
		return perimeter;
	}

	int isCoast(vector< vector<int> >& grid,int i,int j){
		if(i<0 || j<0||i>=grid.size()||j>=grid[i].size()){
			return 1;
		}
		return grid[i][j] == 1?0:1;
	}
};
	
int main(){
	vector<int> v1;
	v1.push_back(0);
	v1.push_back(1);
	v1.push_back(0);
	v1.push_back(0);

	vector<int> v2;
	v2.push_back(0);
	v2.push_back(1);
	v2.push_back(0);
	v2.push_back(0);

	vector<int> v3;
	v3.push_back(1);
	v3.push_back(1);
    v3.push_back(1);
	v3.push_back(0);
	
	vector<int> v4;
	v4.push_back(0);
    v4.push_back(1);
	v4.push_back(0);
	v4.push_back(0);

	vector< vector<int> > h1;
	h1.push_back(v1);
	h1.push_back(v2);
	h1.push_back(v3);
	h1.push_back(v4);

	Solution so;
	int perimeter = so.islandPerimeter(h1);
	cout<< perimeter << endl;

	return 0;
}
