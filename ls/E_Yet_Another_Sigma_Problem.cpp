#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];

int idx=0;
int cnt[N];
int son[N][26];
void cr(string s)
{
    int p=0;
    for(int i=0;i<s.size();i++)
    {
        int u=s[i]-'a';
        if(son[p][u]==0)
        {
            son[p][u]=++idx;
        }
        p=son[p][u];
        cnt[p]++;
    }
    
    // cnt[p]++;
}
int ans = 0;

void cz(string s)
{
    int p=0;
    for(int i=0;i<s.size();i++)
    {

        int u=s[i]-'a';
        p=son[p][u];
        ans += cnt[p] - 1;
    }
}

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        cr(s);
        cz(s);
        // cout << ans << endl;
    }
    cout << ans << endl;








}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}