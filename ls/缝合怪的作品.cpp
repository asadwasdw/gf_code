#include<bits/stdc++.h>
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
// int a[N];
vector<string>ss;
unordered_map<string,vector<int>>st;

void solve()
{
    cin >> n >> m;
    for(int i =1; i <= n; i ++) {
        string t;
        cin >> t;
        ss.push_back(t);
        st[t].push_back(i);
    }
    
    while(m --) {
        int op;
        string a,b;
        int x;
        cin >> op;
        if(op == 1) {
            cin >> a >> b;

            for(auto t : st[a]) {
                ss[t - 1] = b;
                st[b].push_back(t);
            }
            st[a].clear();
        }
        else {
            cin >> x >> b;

            vector<int>t;
            for(auto T : st[ss[x - 1]]) {
                if(T != x) t.push_back(T);
            }
            swap(st[ss[x - 1]], t);
            ss[x - 1] = b;
            st[b].push_back(x);
        }
    }

    for(auto t : ss) {
        cout << t << " ";
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