#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
typedef pair<int,int> PII;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
#define ll2 __int128
LL n;
int cnt,res,ans;
map<string,int> m;
const int N=2e5+10;
int a[N],b[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<6;i++){
        a[i]=s[i]-'0';
    }
    sort(a,a+6);
    if(a[0]!=a[1]&&a[1]==a[2]&&a[2]!=a[3]&&a[3]==a[4]&&a[4]==a[5]) cout<<"Yes";
    else cout<<"No";
    return 0;
}