#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


struct st{
   int cs;
   int a[5][5];
   int p;
};

int bh(char t)
{
    if(t=='w')return 1;
    if(t=='i')return 2;
    if(t=='n')return 3;
    return 0;
}


void print(st t)
{
    cout<<t.cs<<endl;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)cout<<t.a[i][j]<<" ";
        cout<<endl;
    }
    cout<<t.p<<endl;
    cout<<"---------"<<endl;
}


ll qmi(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

void solve()
{
    st t;
    cin>>t.cs;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++)
        {
            char T;cin>>T;
            t.a[i][j]=bh(T);
        }
    }
    t.p=1;

    ll ly3=qmi(3,mod-2);

    queue<st>q;
    q.push(t);

    ll res=0;

    while(q.size())
    {
        t=q.front();q.pop();
 
        //print(t);
        bool js=false;

        for(int i=1;i<=3&&!js;i++)
        {
            sort(t.a[i]+1,t.a[i]+4);
            if(t.a[i][2]!=t.a[i][3] && t.a[i][2]!=t.a[i][1])
            {
                js=true;
                if(i==1)res+=t.p;
            }
        }

        res%=mod;

        if(js)continue;

        if(t.cs==0)continue;

        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                ll p=t.p*ly3%mod*ly3%mod;
                st T=t;
                T.p=p;

                T.a[1][2]=t.a[3][j];
                T.a[2][i]=t.a[1][2];
                T.a[3][j]=t.a[2][i];
                T.cs--;
                q.push(T);
            }
        }
        
    }

    cout<<res<<endl;
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