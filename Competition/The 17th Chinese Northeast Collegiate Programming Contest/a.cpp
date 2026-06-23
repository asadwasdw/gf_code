#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5+10; 
double a[N];

int main()
{
    int n;cin>>n;
    double sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    sort(a+1,a+n+1);

    if(n>=3)printf("%.1lf",min(a[2],a[1]/2+a[n]/2));
    else printf("%.1lf",sum/n);
}