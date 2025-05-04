/*
Problem Link: https://codeforces.com/group/hNnRWqFua0/contest/553384/problem/B

Description:
It's the year 2050 and Princeton now offers exactly N CS courses, ranging
from protonic computing to a topics class on how to prove P=NP. To keep
track of all the courses, Princeton decided to give each course a unique
course number, which is an integer between 1 and 10^9.

Meilin is trying to pick courses for the Spring semester of 2100, but is
having a little trouble keeping track of all the course numbers. So she
decided to ask you for help. Given a sorted list of the N course numbers
and a sequence of Q integers, for each one determine if there is a course
with that number.

Input
The first line contains two integers, N and Q (1≤N,Q≤100,000) – the size
of the sequence and the number of operations you should support.

Then follows on line with N space separated integers (0≤Si≤10^9) the list
of course numbers. This list of integers will always be in sorted order.

Then follow Q lines, each in one containing one integer between 0 and 10^9.

Output
Print Q lines, the ith of which should be "NO COURSE FOR YOU" if there
is no course with course number equal to the ith integer, or "COURSE"
otherwise.
*/

/*
Solved? Yes
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(void)
{
    ll N;
    ll Q;
    cin >> N >> Q;
    vector<ll> courses(N);
    for (int i = 0; i < N; i++)
    {
        cin >> courses[i];
    }
    for (int i = 0; i < Q; i++)
    {
        ll course;
        cin >> course;
        ll first = 0;
        ll last = N - 1;
        bool found = false;
        while (first <= last)
        {
            ll mid = first + (last - first) / 2;
            if (courses[mid] == course)
            {
                cout << "COURSE" << endl;
                found = true;
                break;
            }
            else if (courses[mid] < course)
            {
                first = mid + 1;
            }
            else
            {
                last = mid - 1;
            }
        }
        if (!found)
        {
            cout << "NO COURSE FOR YOU" << endl;
        }
    }
}