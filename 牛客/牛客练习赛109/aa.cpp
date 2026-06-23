#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;


inline long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

void print(long long x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10^48);
}


void solve()
{
    long long a;
    a=read();
   //cout<<a<<endl;
    long long ans=0;
    if(a<=1)ans=a;
    else if(a%2==0)ans=2;
    else ans=3;
    print(ans); 
    printf("\n");
}


int main()
{
    long long t;
    t=read();
    while(t--)
    solve();

}