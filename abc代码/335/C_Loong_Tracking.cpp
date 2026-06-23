#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=3e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int x[N],y[N];



void solve()
{
    int n,q;cin>>n>>q;
    for(int i=n;i;i--){
        x[i]=n-i+1;
        y[i]=0;
    }


    while(q--)
    {
        int p;
        cin>>p;
        if(p==1){
            char op ;
            cin >> op;
            if(op=='U'){
                x[n+1]=x[n];
                y[n+1]=y[n]+1;
            }
            else if(op=='D'){
                x[n+1]=x[n];
                y[n+1]=y[n]-1;
            }
            else if(op=='L'){
                x[n+1]=x[n]-1;
                y[n+1]=y[n];
            }
            else {
                x[n+1]=x[n]+1;
                y[n+1]=y[n];
            }
            n++;
        }
        else {
            int op;
            cin>>op;
            cout<<x[n-op+1]<<" "<<y[n-op+1]<<endl;
        }
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