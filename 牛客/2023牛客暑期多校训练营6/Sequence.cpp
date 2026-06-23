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
int num[N][2];

void solve()
{
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a[i]=x%2;
    }

    for(int i=1;i<=n;i++){
        a[i]^=a[i-1];
    }

    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;

    for(int i=1;i<=n;i++){
        num[i][1]=num[i-1][1];
        num[i][0]=num[i-1][0];
        num[i][a[i]]++;
    }

    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        l--;
        if(a[l]==a[r]&&num[r][a[r]]-num[l][a[l]]>=k){
            cout<<"YES";
        }
        else cout<<"NO";

        cout<<endl;
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