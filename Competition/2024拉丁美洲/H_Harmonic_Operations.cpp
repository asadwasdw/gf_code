#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int n,m;
string s;
pair<char, int> a[N];
ll sum[2][N];
void solve()
{
    cin >> s;
    n = s.size();
    cin >> m;
    for(int i=1; i<=m; ++i)cin >> a[i].first >> a[i].second;
    int cha = 0;
    {
        string t = s + s;
        vector<int> nx(t.size());
        for(int i=1; i<t.size(); ++i){
            int j = nx[i-1];
            while(j > 0 && t[i] != t[j])j = nx[j-1];
            if(t[i] == t[j])++j;
            nx[i] = j;
        }
        for(int i=0; i<t.size(); ++i){
            if(nx[i] >= n){
                cha = i - n + 1;
                break;
            }
        }
    }
    
    int rcha = 0;
    {
        string t = s;
        reverse(t.begin(), t.end());
        t = s + t + t;
        vector<int> nx(t.size());
        for(int i=1; i<t.size(); ++i){
            int j = nx[i-1];
            while(j > 0 && t[i] != t[j])j = nx[j-1];
            if(t[i] == t[j])++j;
            nx[i] = j;
        }
        for(int i=n; i<t.size(); ++i){
            if(nx[i] >= n){
                rcha = i - n + 1 - n;
                break;
            }
        }
    }
    if(rcha == 0)rcha = -1;
    {
        int f = 0;
        for(int i=1; i<=m; ++i){
            auto [op, x] = a[i];
            if(op == 'I')sum[0][i] = sum[0][i-1], f = !f;
            if(op == 'L'){
                if(f)sum[0][i] = (sum[0][i-1] + x) % cha;
                else sum[0][i] = (sum[0][i-1] - x + cha) % cha;
            }
            if(op == 'R'){
                if(f)sum[0][i] = (sum[0][i-1] - x + cha) % cha;
                else sum[0][i] = (sum[0][i-1] + x) % cha;
            }
        }
        f = 1;
        for(int i=1; i<=m; ++i){
            auto [op, x] = a[i];
            if(op == 'I')sum[1][i] = sum[1][i-1], f = !f;
            if(op == 'L'){
                if(f)sum[1][i] = (sum[1][i-1] + x) % cha;
                else sum[1][i] = (sum[1][i-1] - x + cha) % cha;
            }
            if(op == 'R'){
                if(f)sum[1][i] = (sum[1][i-1] - x + cha) % cha;
                else sum[1][i] = (sum[1][i-1] + x) % cha;
            }
        }
    }
    map<int, int> mp1[2], mp2[2];
    mp1[0][0]++;mp2[1][0]++;
    ll res = 0;
    int f1 = 0, f2 = 1;
    for(int i=1; i<=m; ++i){
        auto [op, x] = a[i];
        if(op == 'I')f1 = !f1, f2 = !f2;
        if(f1 == 0){
            res += mp1[0][sum[0][i]];
            if(rcha != -1)
            res += mp1[1][(sum[0][i] - rcha + cha) % cha];
        }
        else{
            res += mp2[0][sum[1][i]];
            if(rcha != -1)
            res += mp2[1][(sum[1][i] - rcha + cha) % cha];
        }
        mp1[f1][sum[0][i]]++;
        mp2[f2][sum[1][i]]++;
    }
    cout << res << endl;
    for(int i=1; i<=m; ++i){
        cout << sum[0][i] << ' ' << sum[1][i] << endl;
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