#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int rs=-1;
        int i,j;
        if(haystack==needle){
            return 0;
        }
        if(haystack.size()<needle.size()){
            return -1;
        }
        int block=needle.size();
        for(i=0;i<=haystack.size()-block;i++){
            int k=i;
            bool flag=true;
            cout <<"i="<<i<<endl;
            for(j=0;j<block;j++,k++){
                cout <<"j="<<j<<endl;
                if(haystack[k]!=needle[j]){
                    flag=false;
                    cout <<haystack[k]<<"不一致"<<needle[j]<<endl;
                    break;
                }
            }
            if(flag){
                rs=i;
                break;
            }
        }
        return rs;
    }
};

int main() {
    Solution solution;
    cout <<solution.strStr("aaa","aaaa")<< std::endl;
    return 0;
}