#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int n;
bool pd(int x)
{

	int a[100]={0};
	for(int i = n - 1; ~i ;i--){
		a[i] = ((x>>i)&1);
	}
//	cout<<"----\n";
	// for(int j = 0;j<n;j++){
	// 	cout<<a[j]<<" ";
	// }cout<<endl;
	for(int i = 1;i<=2*n;i++){
		int b[100]={0};
		for(int j = 0;j<min(30,n);j++){


			if(a[j]){
				if(j!=0&&a[j-1]!=1)b[j-1]^=1;
				if(j!=n-1&&a[j+1]!=1)b[j+1]^=1;
			}
		}
		int t = 0;
		for(int j = 0;j<min(30,n);j++){
			t+=b[j]*(1<<j);
			//cout<<b[j]<<" ";
		}//cout<<endl;
	
		if(t==x)return true;
		memcpy(a,b,sizeof a);
	}
	return false;
}

void solve()
{
	cin>>n;
	if(n%2){
	for(int i = 1; i< n*n;i++)
		if(pd(i)){
			for(int j =n-1;~j;j--){
				cout<<((i>>j)&1);
			}return;
		}}
else{
	for(int i = 1; i< 5*n*n;i++)
		if(pd(i)){
			for(int j =n-1;~j;j--){
				cout<<((i>>j)&1);
			}return;
		}
}
cout<<"Unlucky";
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