/* ----------------------------------------------------- */
/* EncodeAndDecodeStrings.cpp                            */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Encode and Decode Strings */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string ans;
        for (int i = 0; i < strs.size(); i++)
        {
            ans = ans + to_string(strs[i].length()) + "#" + strs[i];
        }
        return ans;
    }

    vector<string> decode(string s)
    {
        vector<string> ans;
        int i = 0;
        while (i < s.length())
        {
            int j = i;
            while (s[j] != '#')
            {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            j++;
            ans.push_back(s.substr(j, length));
            i = j + length;
        }
        return ans;
    }
};

void checkAns(vector<string> input, Solution obj)
{
    string code = obj.encode(input);
    vector<string> ans = obj.decode(code);
    for (string i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    Solution obj;
    vector<string> input = {"neet", "code", "love", "you"};

    checkAns(input, obj);
    // should output as "neet code love you"

    input = {"we", "say", ":", "yes"};
    checkAns(input, obj);
    // should output as "we say : yes"
}