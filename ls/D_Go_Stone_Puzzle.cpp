#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];


void solve()
{
    cin >> n;
    n += 2;
    string s, t;
    cin >> s >> t;

    if(s == t) {
        cout << "0";
        return;
    }
    t = t + "..";
    s = s + "..";
    queue<PII>q;
    map<string,int>st;
    q.push({s, 1});
    
    while(q.size()) {
        auto [u,dis] = q.front();q.pop();
        if(st[u]) continue;
        st[u] = 1;
        // cout << u << endl;
        int wz = 0;
        for(int i = 0; i < n; i ++) {
            if(u[i] == '.') {
                wz = i;
                break;
            }
        }

        for(int i = 0; i < n - 1; i ++) {
            if(u[i] != '.' && u[i + 1] != '.') {
                string v = u;
                v[i] = v[i + 1] = '.';
                v[wz] = u[i]; 
                v[wz + 1] = u[i + 1];
                if(st[v]) continue;
                q.push({v,dis + 1});
                if(v == t) {
                    cout << dis;
                    return;
                }
            }
        }
    }
    cout << "-1";








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