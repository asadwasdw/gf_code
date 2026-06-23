#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e7+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
bool st[N];
int pri[N];
int cnt;

void qie_p(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])pri[cnt++]=i;
        
        for(int j=0;i*pri[j]<=n;j++)
        {
            st[pri[j]*i]=true;
            if(i%pri[j]==0)
            {
                break;
            }
        }
    }
    
}

int a[N];


void solve()
{
    int n;cin>>n;
    qie_p(1e7);
    int w = cnt-1;

    if(n%2)a[1]=1;

    for(int i=n;i;i--){
        if(a[i])continue;
        while(~w&&(pri[w]-i>i || a[pri[w]-i]==1)){
            w--;
        }
        // cout<<i<<" "<<pri[w]<<endl;
        a[i]=pri[w]-i;
        a[pri[w]-i]=i;
    }
    // for(int i=1;i<=10;i++)cout<<pri[i]<<" ";cout<<endl;


    // for(int i=1;i<=n;i++) cout<<a[i]+i<<" ";cout<<endl;
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
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