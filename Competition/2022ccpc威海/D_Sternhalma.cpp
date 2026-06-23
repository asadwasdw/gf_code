#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
#define setb0(n,k) (n=(n&(~(1<<k))))
#define setb1(n,k) (n=(n|(1<<k)))
const int N=1e6+10;
const int mod=998244353;
const int INF  = 1<<20;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int f[INF];
int a[16][16];

PII get(PII t,int d){
    int x = t.first,y = t.second;
    if(x<3){
        if(d==1)return {x-1,y-1};
        if(d==2)return {x-1,y};
        if(d==3)return {x,y+1};
        if(d==4)return {x+1,y+1};
        if(d==5)return {x+1,y};
        if(d==6)return {x,y-1};
    }
    else if(x==3){
        if(d==1)return {x-1,y-1};
        if(d==2)return {x-1,y};
        if(d==3)return {x,y+1};
        if(d==4)return {x+1,y};
        if(d==5)return {x+1,y-1};
        if(d==6)return {x,y-1};
    }else{
        if(d==1)return {x-1,y};
        if(d==2)return {x-1,y+1};
        if(d==3)return {x,y+1};
        if(d==4)return {x+1,y};
        if(d==5)return {x+1,y-1};
        if(d==6)return {x,y-1};
    }

}
PII get(int x){
    if(x<=3)return {1,x};
    if(x<=7)return {2,x-3};
    if(x<=12)return {3,x-7};
    if(x<=16)return {4,x-12};
    return {5,x-16};
}
int get(PII t){
    int x = t.first,y = t.second;
    if(x<=0)return 0;
    if(x<=1)return y;
    if(x<=2)return 3+y;
    if(x<=3)return 7+y;
    if(x<=4)return 12+y;
    return 16+y;
}
int dfs(int i){
    if(f[i]>=0)return f[i];
    for(int j=0;j<19;j++){
                if((i>>j)&1==0)continue;

                int z = i;
                setb0(z,j);

                f[i] = max(f[i],dfs(z));
                for(int k=1;k<=6;k++){
                    PII l = get(get(j+1),k),r = get(get(j+1),(k+2)%6+1);

                     int x = get(l)-1,y = get(r)-1;
                    if(x==-1||y==-1)continue;
                   
                    if((i>>x)&1==0)continue;
                    setb0(z,x);
                    setb1(z,y);
                    f[i] = max(f[i],dfs(z)+a[get(j+1).first][get(j+1).second]);
                }
            }
    return f[i];
}
void solve()
{
    for(int i=1;i<=5;i++){
        if(i==1||i==5){
            for(int j=1;j<=3;j++)cin>> a[i][j];
        }
        else if(i==2||i==4){
            for(int j=1;j<=4;j++)cin>> a[i][j];
        }
        else {
            for(int j=1;j<=5;j++)cin>> a[i][j];
        }
    }

    for(int i=0;i<=INF;i++)f[i] = (int)-1e9;
    f[0] = 0;
    dfs(1);
    

        
    


    int q;cin>> q;
    while(q--){
        int now=0;
        for(int i=1;i<=5;i++){
            string s;cin>> s;
            for(auto t:s){
                now*=2;
                if(t=='#')now++;
                
            }
        }
        cout<<dfs(now)<<endl;
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