#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
string s,t;
int n;
int f[N][26];
int pos[26];
void solve()
{
    cin >> t >> s;
    cin >> n;
    int m = t.size();
    for(int i=0; i<m; ++i)pos[i] = s.size();
    for(int i=s.size()-1; i>=0; --i){
        for(int j=0; j<m; ++j)f[i][j] = pos[j];
        pos[t.find(s[i])] = i;
    }
    int len = INF;
    for(int j=0; j<m; ++j){
        int k = pos[j];
        int cnt = 0;
        ++cnt;
        while(k != s.size()){
            int mx = 0;
            ++cnt;
            for(int i=0; i<m; ++i)mx = max(mx, f[k][i]);
            k = mx;
        }
        len = min(len, cnt);
    }
    while(n--){
        string q;
        cin >> q;
        if(q.size() != len){
            cout << 0 << '\n';
            continue;
        }
        int k = s.size();
        bool res = false;
        for(int i=0; i<q.size(); ++i){
            if(i == 0)k = pos[t.find(q[i])];
            else{
                k = f[k][t.find(q[i])];
            }
            if(k == s.size()){
               res = true;
               break;
            }
        }
        cout << (res ? 1 : 0) << '\n';

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