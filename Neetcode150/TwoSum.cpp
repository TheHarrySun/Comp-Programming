#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> seen;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            seen[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if (seen.count(temp) && i != (seen.find(temp))->second)
            {
                ans.push_back(i);
                ans.push_back((*seen.find(temp)).second);
                return ans;
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {3, 4, 5, 6};
    int target = 7;
    cout << obj.twoSum(nums, target)[0] << " " << obj.twoSum(nums, target)[1] << endl;
    // should output "0 1"

    nums = {4, 5, 6};
    target = 10;
    cout << obj.twoSum(nums, target)[0] << " " << obj.twoSum(nums, target)[1] << endl;
    // should output "0 2"

    nums = {5, 5};
    target = 10;
    cout << obj.twoSum(nums, target)[0] << " " << obj.twoSum(nums, target)[1] << endl;
    // should output "0 1"
}