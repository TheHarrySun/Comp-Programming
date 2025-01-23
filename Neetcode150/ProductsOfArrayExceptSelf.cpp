#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = 1;
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        vector<int> suffix(n);
        suffix[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }
        vector<int> ans(n);
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = prefix[i] * suffix[i];
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

    vector<int> nums = {1, 2, 4, 6};
    vector<int> ans = obj.productExceptSelf(nums);
    printAns(ans);
    // should output "48 24 12 8"

    nums = {-1, 0, 1, 2, 3};
    ans = obj.productExceptSelf(nums);
    printAns(ans);
    // should output "0 -6 0 0 0"
}