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
    int n;
    int sum = 0;
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i],sum+=a[i];}

    sum=(sum+1)/2;

    for(int i=1;i<=n;i++)
    {
        if(sum>a[i]){
            sum-=a[i];
        }
        else {
            cout<<i<<" "<<sum<<endl;
            break;
        }
    }








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