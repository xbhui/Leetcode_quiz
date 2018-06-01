#include <iostream>
//#include <ext/hash_map>
//#include <ext/hashtable.h>
//#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
  int numJewelsInStones(string J, string S) {

      int num = 0;
      map<char,int> jmap;
      for(int i=0;i<J.size();i++){
        jmap.insert(std::pair<char, int>(J[i],1));
      }

      for(int j=0;j<S.size();j++){
        char s = S[j];
        map<char,int>::iterator it;
        it=jmap.find(s);
        if(it!=jmap.end()){
          num++;
        }
      }
      return num;
  }
};

int main(){


//  string J = "aA", S = "aAAbbbb";
  string J = "z", S = "ZZaz";
  Solution so;
  cout << "output:";
  cout << so.numJewelsInStones(J,S)<<endl;
  return 0;
}
