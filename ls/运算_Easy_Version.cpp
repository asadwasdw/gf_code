#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int> PII;
#define endl '\n'
const int N=4000010,INF=0x3f3f3f3f;
const int mod= 1e9+7;
const double eps=1e-12;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int f[N];
void slove(){
    int n;
    cin>>n;
    for(int i=1;i<=16;i++){
        f[i]=f[i-1]*10+1;
    }
    int ans=1e18;
    for(int i=1;i<=16;i++){
        if((f[i]*9-n)%9==0&&f[i]*9>=n)ans=min(ans,(f[i]*9-n)/9);
        if(n>f[i])continue;
        int temp=0,nn;
        temp+=(f[i]-n)/9;
        nn=n+(f[i]-n)/9*9;
        nn*=9;
        if((f[i]*9-nn)%9!=0)continue;
        ans=min(ans,temp+(f[i]*9-nn)/9+1);
    }
    cout<<ans<<endl;
}
signed main()
{
    int T=1;
    // freopen("Dinner.in","r",stdin);
    // freopen("Dinner.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin>>T;
    while(T--){
        slove();
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
