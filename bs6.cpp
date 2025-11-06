// Implement Lower Bound
#include <iostream>
using namespace std;

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int lp=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
        return lp;
    }
};
