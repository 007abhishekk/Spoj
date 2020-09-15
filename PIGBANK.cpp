#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N = 1e4 + 5;
ll dp[N];
int main(){
    int t;cin >> t;
    while(t--){
        int x, n, m;
        cin >> x;
        cin  >> n;
        n -= x;
        cin >> m;
        ll v[m], w[m];
        for(int i = 0; i < m; ++i){
            cin >> v[i] >> w[i];
        }
        for(int i = 0; i <= n; ++i)
            dp[i] = INT_MAX;
        for(int i = 0; i < m; ++i)
            dp[w[i]] = min(dp[w[i]], v[i]);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < m; ++j){
                if(i - w[j] >= 0)
                    dp[i] = min(dp[i], dp[i-w[j]] + v[j]);
            }
        }
        if(dp[n] >= INT_MAX){
            puts("This is impossible.");
        }
        else{
            cout << "The minimum amount of money in the piggy-bank is " << dp[n] << ".\n";
        }
    }
}