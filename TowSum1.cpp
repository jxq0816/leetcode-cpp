//
// Created by jiangxingqi on 2020/7/4.
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> map=new HashMap<>();
        for(i=0;i<num;i++){
            int x=target-nums[i];
            if(map.containsKey(x)){
                return new int[]{map.get(x),i};
            }
            map.put(nums[i],i);
        }

    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}