#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

typedef long long ll;
const int N=2e5+10;
int a[N];
map<int,vector<int>>s;

int main()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[a[i]].push_back(i);
	}
	ll ans=0;
	for(ll i = 1; i <= n; i ++ ) ans += (i * (n - i + 1) - min(i, n - i + 1));
	ans>>=1;
//	cout<<ans<<endl;
	for(auto t:s)
	{
		auto T=t.second;
		int l=0,r=T.size()-1;

	//	cout<<t.first<<" "<<r<<endl;

		while(l<r)
		{
			ll left=T[l];
			ll right=n-T[r]+1;
			if(left<=right){ans -= left*(r-l);l++;}
			else {ans-= right*(r-l);r--;}
			//cout<<ans<<endl;
		}
	}
    cout<<ans<<endl;
}