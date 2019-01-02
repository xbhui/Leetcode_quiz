#include <stdiod>

using namespace std;


class Solution (){
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target){
		if(matrix == null ) return false;		
				
			
	}

	
	bool help(int[][] M, int top, int bottom,int left,int right,int target){
		if(left > right|| top > bottom) return false;
			
		int midRow = top + (bottom - top)/2;
		int midCol = left + (right - left)/2;

		int can = M[midRow][midCol];
		if(can == target) return ture;

		if(can < target) return help(M,top,midRow-1,left,right,target)||
							   	help(M,midRow ,bottom ,left ,midCol-1,target);

		return help(M,left,rowCol,,midRow,target)||
			   help(M,left,right,midRow+1,bottom,target);

	}
/*
	bool help(int[][] M, int left, int right,int top,int bottom,int target){
		
		if(left > right || top > bottom) {
			return false;
		}else if(target < matrix[up][left] || target > matrix[down][right]){
			return false;
		}		

		int mid = left + (right-left)/2;

		int row = up;
		while(row<=down && matrix[row][mid]<=target) {
			if(matrix[row][mid] == target){
				return true;
			}
			row++;
		}
	
		return help(left,up,mid-1,dow)|| help(mid+1, up, right, row-1);
	}
*/
};

int main(){

	return 0;
}
