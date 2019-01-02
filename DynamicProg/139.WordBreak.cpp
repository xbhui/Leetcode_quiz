#include "stdio.h"
#include <iostream>

using namespace std;

class Solution {
public:
	bool wordBreak(string s,vector<string>& wordDict){
		if(s.size()==0 || s==null) return true;
		vector<bool> dp;
		dp[0] = true;

		for(int i=0;i<s.size();i++){
			for(int j=0;j<=i;++j){

				string sub = s.substr(j,i+1);

				vector<string>::iterator it;
				it = find(wordDict.begin(),wordDict.end(),sub);
				if(dp[j]&&it!=wordDict.end()){
					dp[i+1] = true;
					break;
				}
			}

		}
		return dp[wordDict.size()];
	}
}

int main(){

	return 0;
}
