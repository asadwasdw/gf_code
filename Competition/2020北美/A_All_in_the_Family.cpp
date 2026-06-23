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
string s,t;
map<string, int> mp;
int idx;
int d[N];
vector<int> g[N];
int fa[N], dep[N];

void dfs(int u){
    for(auto v : g[u]){
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}

void solve()
{
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        cin >> s;
        if(!mp.count(s))mp[s] = ++idx;
        int k;
        cin >> k;
        while(k--){
            cin >> t;
            if(!mp.count(t))mp[t] = ++idx;
            fa[mp[t]] = mp[s];
            d[mp[t]]++;
            g[mp[s]].push_back(mp[t]);
        }
    }
    for(int i=1; i<=idx; ++i){
        if(!d[i]){
            dfs(i);
        }
    }
    while(m--){
        cin >> s >> t;
        int u = mp[s], v = mp[t];
        int a = 0, b = 0;
        
        int f0 = 0;
        if(dep[u] > dep[v])swap(u, v), f0 = 1;
        while(dep[u] != dep[v]){
            if(dep[u] > dep[v])u = fa[u], ++a;
            else v = fa[v], ++b;
        }
        while(u != v){
            u = fa[u], v = fa[v];
            ++a, ++b;
        }
        auto check = [&](int x){
            if(x % 10 == 1){
                cout << x << "st";
            }
            else if(x % 10 == 2){
                cout << x << "nd";
            }
            else if(x % 10 == 3){
                cout << x << "rd";
            }
            else cout << x << "th";
        };
        if(a == 0){
            if(b == 1){
                if(f0)cout << s << " is the child of " << t << endl;
                else cout << t << " is the child of " << s << endl;
            }
            else{
                if(f0)cout << s;
                else cout << t;
                cout << " is the ";
                for(int i=1; i<=b-2; ++i)cout << "great ";
                cout << "grandchild of ";
                if(f0)cout << t;
                else cout << s;
                cout << endl;
            }
        }
        else if(a == b){
            cout << s << " and " << t << " are ";
            if(a == 1){
                cout << "siblings" << endl;
            }
            else{
                check(a-1);
                cout << " cousins" << endl; 
            }
            
        }
        else{
            cout << s << " and " << t << " are ";
            check(a-1);
            cout << " cousins, ";
            if(b - a > 1){
                cout << b - a << " times removed" << endl;
            }
            else
            cout << b - a << " time removed" << endl;
        }
    }







}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    // cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}