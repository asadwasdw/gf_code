#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

struct T{
    int v;
    int id;
}a[N];

unordered_map<int,int>mp;

bool cmp(T a, T b) {
    if(a.v != b.v) return a.v < b.v;
    return a.id < b.id;
}


void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i].v;
        a[i].id = i;
    }
    sort(a+1,a+n+1,cmp);

    for(int i = 1; i <= n; i ++) {
        mp[a[i].id] = i;
    }

    while(m --) {
        int op, x, y;
        cin >> op >> x;
        if(op == 1) {
            int i = mp[x];
            cin >> a[i].v;
            while(i < n && a[i].v > a[i + 1].v) {
                swap(mp[a[i+1].id], mp[a[i].id]);
                swap(a[i],a[i + 1]);
                i ++;
            }

            while(i < n && a[i].v == a[i + 1].v && a[i].id > a[i + 1].id) {
                swap(mp[a[i+1].id], mp[a[i].id]);
                swap(a[i],a[i + 1]);
                i ++;
            }

            while(i > 1 && a[i].v < a[i - 1].v) {
                swap(mp[a[i-1].id], mp[a[i].id]);
                swap(a[i],a[i - 1]);
                i--;
            }

            while(i > 1 && a[i].v == a[i - 1].v && a[i].id < a[i - 1].id) {
                swap(mp[a[i-1].id], mp[a[i].id]);
                swap(a[i],a[i - 1]);
                i--;
            }   
            
        }
        else cout << mp[x] << endl;

        // for(int i = 1; i <= n; i ++) cout << a[i].v << " " << a[i].id << endl; cout << endl;
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