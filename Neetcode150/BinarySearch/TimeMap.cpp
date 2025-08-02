/* ----------------------------------------------------- */
/* TimeMap.cpp                                           */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Time Based Key-Value Store */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class TimeMap
{
public:
    unordered_map<string, map<int, string>> keys;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        keys[key].insert({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        auto it = keys[key].upper_bound(timestamp);
        if (it == keys[key].begin())
        {
            return "";
        }
        else
        {
            return prev(it)->second;
        }
    }
};

int main()
{
    TimeMap timemap = TimeMap();
    timemap.set("alice", "happy", 1);
    cout << timemap.get("alice", 1) << endl;
    cout << timemap.get("alice", 2) << endl;
    timemap.set("alice", "sad", 3);
    cout << timemap.get("alice", 3) << endl;
}