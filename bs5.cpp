// Implement Upper Bound
#include <iostream>
using namespace std;
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int up=upper_bound(arr.begin(),arr.end(),target)-arr.begin();
        return up;
    }
};