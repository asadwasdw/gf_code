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
PII a[N];

unordered_map<int,vector<int>> h, w;
map<PII,int> st;

struct Node
{
    int x,y,id;
}no[N];


bool cmp1(Node a, Node b) {
    return a.y < b.y;
}


bool cmp2(Node a, Node b) {
    return a.x < b.x;
}

int wfind(int id, int t) {
    return lower_bound(w[id].begin(),w[id]. end(),t) - w[id].begin();
}

int hfind(int id, int t) {
    return lower_bound(h[id].begin(),h[id]. end(),t) - h[id].begin();
}


void solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        int x, y; cin >> x >> y;
        no[i] = {x + y, x - y, i};
        st[{x + y, x - y}] = i;
    }

    sort(no + 1, no + n + 1,cmp1);

    for(int i = 1; i <= n; i ++) {
        h[no[i].x].push_back(no[i].y);
    }

    for(auto t : h) {
        for(int )
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