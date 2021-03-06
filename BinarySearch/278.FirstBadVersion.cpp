#include <iostream>

using namespace std;

bool isBadVersion(int version);

class Solution{
  public:
    int firstBadVersion(int n) {
        int minOneStepBelow = 0, minEndingHere = 0;
        for (int i = 2; i <= cost.size(); i++) {
          int curMin = min(minEndingHere + cost[i - 1], minOneStepBelow + cost[i - 2]);
          minOneStepBelow = minEndingHere;
          minEndingHere = curMin;
        }
        return minEndingHere;
    }
};

bool isBadVersion(int version){
   if(version>=4){
     return true;
   }
   return false;
}

int main(){
  Solution so;
  int badVersion = so.firstBadVersion(51);
  cout<< "badVersion:" <<badVersion<<endl;

  return 0;
}
