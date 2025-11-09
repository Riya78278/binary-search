// Square Root
#include<iostream>
using namespace std;

class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int low=1;
        int high=n;
        int ans=1;
        while(low <= high){
            long long mid=low+(high-low)/2;
            long long a=mid*mid;
            if(a<=n){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};