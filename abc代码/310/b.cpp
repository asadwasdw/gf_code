#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

struct cp{
    int w;
    vector<int>yd;
}q[N];

bool cmp(cp a,cp b)
{
    if(a.w!=b.w)return a.w>b.w;
    return a.yd.size()<b.yd.size();
}

bool js(cp a, cp b)
{
    
    int i=0;
    for(int j=0;j<(int)b.yd.size();j++)
    {
        if(i<(int)a.yd.size()&&a.yd[i]==b.yd[j]){
            i++;
        }
    }

   // cout<<i<<endl;

     if(i<(int)a.yd.size())return false;
     else return true;
}


void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>q[i].w;
        int c;
        cin>>c;

       // cout<<i<<" ";

        while(c--)
        {
            int x;
            cin>>x;
          //  cout<<x;
            q[i].yd.push_back(x);
        }
        //cout<<endl;
    }

    sort(q+1,q+n+1,cmp);

    // for(int i=1;i<=n;i++)
    // {
    //     cout<<q[i].w<<" ";
    // }
    //cout<<endl;

    bool ky=false;

  //  js(q[3],q[4]);
    

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(js(q[j],q[i])){
                if(q[j].w==q[i].w){
                    if((int)q[i].yd.size()>(int)q[j].yd.size())
                    {
                        ky=true;
                    }
                }
                else 
                {
                    ky=true;
                    //cout<<i<<" "<<j<<endl;
                }
            }
        }
    }

    if(ky)cout<<"Yes";
    else cout<<"No";

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