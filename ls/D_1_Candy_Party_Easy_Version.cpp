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

int a[N];
void solve()
{
    int n;cin>>n;
    int sum = 0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        sum+=x;
        a[i]=x;
    }
    if(sum%n){
        cout<<"No\n";
        return ;
    }
    int avg = sum/n;
    unordered_map<int,int>mpy,mpx;
    bool ans=true;
    for(int i=1;i<=n;i++)
    {
        int c = a[i]-avg;
        if(c==0)continue;
        bool zd=false;
        for(int i=0;i<32;i++)
        {
            int y = pow(2,i);
            int x = y - c;

            if(x<1)continue;
            if(x== (x&-x))
            {
                zd = true,mpy[y]++,mpx[x]++;
              //  cout<<y<<" "<<x<<" "<<(x&-x)<<endl;
               // break;
            }
        }
        if(!zd)ans=false;
    }

    for(auto t:mpx)
    {
       // cout<<t.first<<" "<<t.second<<endl;
        if(t.second!=mpy[t.first])ans=false;
    }
    if(ans)cout<<"Yes\n";
    else cout<<"No\n";
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