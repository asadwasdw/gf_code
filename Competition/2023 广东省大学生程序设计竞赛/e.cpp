#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int son[N][30];
int num[N];
int tot[N];
int cnt=1;

void add(string s)
{
    int p=1;
    tot[p]++;
    for(auto T: s){
        int t=T-'a';
        if(son[p][t]==0)
        {
            ++cnt;
            son[p][t]=cnt;
        }
        p=son[p][t];
        tot[p]++;
    }
    num[p]++;
}

void solve()
{

    for(int i=0;i<=cnt;i++)
    {
        for(int j=0;j<26;j++)son[i][j]=0;
        num[i]=0;
        tot[i]=0;
    }

    cnt=1;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        add(s);
    }

    

    int now=1;

    while(1)
    {
        int t=num[now];
        for(int i=0;i<26;i++)if(son[now][i])t++;

       // cout<<t<<endl;
        if(t>=k)
        {
            if(now==1)cout<<"EMPTY";
            cout<<'\n';
            return;
        }
        
        for(int i=0;i<26;i++) if(son[now][i]) {

            t=t-1+tot[son[now][i]];

            if(t>=k)
            {
                cout<<(char)(i+'a');
                k-=t-tot[son[now][i]];
                now=son[now][i];
                break;
            }

        }

    }
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