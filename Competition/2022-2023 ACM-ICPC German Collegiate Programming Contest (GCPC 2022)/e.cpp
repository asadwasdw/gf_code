#include<iostream>
#include<algorithm>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
double f[N];

int main()
{
    f[1]=1;
    f[0]=0;
    int n;cin>>n;
    for(int i=3;i<=min(100,n);i++)
    {
        f[i]=(f[i-1]+f[i-2])/2;
    }

    // for(int i=1;i<=n;i++)
    // {
    //     printf("%d %.8lf\n",i,f[i]);
    // }


    if(n<=50)
    {
        printf("%.6lf %.6lf",f[n]*100,(1-f[n])*100);
    }
    else cout<<"33.333333 66.666667"<<endl;
}