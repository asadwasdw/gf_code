#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);
int idx=0;
int cnt[N * 10];
int son[N][30];
int cnt2[N * 10];
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
        
        cnt[p] = min(cnt[p], (int)s.size() - i);
        // cout << p << " - " << cnt[p] << endl;
        p=son[p][u];
    }
    cnt2[p]++;
    cnt[p] = 0;
}

int cz(string s)
{
    int ans = INFll;
    int p=0;
    bool ky = true;
    for(int i=0;i<s.size();i++)
    {
        int u=s[i]-'a';
            ans = min((int)s.size() - i  + cnt[p], ans);
        if(son[p][u]==0)
        {
            // cout << s.size() - i << " " << p <<  " "  << cnt[p] << endl;
            ky =false;
            break;
        }
        // if(son[p][u])cnt[son[p][u]] = min(cnt[son[p][u]], max(cnt[p] - 1,0));
        if(cnt2[p]) {
            ans = min(ans, (int)s.size() - i);
        }
        p=son[p][u];
    }
    if(ky)ans = min(cnt[p], ans);
    return ans;
}

void solve()
{
    memset(cnt, 0x3f, sizeof cnt);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        string s; cin >> s;
        int ans = min((int)s.size(), cz(s));
        cr(s);
        cout << ans << endl;
    }
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