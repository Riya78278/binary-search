// Find the Nth root of a number using binary search
#include <iostream>
using namespace std;

class Solution {
  private:
    int rootans(int mid, int n){
        long long ans = 1;
        while(n > 0){
            if(n % 2 == 1){
                ans = ans * mid;
                n = n - 1;
            } else {
                mid = mid * mid;
                n = n / 2;
            }
        }
        return ans;
    }

  public:
    int nthRoot(int n, int m) {
        if(m == 0) return 0;     // FIX for edge case

        int low = 1;
        int high = m;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int midn = rootans(mid, n);

            if(midn == m){
                return mid;
            }
            else if(midn < m){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};
