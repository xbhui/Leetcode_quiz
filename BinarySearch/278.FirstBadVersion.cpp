#include <iostream>

using namespace std;

bool isBadVersion(int version);

class Solution{
  public:
    int firstBadVersion(int n) {
      int left=1;
      int right=n;
      while(left<right){
            int mid = left + (right-left)/2;
            cout<< "isBadVersion:" <<mid<<endl;
            if(isBadVersion(mid)){

              right = mid;
            }else{
              left = mid+1;
            }
      }
      return left;
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
