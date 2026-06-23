#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

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
vector<int>ans(N+10,0);
bool pd(int l,int r)
{
vector<int>num(N+10,0);

for(int i=l;i<=r;i++){
    num[ans[i]]++;
}
    int i = 1;
    while(num[i])i++;

    cout<<l<<" "<<r<<" "<<i<<endl;

    return !st[i]&&i!=1;
    

}




void solve()
{
   
    int n;
    cin>>n;

    int t = n/2+1;
    int dt = n/2;
    //cout<<t<<" "<<dt<<endl;
    for(int i =1;i<=n;i++)
    {
        if(!st[i+1]){
            
            ans[t]=i;
            
            if(t<dt){
                t--;
            }
            else t++;

            swap(t,dt);
        }
        
    }



    int j = 1;

    for(int i=1;i<=n;i++)
    {
        while(ans[j]!=0)j++;
        if(st[i+1]){
            ans[j]=i;
        }
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    int cnt =0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(pd(i,j))cnt++;
        }
    }
    cout<<cnt<<endl;
}


signed main()
{

    qie_p(N-1);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
   // cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}