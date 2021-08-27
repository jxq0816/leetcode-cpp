#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==-1){
            if(dividend<=INT_MIN){
                return INT_MAX;
            }else{
                return -dividend;
            }
        }
        if(divisor==1){
            return dividend;
        }
        int sign=1;
        if((dividend>0&&divisor<0)||(dividend<0&&divisor>0)){
            sign=-1;
        }
        dividend=-abs(dividend);
        divisor=-abs(divisor);
        cout<<dividend<<endl;
        cout<<divisor<<endl;
        int rs = div(dividend,divisor);
        cout<<rs<<endl;
        if(sign>0){
            return rs;
        }
        return -rs;
    }
    int div(int a,int b){
        if(a>b){
            return 0;
        }
        int cnt=1;
        int tb=b;
        while(tb - a + tb >= 0){
            cnt=cnt+cnt;// 解翻倍
            tb=tb+tb;// 除数翻倍
        }
        return cnt+div(a-tb,b);
    }
};
int main() {
    Solution solution;
    cout <<solution.divide(-2147483648,2)<<endl;
    return 0;
}

//2147483647
//-2147483648