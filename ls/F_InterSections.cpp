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
int a[N];
struct seg{
    int l, r;
}s[N];


struct node{
   int x;
   int id;
   int isl;
}no[N];


bool cmp(seg a, seg b) {
    if(a.l != b.l) return a.l < b.l;
    return a.r < b.r;
}

bool cmp2(node a, node b) {
    if(a.x != b.x) return a.x < b.x;
    return a.isl < b.isl;
}

vector<int>lsh;




void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> s[i].l >> s[i].r;
    }
    int ans = 0;
    int res = 0;
    sort(s + 1, s + n + 1, cmp);
    for(int i = 1; i <= n; i ++) {
        no[2 * i - 1] = {s[i].l, i, 1};
        no[2 * i    ] = {s[i].r, i, 0};
    }
    sort(no + 1, no + 2 * n + 1, cmp2);
    multiset<int> st;
    int ansl, ansr;

    lsh.push_back(-12);
    for(int i = 1; i <= 2 * n; i ++) {
        lsh.push_back(no[i].x - 1);
        lsh.push_back(no[i].x + 1);
    }
    sort(lsh.begin(),lsh.end());
    lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());

    vector<PII> num(lsh.size() + 10);
    int j = 1;
    int l = 0, r = 0;  

    int minl = 0;

    for(int i = 1; i <= lsh.size(); i ++) {
        while(j <= 2 * n && lsh[i] > no[j].x) {
            if(no[j].isl) l ++;
            else r ++;
        }
        num[i] = {l, r};

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