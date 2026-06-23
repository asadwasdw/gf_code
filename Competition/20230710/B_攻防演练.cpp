#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

unordered_map<int, queue<int>>edg;
int f[N][25];

void solve()
{
    int m,n;
    cin>>m>>n;
    string s;cin>>s;
    s="a"+s;
    for(int i=1;i<=n;i++){
        edg[s[i]-'a'].push(i);
    }

    for(int i=0;i<=n;i++)
    {
        int t= 0;
        for(int j=0;j<m;j++){
            while(edg[j].size()&&edg[j].front()<=i)edg[j].pop();
            if(edg[j].size())t=max(t,edg[j].front());
            else t=n+4;
        }
        if(t==0)t=n+4;
        f[i][0]=t;

    }

    for(int i=n;i>=0;i--)
    {
        for(int j=1;j<=20;j++)
        {
            f[i][j]=f[f[i][j-1]][j-1];
            if(f[i][j]==0){
                f[i][j]=n+5;
                //continue;
            }
        }
    }
    //cout<<"s"<<endl;

    int q;
    cin>>q;
    while(q--)
    {
        int l , r;
        cin>>l>>r;
        l--;
        int res = 0;
        for(int i=20;i>=0;i--)
        {
            if(f[l][i]>r)continue;
            l=f[l][i];
            res+=(1<<i);
        }
        cout<<res+1<<endl;
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