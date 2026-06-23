#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


bool pd(int n,int k){

    string s;
    int cnt0 = n/2;
    int cnt1 = n - cnt0;

    for(int i =1;i<=cnt0;i++) {
        s+='0';
    }
    for(int i =1;i<=cnt1;i++) {
        s+='1';
    }
 

    bool ky =false;

    do{
        set<int>st;
        for(int i = 0;i + k - 1<n;i++){
            int t = 0;
            for(int j = 0;j<k;j++){
                if(s[i+j]=='1')t^=1;
            }
            st.insert(t);
        }
        if(st.size() == 1) {ky = true;break;}

    }while(next_permutation(s.begin(),s.end()));

    if(ky)return 1;
    return 0;
}

void solve()
{
    int n;
    cin>>n;
    printf("sss");
    for(int j=1;j<=n;j++)printf("%3d",j);cout<<endl;
    for(int i= 1;i<=n;i++)
    {
        printf("%3d",i);
        for(int j=1;j<=n;j++){
            if(j>n)printf("%3d",0);
            else printf("%3d",pd(i,j));
        }
        cout<<endl;
    }

}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}