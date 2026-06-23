#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

map<string,int>mp;

void solve()
{
    mp["tourist"]= 3858;
    mp["ksun48"]=  3679;
    mp["Benq"]= 3658;
    mp["Um_nik"]= 3648;
    mp["apiad"]= 3638;
    mp["Stonefeang"]= 3630;
    mp["ecnerwala"]=  3613;
    mp["mnbvmar"]=  3555;
    mp["newbiedmy"]=  3516;
    mp["semiexp"]=  3481;

    string s;cin>>s;
    cout<<mp[s]<<endl;
 
 

 










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