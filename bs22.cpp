// Allocate Minimum Pages
#include <iostream>
#include <algorithm>
#include<numeric>

using namespace std;


class Solution {
  private:
    int countstudents(vector<int>&arr,int pages){
        int student=1;
        long long pagesstudent=0;
        for(int i=0;i<arr.size();i++){
            if(pagesstudent+arr[i]<=pages){
                pagesstudent +=arr[i];
            }
            else{
                student++;
                pagesstudent=arr[i];
            }
        }
        return student;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n) return -1;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low <= high){
            int mid=low+(high-low)/2;
            int student=countstudents(arr,mid);
            if(student> k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};