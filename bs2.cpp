// Ceil The Floor
#include <iostream>
using namespace std;
class Solution {
  private:
    int floorIndex(int x, vector<int>& arr){
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int ceilIndex(int x, vector<int>& arr){
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {

        // ✅ MUST SORT for binary search
        sort(arr.begin(), arr.end());

        int f = floorIndex(x, arr);
        int c = ceilIndex(x, arr);

        // return element values, not indices
        int floorVal = (f == -1 ? -1 : arr[f]);
        int ceilVal  = (c == -1 ? -1 : arr[c]);

        return {floorVal, ceilVal};
    }
};
