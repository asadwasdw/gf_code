#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

void pd(int A,int B)
{
    double a=A;
    double b=B;
    if(b*log(a)>a*log(b))cout<<A<<endl;
    else if (b*log(a)==a*log(b))cout<<min(A,B)<<endl;
    else cout<<B<<endl;
}


int main()
{
    int a,b;
    cin>>a>>b;
    pd(a,b);

}