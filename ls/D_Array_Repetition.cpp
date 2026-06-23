#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int a[N];
__int128 num[N],len[N];

void solve()
{
    int n,q;
    cin>>n>>q;
    __int128 cnt = 0;
    for(int i=1;i<=n;i++){
        int op,x;
        cin>>op>>x;
        if(op==1){
            ++cnt;
            a[cnt]=x;
            len[cnt]=len[cnt-1]+1;
            num[cnt]=1;
        }
        else {
            len[cnt]*=(x+1);
            num[cnt]*=(x+1);
        }
    }

    // for(int i=1;i<=cnt;i++)cout<<a[i]<<" "<<len[i]<<endl;

    while(q--){
        int x;
        cin>>x;
        __int128 ans = cnt;
        while(x!=len[ans]&&x){
            __int128 ln = len[ans]/num[ans];
            if(x>ln){
                x%=ln;
                if(x==0)x=ln;
            }
            else if(x<ln){
                ans--;
            }
            else {
                break;
            }
        }

        cout<<a[ans]<<" ";
    }
    cout<<endl;




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