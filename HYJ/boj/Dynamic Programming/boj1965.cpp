#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<int> v(n, 0);
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (v[i] > v[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int m = 0;
    for (int i = 0; i < n; i++) {
        m = max(dp[i], m);
    }
    cout << m;

    return 0;
}
