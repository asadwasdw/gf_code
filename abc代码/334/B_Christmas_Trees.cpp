#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int ceil(int a,int b){
    if(a>=0)return (a+b-1)/b;
    return a/b;
}
int floor(int a,int b){
    if(a<0)return (a-b+1)/b;
    return a/b;
}
void solve()
{
    int a,m,l,r;
    cin>>a>>m>>l>>r;

    int L = ceil(l-a,m);
    int R = floor(r-a,m);

    cout << R - L + 1 << endl;


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