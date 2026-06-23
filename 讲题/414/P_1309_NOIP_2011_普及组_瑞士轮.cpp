#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

struct P
{
    int id, weight, w;
}p[N],a[N],b[N];

bool cmp(P a, P b) {
    if(a.w == b.w) return a.id < b.id;
    return a.w > b.w;
}


void solve()
{
    int n, r, q;
    cin >> n >> r >> q;
    n *= 2;
    for(int i = 1; i <= n; i ++) {
        cin >> p[i].w;
        p[i].id = i;
    }
    for(int i = 1; i <= n; i ++) {
        cin >> p[i].weight;
    }
    sort(p + 1, p + n + 1, cmp);

    while(r --) {
        int cnta = 0,cntb = 0;
        for(int i = 1; i <= n; i += 2) {
            if(p[i].weight > p[i + 1].weight) {
                p[i].w ++;
                a[++cnta] = p[i];
                b[++cntb] = p[i + 1];
            }
            else {
                p[i + 1].w ++;
                a[++cnta] = p[i + 1];
                b[++cntb] = p[i];
            }
        }
        
        int l = 1, r = 1;
        for(int i = 1; i <= n; i ++) {
            if(l <= cnta && r <= cntb) {
                if(a[l].w == b[r].w) {
                    if(a[l].id < b[r].id) p[i] = a[l ++];
                    else p[i] = b[r++];
                }
                else if(a[l].w > b[r].w)  p[i] = a[l ++];
                else p[i] = b[r++];
                continue;
            }
            if(l <= cnta) p[i] = a[l ++];
            if(r <= cntb) p[i] = b[r ++];
        }
        // for(int i = 1; i <= n; i++) cout << p[i].id << " " ; cout << endl; 
    }
    cout << p[q].id << endl;

    







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