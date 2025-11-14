// Split Array Largest Sum or The Painter's Partition Problem-II (leetcode , gfs )

#include <iostream>
#include<numeric>

using namespace std;
class Solution {
private:
    int countstudent(vector<int>&nums, int pages){
        int student=1;
        int pagesofs=0;
        for(int i=0;i<nums.size();i++){
            if(pagesofs +nums[i] <= pages){
                pagesofs +=nums[i];
            }
            else{
                student++;
                pagesofs=nums[i];
            }
        }
        return student;
    }    
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        //sort(nums.begin(),nums.end());
        if(k>n) return -1;
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int student=countstudent(nums,mid);
            if(student > k){
                low=mid+1;

            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};

