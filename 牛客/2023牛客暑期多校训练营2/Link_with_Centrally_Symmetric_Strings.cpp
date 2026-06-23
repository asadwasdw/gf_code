#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int  dy[256];

void init()
{
    for(int i=1;i<256;i++)dy[i]=1;
    dy['o']='o';
    dy['s']='s';
    dy['x']='x';
    dy['z']='z';
    dy['b']='q';
    dy['q']='b';
    dy['u']='n';
    dy['n']='u';
    dy['p']='d';
    dy['d']='p';
    dy['|']='|';
}

bool pd(int a,int b)
{
   // cout<<a<<" "<<dy[b]<<endl;
    if(a==dy[b]){
        return true;
    }
    return false;
}



void solve()
{

    string _s;
    string s;
    cin>>_s;
    int n = _s.size()*2+1;
    s+=' ';
    s+='$';

    vector<int>l(2*n,0);
    vector<int>f(2*n,INF);
    vector<int>dp(2*n,0);

    for(auto t: _s)
    {
        s+='|';
        s+=t;
    }
    s+='|';
    s+='%';
    s+='\n';
    //cout<<s;

    l[1]=1;
    int k = 0;
    int r = 0;

    f[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(i<r)l[i]=min(r-i,l[k*2-i]);
        else l[i]=0;
        while(pd(s[i-l[i]],s[i+l[i]]))
        {
            f[i+l[i]]=min(f[i+l[i]],i-l[i]-1);
            l[i]++;
        }

        if(i+l[i]>r)
        {
            k = i ;
            r=i+l[i];
        }
    }

    dp[0]=dp[1]=1;

    for(int i=1;i<=n;i++){
        dp[i]|=dp[min(n+1,f[i])];
    }

   // for(int i=0;i<=n;i++)cout<<dp[i]<<" ";cout<<endl;

    if(dp[n])cout<<"Yes\n";
    else cout<<"No\n";



}


signed main()
{
    init();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}