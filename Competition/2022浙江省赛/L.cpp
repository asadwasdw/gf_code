#include<iostream>
#include<algorithm>

using namespace std;

const int N=2e6+10;
long long a[N];
long long s[N];

int main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=i*i*i;
		cin>>a[i];
	}

	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
		//cout<<(double)s[i]/i<<endl;
	}

	int j=0;

	int ans=0;

	for(int i=1;i<=n;i++)
	{
		double pjs=(double)s[i]/i;

		while(j<=n&&a[j]<=pjs)
		{
			j++;
		}

		ans=max(ans,i-j+1);
		//cout<<ans<<" "<<j<<endl;
		//cout<<pjs<<" "<<j<<endl;
	}

	cout<<ans<<endl;

}