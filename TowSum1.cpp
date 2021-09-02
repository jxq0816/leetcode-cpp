//
// Created by jiangxingqi on 2020/7/4.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> map;
        for(int i=0;i<nums.size();i++){
            auto it = map.find(target - nums[i]);
            if (it != map.end()) {
                return {it->second, i};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};
int main() {
    Solution solution;
    vector<int> nums= {2,7,11,15};
    int target = 9;
    vector<int> rs=solution.twoSum(nums,target);
    for(int i:rs){
        cout<<i<<",";
    }
    cout<<endl;
    return 0;
}