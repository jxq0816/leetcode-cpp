//
// Created by jiangxingqi on 2021/8/24.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
    int randomized_partition(vector<int>& nums, int start, int end) {
        int pivot_index = rand() % (end - start + 1) + start;
        swap(nums[pivot_index],nums[start]);
        return partition(nums,start,end);
    }
    void quickSort(vector<int>& nums,int start,int end){
        if(start<end){
            int mid=randomized_partition(nums,start,end);
            cout<<"mid:"<<mid<<std::endl;
            quickSort(nums,start,mid-1);
            quickSort(nums,mid+1,end);
        }
    }
    int partition(vector<int>& nums,int start,int end){
        cout<<"start:"<<start<<"end:"<<end<<std::endl;
        int pivot=nums[start];
        cout<<"pivot:"<<pivot<<std::endl;
        while(start<end){
            while(start<end&&nums[end]>=pivot){
                end--;
            }
            nums[start]=nums[end];
            while(start<end&&nums[start]<=pivot){
                start++;
            }
            nums[end]=nums[start];
        }
        nums[start]=pivot;
        for(int i=0;i<nums.size();i++){
            cout<<nums[i];
        }
        cout<<std::endl;
        return start;
    }
};

int main() {
    vector<int> nums = {5,2,3,1};
    Solution solution;
    solution.sortArray(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i];
    }
    cout<<std::endl;
    return 0;
}