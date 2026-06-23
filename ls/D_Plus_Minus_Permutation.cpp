#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


void solve()
{
    
    int n,a,b;
    cin>>n>>a>>b;
    int ans1 = n/a;
    int ans2 = n/b;
    int ans3 = n/(a*b/__gcd(a,b));
    ans1-=ans3;
    ans2-=ans3;

    cout<<((n+(n-ans1+1))*ans1/2)-((1+ans2)*ans2/2)<<endl;







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