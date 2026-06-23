#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int a[N];

void solve()
{

    bool flag = true;
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        edg[x].push_back(i);
        if(x!=1 && edg[x-1].size() == 0) flag = false; 
    }
    int res = 1;
    
    for(int i = 1;i <= n && res <= n; i++) {
        reverse(edg[i].begin(), edg[i].end());
        if(edg[i].size() == 0){
            flag = false;
            break;
        }
        for(auto t:edg[i]) {
            a[t] = res++;
        }
    }

    if(!flag)cout << "-1";
    else for(int i =1; i <= n; i++) cout << a[i] << " ";

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}