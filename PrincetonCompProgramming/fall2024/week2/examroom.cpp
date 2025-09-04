/*
Problem Link: https://codeforces.com/group/hNnRWqFua0/contest/551614/problem/A

Description:
It's 2050, and there are n students enrolled in COS126. As such, the
logistics of organizing the midterm exams for the class have become
really hard. This year, the n students will sit side by side on chairs
arranged in a long line. Student i will be sitting on a chair that is x_i
yards away from the beginning of the line.

Because we don't want students to sit too close to each other, you have
been tasked with determining the distance between the two closest students.
In other words, the minimum |x_i−x_j| over all i≠j.

Input
The first line of the input contains an integer n (2 ≤ n ≤ 10^5).

Then follows one line with n integers separated by spaces; the ith
corresponds to x_i (0 ≤ x_i ≤ 10^9).

Output
The output should contain a line with a single integer, the minimum
distance between any two students.
*/

/*
Solved? Yes!
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    vector<ll> distances(n);
    for (int i = 0; i < n; i++)
    {
        cin >> distances[i];
    }
    sort(distances.begin(), distances.end());

    ll min_dist = numeric_limits<ll>::max();
    for (int i = 0; i < n - 1; i++)
    {
        min_dist = min(min_dist, distances[i + 1] - distances[i]);
    }
    cout << min_dist << endl;
}