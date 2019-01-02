#include<iostream>
class Solution {
public:
 	bool canVisitAllRooms(vector<vector<int>& rooms> rooms){
	 	
		vector<bool> vist(rooms.size(),false);
		vist[0]=true;
		queue<int> q;
		q.push(0);
		int cnt=0;
		while(!q.empty){
			int u=q.front();
			q.pop();
			cnt++;
			if(cnt==rooms.size())
				return true;
			for(vector<int> v:rooms[u]){
				if(!vist[v]){
					vist[v]=true;
					q.push(v);
				}
			}
		}		


		return cnt==rooms.size();	
	}
};


int main()
{

	return 0;
}
