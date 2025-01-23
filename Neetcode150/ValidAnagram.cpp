#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, int> countS;
        unordered_map<char, int> countT;
        for (int i = 0; i < s.length(); i++)
        {
            countS[s[i]]++;
            countT[t[i]]++;
        }
        return countS == countT;
    }
};

int main()
{
    Solution obj;
    string s1 = "racecar";
    string t1 = "carrace";
    cout << obj.isAnagram(s1, t1) << endl;
    // should output 1 for true

    string s2 = "jar";
    string t2 = "jam";
    cout << obj.isAnagram(s2, t2) << endl;
    // should output 0 for false
}