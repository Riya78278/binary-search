// Minimum Number of Days to Make m Bouquets
#include<iostream>
using namespace std;

class Solution {
private:
    bool possible(vector<int>& bloomDay,int mid,int m,int k){
        int count=0;
        int ans=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<= mid){
                count++;

            }
            else{
                ans +=(count/k);
                count=0;
            }
        }
        ans +=(count/k);
        return ans>=m;
    }  
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val= m* 1LL * k *1LL;
        if(val>bloomDay.size()) return -1;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int low=mini;
        int high=maxi;
        while(low <= high){
            int mid= low+(high-low)/2;
            if(possible(bloomDay,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};