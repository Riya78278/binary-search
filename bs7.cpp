// First and Last Occurrences

#include <iostream>
using namespace std;

class Solution {
  private:
    int first(vector<int>&arr,int x, int n){
        int low=0;
        int high=n-1;
        int first=-1;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(arr[mid]==x){
                first=mid;
                high=mid-1;
            }
            else if(arr[mid]<x){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return first;
    }
    
    int last(vector<int>&arr,int x, int n){
        int low=0;
        int high=n-1;
        int last=-1;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(arr[mid]==x){
                last =mid;
                low=mid+1;
            }
            else if(arr[mid]<x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return last;
    }
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int f= first(arr,x,n);
        if(f==-1) return {-1,-1};
        int l= last(arr,x,n);
        return {f,l};
        
    }
};