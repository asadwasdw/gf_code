#include <bits/stdc++.h>
using namespace std;



long double fs(long double fz,long double fm,long double gh)
{
    return fz/fm*sqrt(gh);
}

void solved() {

	long double a,b;cin>>a>>b;

    if(a>b){
        swap(a,b);
    }

    double  ans = ((b/a*b/a) + 1)/2/(b/a);

    if(b/a>=fs(2,3,3))
    {
        ans=fs(2,3,3)*a;
    }

    
    if(a==b)
    {
        ans=1.03527618041008295791*a;
    }

	printf("%.13lf",ans);

}
int main() {
	// int ttx;  read(ttx);  while(ttx --)
	solved();
	return 0;
}