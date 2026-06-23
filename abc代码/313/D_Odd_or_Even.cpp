#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int a[N];
int qm=0;
void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        cout<<"! ";
        for(int j=1;j<k;j++){
            cout<<j<<" ";
        }
        cout<<k+i;

        int t;
        cin>>t;

        if(i==0){
            qm=t;
        }
        else 
        {
            if()
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