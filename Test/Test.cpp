// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }
        int length = 0, pos = 0;
        for (int i = 0; i < s.length() - 1 - (length >> 2); ++i) {//如果最后剩下的字符小于已知回文子串最大长度的一半，则没有必要继续遍历
            int j = i + 1;
            int k = i;
            int l_length = 0;
            while (j < s.length() && k >= 0) {//判断当前回文子串长度
                if (s[j] == s[k]) {
                    l_length += 2;
                    if (l_length > length) {
                        length = l_length;
                        pos = k;
                    }
                    ++j;
                    --k;
                   // cout << length << endl;
                }
                else {
                    break;
                }
            }
        }
        //cout << pos << "   " << length << endl;
        if (s.length() <= 2) {
            return s.substr(pos,length);
        }
        for (int i = 1; i < s.length() - 1 - ((length - 1) >> 2); ++i) {
            int j = i + 1;
            int k = i - 1;
            int l_length = 1;
            while (j <= s.length() && k >= 0) {//判断当前最大回文子串长度
                if (s[j] == s[k]) {
                    l_length += 2;
                    if (l_length > length) {
                        length = l_length;
                        pos = k;
                    }
                    ++j;
                    --k;
                }
                else {
                    break;
                }
            }
        }
        return s.substr(pos,length);
    }
};
int main()
{
    Solution s;
    string a = "cbbdbbd";
    std::cout << s.longestPalindrome(a);
}