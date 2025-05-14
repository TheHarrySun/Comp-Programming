/*
Problem Link: https://codeforces.com/group/hNnRWqFua0/contest/551614/problem/E

Description:
A permutation is an array consisting of n distinct integers from 1
to n in arbitrary order. For example, [2,3,1,5,4] is a permutation,
but [1,2,2] is not a permutation (2 appears twice in the array) and
[1,3,4] is also not a permutation (n=3 but there is 4 in the array).

You are given a permutation of 1,2,…,n, [a1,a2,…,an]. For integers i,
j such that 1 ≤ i < j ≤ n, define mn(i,j) as min_{k=i}^{j} a_k, and
define mx(i,j) as max_{k=i}^{j} a_k.

Let us build an undirected graph of n vertices, numbered 1 to n. For
every pair of integers 1 ≤ i < j ≤ n, if mn(i,j)=a_i and mx(i,j)=a_j
both holds, or mn(i,j)=a_j and mx(i,j)=a_i both holds, add an undirected
edge of length 1 between vertices i and j.

In this graph, find the length of the shortest path from vertex 1 to
vertex n. We can prove that 1 and n will always be connected via some
path, so a shortest path always exists.

Input
Each test contains multiple test cases. The first line contains the
number of test cases t (1 ≤ t ≤ 5⋅10^4). Description of the test cases
follows.

The first line of each test case contains one integer n (1 ≤ n ≤ 2.5⋅10^5).

The second line of each test case contains n integers a_1, a_2, …, a_n
(1 ≤ a_i ≤ n). It's guaranteed that a is a permutation of 1, 2, …, n.

It is guaranteed that the sum of n over all test cases does not exceed
5⋅10^5.

Output
For each test case, print a single line containing one integer — the
length of the shortest path from 1 to n.
*/

/*
Solved? No
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll distance(ll n, vector<ll> permutation)
{
}

int main(void)
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll length;
        cin >> length;
        vector<ll> permutation(length);
        for (ll j = 0; j < length; j++)
        {
            cin >> permutation[j];
        }
        cout << distance(length, permutation) << endl;
    }
}