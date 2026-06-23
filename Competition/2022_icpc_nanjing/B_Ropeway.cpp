#include<bits/stdc++.h>
// #define int long long
using namespace std;
typedef long long ll;

const int N=1e6+10;
const int mod=998244353;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
typedef pair<ll,int>PII;
//vector<vector<int>>edg(N);


int a[N];
ll dp[N],gp[N];

void solve()
{
    int n, k; cin >> n >> k;

    for(int i = 1; i <= n; i ++) 
    {
        cin >> a[i];
        dp[i] = INFll;
    }
    a[n + 1] = 0;
    dp[0] = dp[n + 1] = gp[0] = gp[n + 1] = INFll;
    dp[0] = dp[n + 2] = gp[0] = gp[n + 2] = INFll;

    string s; cin >> s; s = " " + s;

    {
        dp[0] = 0;
        priority_queue<PII,vector<PII>, greater<PII>> q;
        q.push({0, 0}); 
        for(int i = 1; i <= n + 1; i ++) {
            while(q.size() && q.top().second < i - k) q.pop();
            dp[i] = q.top().first + a[i];
            if(s[i] == '1') 
                while(q.size()) q.pop();
            q.push({dp[i],i});
        }
    }


    {
        gp[n + 1] = 0;
        priority_queue<PII,vector<PII>, greater<PII>> q;
        q.push({0 , n + 1}); 
        for(int i = n; i >= 0; i --) {
            while(q.size() && q.top().second > i + k) q.pop();
            gp[i] = q.top().first;

            if(s[i] == '1') 
                while(q.size()) q.pop();

            q.push({gp[i] + a[i], i});
        }
    }


    
    int m;
    cin >> m;
    while(m --) {
        int x, y;
        cin >> x >> y;

        priority_queue<PII,vector<PII>, greater<PII>> q;
        for(int i = max(0, x - k - 1); i < x; i ++) {
            if(s[i] == '1') while(q.size()) q.pop();
            q.push({dp[i], i});
        }
        int T = a[x];
        a[x] = y;
        ll ans = INFll;
        for(int i = x; i <= min(n + 1, i + k + 1); i ++) {
            while(q.size() && q.top().second < i - k) q.pop();
            ll t = q.top().first + a[i];
            ans = min(t + gp[i], ans);
               if(s[i] == '1') 
                while(q.size()) q.pop();
            q.push({t, i});
        }
        cout << ans << endl;
        a[x] = T;
    }
}


signed main()
{
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}