#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    int num;
    cin >> num;
    getline(cin, line);
    for (int i = 0; i < num; i++)
    {
        int ans = 0;
        for (int j = 0; j < 10; j++)
        {
            getline(cin, line);
            for (int k = 0; k < 10; k++)
            {
                if (line[k] == 'X')
                {
                    ans += min(min(j, 9 - j), min(k, 9 - k)) + 1;
                }
            }
        }
        cout << ans << endl;
    }
}