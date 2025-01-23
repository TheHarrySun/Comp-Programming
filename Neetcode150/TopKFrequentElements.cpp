#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> count;
        vector<vector<int>> sizes(nums.size() + 1);

        for (int i = 0; i < nums.size(); i++)
        {
            count[nums[i]] += 1;
        }
        for (auto &entry : count)
        {
            sizes[entry.second].push_back(entry.first);
        }
        vector<int> ans;
        for (int i = sizes.size() - 1; i > 0; i--)
        {
            for (int j : sizes[i])
            {
                if (ans.size() == k)
                {
                    return ans;
                }
                ans.push_back(j);
            }
        }
        return ans;
    }
};

void printAns(vector<int> ans)
{
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    Solution obj;

    vector<int> nums = {1, 2, 2, 3, 3, 3};
    int k = 2;

    vector<int> ans = obj.topKFrequent(nums, k);
    printAns(ans);
    // should output 2 and 3

    nums = {7, 7};
    k = 1;

    ans = obj.topKFrequent(nums, k);
    printAns(ans);
    // should output 7
}