/*
https://codeforces.com/group/hNnRWqFua0/contest/555432/problem/E

Solved? YES
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>

typedef long long ll;

using namespace std;

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    ll ops[m][3];
    for (int i = 0; i < m; i++)
    {
        cin >> ops[i][0] >> ops[i][1] >> ops[i][2];
    }
    ll queries[k][2];
    for (int i = 0; i < k; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<ll> diff(m + 2, 0);
    for (int i = 0; i < k; i++)
    {
        diff[queries[i][0]] += 1;
        diff[queries[i][1] + 1] -= 1;
    }

    for (int i = 1; i < m + 2; i++)
    {
        diff[i] += diff[i - 1];
    }

    vector<ll> diff_ans(n + 2, 0);
    for (int i = 0; i < m; i++)
    {
        diff_ans[ops[i][0]] += diff[i + 1] * ops[i][2];
        diff_ans[ops[i][1] + 1] -= diff[i + 1] * ops[i][2];
    }
    for (int i = 1; i < n + 2; i++)
    {
        diff_ans[i] += diff_ans[i - 1];
    }

    for (int i = 1; i < n + 1; i++)
    {
        array[i - 1] += diff_ans[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << array[i] << " ";
    }
    cout << array[n - 1] << endl;
}
