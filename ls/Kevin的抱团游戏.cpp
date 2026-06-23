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


void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int nown=n,nowm=m;

    if(k%2 == 0) {
        int num = k/2;
        nowm = nowm%num;

        if(nown + nowm*2 >= k) {
            nown -= k - nowm*2;
            nowm = 0;
        }
        nown %= k;
        int t = nown/2;

        int th = min(t,m-nowm);
        nowm+=th;
        nown -= th*2;
        cout<<nowm+nown<<endl;
    }
    else if(k == 1) {
        cout<<nowm<<endl;
    }
    else {
        int num = k/2;
        int gs = min(nowm/num,nown);

        nown -= gs;
        nowm -= gs * num;

        if(nown){
            if(nown + nowm*2 >= k) {
                nown -= k - nowm*2;
                nowm = 0;
            }
            nown %= k;

            int t = nown/2;
            int th = min(t,m-nowm);
            nowm+=th;
            nown -= th*2;
            cout<<nowm+nown<<endl;
        }
        else {
            cout<<nowm<<endl;
        }
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