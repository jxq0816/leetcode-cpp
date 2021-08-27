//
// Created by jiangxingqi on 2021/8/27.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void sortArray(vector<int>& nums){
        quickSort(nums,0,nums.size()-1);
    }
    void quickSort(vector<int>& nums,int l,int r){
        if(l<r){
            int mid=partition(nums,l,r);
            quickSort(nums,l,mid-1);
            quickSort(nums,mid+1,r);
        }
    }
    int partition(vector<int>& nums,int l,int r){
        int pivot=nums[l];
        while(l<r){
            while(l<r&&nums[r]>=pivot){
                r--;
            }
            nums[l]=nums[r];
            while(l<r&&nums[l]<=pivot){
                l++;
            }
            nums[r]=nums[l];
        }
        nums[l]=pivot;
        return l;
    }
};
int main(){
    Solution solution;
    vector<int> nums={3,2,1,1};
    solution.sortArray(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i];
    }
    cout<<endl;
}