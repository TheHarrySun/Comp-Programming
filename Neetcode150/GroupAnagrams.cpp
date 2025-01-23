#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> words;
        for (int i = 0; i < strs.size(); i++)
        {
            vector<int> count(26, 0);
            for (char s : strs[i])
            {
                count[s - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++)
            {
                key = key + ',' + to_string(count[i]);
            }
            words[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto &pair : words)
        {
            ans.push_back(pair.second);
        }
        return ans;
    }
};

void printAns(vector<vector<string>> ans)
{
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution obj;
    vector<string> strs = {"act", "pots", "tops", "cat", "stop", "hat"};
    printAns(obj.groupAnagrams(strs));
    // should group "act cat", "pots tops stop", and "hat"

    strs = {"x"};
    printAns(obj.groupAnagrams(strs));
    // should group "x"

    strs = {""};
    printAns(obj.groupAnagrams(strs));
    // should just be ""
}