#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <vector>

using namespace std;

class Solution {

    public:
    Solution(){

    }
    int minCostClimbingStairs(vector<int>& cost) {
      int minOneStepBelow = 0, minEndingHere = 0;
      for (int i = 2; i <= cost.size(); i++) {
          int curMin = min(minEndingHere + cost[i - 1], minOneStepBelow + cost[i - 2]);
          minOneStepBelow = minEndingHere;
          minEndingHere = curMin;
      }
      return minEndingHere;
    }
};

int main(int argc, char const *argv[]) {

//  int values[] = {10, 15, 20};
  int values[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  vector<int> v;
  v.insert(v.begin(),values[0]);
  v.insert(v.begin()+1,values[1]);
  v.insert(v.begin()+2,values[2]);
  v.insert(v.begin()+3,values[3]);
  v.insert(v.begin()+4,values[4]);
  v.insert(v.begin()+5,values[5]);
  v.insert(v.begin()+6,values[6]);
  v.insert(v.begin()+7,values[7]);
  v.insert(v.begin()+8,values[8]);
  v.insert(v.begin()+9,values[9]);
  Solution so;
  cout << "Solution:" <<so.minCostClimbingStairs(v) << endl;
  return 0;
}
