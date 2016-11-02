#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string addStrings(string num1, string num2) {
            char rev[5105];
            int i=0, p=0;
            int l1 = num1.size();
            int l2 = num2.size();
            while (i<l1 && i<l2) {
                int x = (num1[l1-i-1]-'0') + (num2[l2-i-1]-'0') + p;
                rev[i] = '0' + (x%10);
                p = x/10;
                i++;
            }
            while (i<l1) {
                int x = (num1[l1-i-1]-'0') + p;
                rev[i] = '0' + (x%10);
                p = x/10;
                i++;
            }
            while (i<l2) {
                int x = (num2[l2-i-1]-'0') + p;
                rev[i] = '0' + (x%10);
                p = x/10;
                i++;
            }
            if (p>0) {
                rev[i] = '0' + p;
                p=0;
                i++;
            }
            char result[5105];
            for (int k=i-1; k>=0; k--) {
                result[i-k-1] = rev[k];
            }
            result[i]='\0';
            return string(result);
        }
};

int main() {
    Solution s;
    cout << s.addStrings("123", "345") << endl;
    cout << s.addStrings("1", "345") << endl;
    cout << s.addStrings("123", "3") << endl;
}
