#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N];
int n;

void print(){
    for(int i=1;i<=n;i++){
        for(int j=5;~j;j--){
            cout<<((a[i]>>j)&1)<<" ";
        }cout<<endl;
    }
    cout<<endl;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a[i]^=x;
        a[i]|=(1<<i);
    }
    // print();
    int x,y;
    while(cin>>x>>y && x && y){
        a[y]|=(1<<x);
    }

   // print();

    int ans = 0;
    
    for(int i=1;i<=n;i++){

        for(int j=i+1;j<=n;j++){
            if(a[j]>a[i])swap(a[j],a[i]);
        }

        if(a[i]==0){
            ans=(1<<(n-i+1));
            break;
        }
        
        if(a[i]==1){
            ans=0;
            break;
        }

        for(int k=n;k;k--){
            if(a[i]>>k & 1) {
                for(int j=1;j<=n;j++){
                    if(i==j)continue;
                    if(a[j]>>k & 1){
                        a[j]^=a[i];
                    }
                }
            }
        }
    }
    if(ans==0)cout<<"Oh,it's impossible~!!\n";
    else cout<<ans<<"\n";
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