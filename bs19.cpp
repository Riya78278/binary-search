//  Find the Smallest Divisor Given a Threshold
#include <iostream>
using namespace std;

class Solution {
private:
    int sumD(vector<int>& nums, int mid){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+ceil((double)(nums[i])/(double)(mid));
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high= *max_element(nums.begin(),nums.end());
        while(low <= high){
            int mid= low+(high-low)/2;
            int ans=sumD(nums,mid);
            if(ans <= threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;

    }
};