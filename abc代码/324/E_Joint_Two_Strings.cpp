#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int nn ;
int L[N],R[N];
int sl[N];
int sr[N];

string T;
int js(string &t,string &T)
{
    int a=0;
    int b=0;

    while(a<nn && b<(ll)t.size()){
        if(T[a] == t[b]){
            a++;
        }
        b++;
    }
   // cout<<T<<" "<<t<<" "<<a<<endl;
    return a;
}


void solve()
{
    int n;
    cin>>n;
    cin>>T;
    string T1 = T;
    nn= T.size();
    reverse(T1.begin(),T1.end());

    for(int i = 1;i<=n;i++){
        string t;
        cin>>t;
        L[i] = js(t,T);
        reverse(t.begin(),t.end());
        R[i] = js(t,T1);

  //    cout<<L[i]<<" "<<R[i]<<endl;
        sl[L[i]]++;
        sr[R[i]]++;
    }


    for(int i= nn;i>=0;i--){
        sr[i] +=sr[i+1];
    }

    ll ans = 0;
    for(int i = 0;i<=nn;i++){
        int j = nn - i ;
        ans+=1ll*sl[i]*sr[j];
    }
    cout<<ans<<endl;
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