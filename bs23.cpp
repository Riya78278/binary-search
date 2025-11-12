// Aggressive Cows
#include<iostream>
using namespace std;


class Solution {
  private:
    int canweplace(vector<int>&stalls,int dist,int cow){
        int n=stalls.size();
        int countcow=1;
        int lastcow=stalls[0];
        for(int i=0;i<n;i++){
            if(stalls[i]-lastcow>=dist){
                countcow++;
                lastcow=stalls[i];
            }
            if(countcow >= cow){
                return true;
            }
        }
        return false;
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0];
        while(low <= high){
            int mid=low+(high-low)/2;
            if(canweplace(stalls,mid,k)==true){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};