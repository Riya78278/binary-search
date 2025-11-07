// Number of occurrence
#include<iostream>
using namespace std;

class Solution {
  private:
    int first(vector<int>&arr,int target, int n){
        int low=0;
        int high=n-1;
        int ff=-1;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                ff=mid;
                high=mid-1;
            }
            else if(arr[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ff;
        
    }
    int last(vector<int>&arr,int target ,int n){
        int low=0;
        int high=n-1;
        int last=-1;
        while(low <= high){
            int mid=low +(high-low)/2;
            if(arr[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(arr[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return last;
    }
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int f=first(arr,target,n);
        int l=last(arr,target,n);
        if(f==-1) return 0;
        int anss=l -f +1;
        return anss;
        
        
    }
};
