#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    long pow(long x, long n){
        long res = 1;
        while(n>0){
            if(n%2==1){
                res=res*x;
                x=x-1;
            }else{
                x=x*x;
                n=n/2;
            }
        }
        return res;
    }
public:
    int countGoodNumbers(long long n) {
        int even=0, odd=0;
        if(n%2==1){
            even = (n/2)+1;
            odd = n/2;
        }else{
            even=n/2;
            odd=n/2;
        }

        return pow(odd, 4) * pow(even, 5);
    }
};
int main() {
    Solution sol;
    cout << sol.countGoodNumbers(1) << endl;  // 5
    cout << sol.countGoodNumbers(2) << endl;  // 20
    cout << sol.countGoodNumbers(4) << endl;  // 400
}
