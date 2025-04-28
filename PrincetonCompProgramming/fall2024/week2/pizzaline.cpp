#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int merge(vector<ll> &positions, int left, int right);

int main()
{
    ll n;
    cin >> n;
    vector<ll> positions(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> positions[i];
    }
    int output = merge(positions, 0, n - 1);
    cout << output << endl;
}

int merge(vector<ll> &positions, int left, int right)
{
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;
    int output = 0;
    output += merge(positions, left, mid);
    output += merge(positions, mid + 1, right);

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<ll> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = positions[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = positions[mid + 1 + j];
    }
    int i = 0, j = 0;
    int k = left;
    int inversions = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            positions[k] = L[i];
            i++;
            output += inversions;
        }
        else
        {
            positions[k] = R[j];
            j++;
            inversions++;
        }
        k++;
    }
    while (i < n1)
    {
        positions[k] = L[i];
        i++;
        k++;
        output += inversions;
    }
    while (j < n2)
    {
        positions[k] = R[j];
        j++;
        k++;
    }
    return output;
}