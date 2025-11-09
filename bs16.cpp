//  Koko Eating Bananas

// for leetcode
#include<iostream>
using namespace std;
class Solution {
private:
    int findmax(vector<int>& piles){
        int maxi=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }   

    long long calculatehours(vector<int>& piles , int mid){
        long long totalh=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            // integer ceiling: (p + mid - 1) / mid
            totalh += ( (long long)piles[i] + mid - 1 ) / mid;
        }
        return totalh;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=findmax(piles);
        while(low <= high){
            int mid=low+(high-low)/2;
            long long totalhours=calculatehours(piles, mid);
            if(totalhours <= h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};

// for gfg

class Solution {
  private:
    int findmax(vector<int>&arr){
        int maxi=INT_MIN;
        int n=arr.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
    
    int calculateh(vector<int>&arr , int mid){
        
        long long totalh=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            totalh += ceil((double)arr[i]/(double)mid);
        }
        return totalh;
    }
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low=1;
        int high= findmax(arr);
        while(low <= high){
            int mid= low+(high-low)/2;
            int totalhour=calculateh(arr,mid);
            if(totalhour<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};

