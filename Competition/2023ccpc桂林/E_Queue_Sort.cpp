#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N];

void solve()
{
    int n;cin>>n;
    int mn = INF,id = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<mn) {
            mn=a[i];
            id=i;
        }
    }

    for(int i=id+1;i<=n;i++){
        if(a[i]<a[i-1]){
            cout<<"-1\n";
            return;
        }
    }
    cout<<id-1<<endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}