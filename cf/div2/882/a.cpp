#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int n,k;
int a[N];
vector<int>ans;

bool cmp(int a,int b)
{
    return a<b;
}
void solve()
{

    ans.clear();
    cin>>n>>k;
    k=n-k;
    int res=0;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i!=1)ans.push_back(abs(a[i]-a[i-1]));
    }

    sort(ans.begin(),ans.end(),cmp);
    int sum=0;

    for(int i=0;i<ans.size();i++)
    {
       // cout<<i<<" "<<ans[i]<<endl;
        if(k > 0)
        {
         res+=ans[i];
            k--;
        }

        sum+=ans[i];
    }
    cout<<res<<endl;

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