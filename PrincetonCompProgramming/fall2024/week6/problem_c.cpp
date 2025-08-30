/*
https://codeforces.com/group/hNnRWqFua0/contest/561424/problem/C

Solved? YES
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <unordered_map>

typedef long long ll;

using namespace std;

int main()
{
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        vector<string> board(8, string(8, ' '));
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                cin >> board[j][k];
            }
        }

        bool found = false;
        for (int j = 0; j < 8; j++)
        {
            bool row = true;
            for (int k = 0; k < 8; k++)
            {
                if (board[j][k] != 'R')
                {
                    row = false;
                }
            }
            if (row)
            {
                cout << 'R' << endl;
                found = true;
                break;
            }
        }

        if (found)
        {
            continue;
        }
        for (int j = 0; j < 8; j++)
        {
            bool col = true;
            for (int k = 0; k < 8; k++)
            {
                if (board[k][j] != 'B')
                {
                    col = false;
                }
            }
            if (col)
            {
                cout << 'B' << endl;
                found = true;
                break;
            }
        }
    }
}