#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        bool isAdditiveNumber(string num) {
            int l = num.size();
            for (int i=0; i<(l-1)/2; ++i) {
                for (int j=i+1; j<l; ++j) {
                    if (solve(num, 0, i, j)) {
                        return true;
                    }
                }
            }
            return false;
        }
        bool solve(string num, int p1, int p2, int p3) {
            int l1 = p2-p1+1;
            int l2 = p3-p2;
            int x = max(l1, l2);
            if (p3+x>num.size()) {
                return false;
            }
            for (int i=0; i<2; i++) {
                int p4 = p3+x+i;
                if (check(num, p1, p2, p3, p3+x+i) && p4<num.size()) {
                    if (p4 == num.size()-1) {
                        return true;
                    } else {
                        return solve(num, p2+1, p3, p4);
                    }
                }
            }
            return false;
        }
        bool check(string num, int p1, int p2, int p3, int p4) {
            if ((p2-p1+1>1 && num[p1]=='0') || (p3-p2>1&&num[p2+1]=='0') || (p4-p3>1&&num[p3+1]=='0')) {
                return false;
            }
            int carry = 0;
            int x1 = p2, x2 = p3;
            string sum;
            for (; p1<=x1 && p2<x2; x1--, x2--) {
                int temp = (num[x1]-'0') + (num[x2]-'0') + carry;
                carry = temp/10;
                sum.push_back((temp%10)+'0');
            }
            for (; p1<=x1 ; x1--) {
                int temp = (num[x1]-'0') + carry;
                carry = temp/10;
                sum.push_back((temp%10)+'0');
            }
            for (; p2<x2 ; x2--) {
                int temp = (num[x2]-'0') + carry;
                carry = temp/10;
                sum.push_back((temp%10)+'0');
            }
            if (carry==1) {
                sum.push_back('1');
            }
            string res;
            for(int i=sum.size()-1;i>=0;i--){
                res.push_back(sum[i]);
            }
            if (res.size() == p4-p3) {
                for (int i=0; i<res.size(); i++) {
                    if (res[i] != num[p3+i+1]) {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }
        int max(int a, int b) {
            return (a>b)?(a):(b);
        }

};
int main() {
    Solution s ;
    cout << s.isAdditiveNumber("1991001990") << endl;
    cout << s.isAdditiveNumber("101") << endl;
}
