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
int n,m,k;
struct node{
    int lson,rson; // 
    int l,r;
    int v;
}tr[N * 25];
int cnt = 0;
unordered_map<int,int>root;

void update(int u,int k,int x,int l,int r) {
    if(l == r) {
        
    }
}

void insertgf(int g,int f) {
    if(root[g] == 0) {
        root[g] = ++ cnt;
    }
0    update(root[g],f);
}





void solve()
{
    
    cin >> n >> m >> k;









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