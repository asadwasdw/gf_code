#include <stdio.h>
#include <algorithm>
#include<iostream>
#define LL long long
#define maxn 100010
LL a[maxn],c,b,d,ans1,ans2;
using namespace std;
LL quick_pow(LL a,LL b){
	LL ret=1;
	while(b){
		if(b&1)ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}
int main(){
	
	for(int i=1;i<=100;i++)cout<<"1 ";
}