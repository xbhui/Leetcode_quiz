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

      
      int f_cost = cost[0];
      int s_cost = cost[1];
      int f_ca = 0;
      int s_ca = 0;
      int f_start_id = 0;
      int s_start_id = 0;

      int t_ca = 0;
      int t_ca_id = 0;

      if(f_cost+cost[1]>f_cost+cost[2]){
          f_ca = f_cost+cost[2];
          f_start_id = 2;
      }else{
          f_start_id = 1;
          f_ca = f_cost+cost[1];
      }

      if(s_cost+cost[2]>s_cost+cost[3]){
          s_ca = s_cost+cost[3];
          s_start_id = 3;
      }else{
          s_ca = s_cost+cost[2];
          s_start_id = 2;
      }

      if(f_ca<s_ca){
        t_ca_id = f_start_id;
      }else{
        t_ca_id = s_start_id;
      }

      int total = 0;
      for(int i=t_ca_id;i<cost.size()-1;i++){
        //total+=cost[i]<cost[i+1]?cost[i]
        if(cost[i]<cost[i+1]){
          total+=cost[i];
        }else{
          total+=cost[i+1];
          i++;
        }
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
