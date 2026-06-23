#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
const int M = 131, mod = 1e9 + 7;
#define ull unsigned long long
int n;
vector<ull> pre(N + 2), suf(N + 2);
vector<ull> p(N + 2, 1);

ull get(int l,int r){
	return pre[r]-pre[l-1]*p[r-l+1];
}
ull getf(int l,int r){
	int L =  n - r +1; 
	int R = n - l+1;
	//cout<<L<<" "<<R<<endl;
	return suf[R]-suf[L-1]*p[R-L+1];
}
void solve(){
	string s, c;cin>>s;
	n = s.size();
	s=" "+s;
	int l=1;
	int r=n;
	while(l<r){
		if(s[l]!=s[r]) break;
		l++, r--;
	}

	if(l>=r){
		cout << "1 "<< n << endl;
		return;
	}
	c = " ";
	for(int i=l;i<=r;i++)c+=s[i];
	n = c.size() - 1;
	
	


	for(int i=1;i<=n;i++){
		pre[i] = pre[i-1]*M+c[i]-'a'+1;
		p[i] = p[i-1]*M;
	}
	s=c;
	reverse(s.begin(), s.end());
	//cout<<s<<endl;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		suf[i]=suf[i-1]*M+s[i]-'a'+1;
		//cout<<i<<" "<<s[i]<<" "<<suf[i]<<endl;
	}

	//cout<<getf(2,2)<<endl;
	//cout<<n<<endl;
	for(int k=1;k<n;k++){
		//cout<<p[k]<<endl;
		//cout<<getf (1,k)<<" "<<get(k+1,n)<<endl;
		//cout<<getf (k+1,n)<<" "<<get(1,k)<<endl;
		ull a = getf (1,k)*p[n-k]+get(k+1,n);
		ull b = getf(k+1,n)*p[k]+get(1,k);
		//cout<<i<<" "<<a<<" "<<b<<endl;

		if(a==b){
			//cout<<k<<endl;
			cout<<l<<" "<<k+l-1<<endl;
			return;
		} 
	}

    for(int k=1;k<n;k++){
		//cout<<p[k]<<endl;
		//cout<<getf (1,k)<<" "<<get(k+1,n)<<endl;
		//cout<<getf (k+1,n)<<" "<<get(1,k)<<endl;
		ull a = get (1,k)*p[n-k]+getf(k+1,n);
		ull b = get(k+1,n)*p[k]+getf(1,k);
		//cout<<i<<" "<<a<<" "<<b<<endl;

		if(a==b){
			//cout<<k<<endl;
			cout<<l+k<<" "<<r<<endl;
			return;
		} 
	}

	cout<<"-1 -1";


}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;//cin >> t;
	while(t--)solve();
}