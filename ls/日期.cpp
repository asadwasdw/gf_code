#include <iostream>
using namespace std;
#define ll long long 

int n;

ll rn[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
ll pn[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

bool isr(ll t)
{
	if (t % 4 == 0 && t % 100 != 0)return true;
	if (t % 400 == 0)return true;

	return false;
}



void solved() {

	ll year, mouth, day;
	cin >> year >> mouth >> day ;
    //printf("%d,%d,%d\n",year,mouth,day);
    bool ky =true;
    if(year <1 ||year > 2050)ky=false;

    day++;
    if (isr(year))
    {
        if(mouth>13||mouth<0 || day - 1 > rn[mouth] || day - 1 <= 0)ky=false;
        if (day > rn[mouth]) {
            day = 1;
            mouth++;
        }
        if (mouth >= 13) {
            year++;
            mouth = 1;
        }
    }
    else
    {
        if(mouth>13||mouth<0 || day - 1 > pn[mouth] || day - 1 <= 0)ky=false;
        if (day > pn[mouth]) {
            day = 1;
            mouth++;
        }

        if (mouth >= 13) {
            year++;
            mouth = 1;
        }

    }
   
    if(ky)
	printf("%d %d %d\n",year,mouth,day);
    else cout<<"输入数据不合法";
}
int main() {
	solved();
	return 0;
}