/*
Problem link: https://codeforces.com/group/hNnRWqFua0/contest/555432/problem/A
*/

/*
Solved? YES
*/

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    cin >> n;

    unordered_map<string, string> netid_map;
    for (int i = 0; i < n; i++)
    {
        string command;
        string user;
        string pass;
        cin >> command >> user >> pass;
        if (command == "ADD")
        {
            netid_map[user] = pass;
        }
        if (command == "LOGIN")
        {
            if (netid_map.find(user) == netid_map.end() || netid_map[user] != pass)
            {
                cout << "ACCESS DENIED" << endl;
            }
            else
            {
                cout << "LOGGED IN" << endl;
            }
        }
    }
}