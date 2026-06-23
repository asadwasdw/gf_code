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
void print(int x) {
    printf("Python 3.%d will be faster than C++",x);
}

void solve()
{
    int n;cin>> n;
    int k;cin>>k;
    for(int i=1;i<=500000;i++){
        if(i<=n)cin>>a[i];
        else a[i] = max(0,2*a[i-1]-a[i-2]);
        if(a[i]<k) {
            print(i);
            return;
        }
    }

    cout<<"Python will never be faster than C++";

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