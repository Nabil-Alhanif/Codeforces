#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int ans=0;
    int curHour=(s[0]-'0')*10+(s[1]-'0');
    int curMinute=(s[3]-'0')*10+(s[4]-'0');
    int curHourMin=(s[1]-'0')*10+(s[0]-'0');
    int nextHour=(curHour+1)%24;
    if (nextHour>=6&&nextHour<10)
    {
        ans+=(10-nextHour)*60;
        nextHour=10;
    }
    if (nextHour>=16&&nextHour<20)
    {
        ans+=(20-nextHour)*60;
        nextHour=20;
    }
    int nextHourMin=(nextHour%10)*10+((nextHour/10)%10);
    if (curMinute<=curHourMin&&!(curHour>=6&&curHour<10)&&!(curHour>=16&&curHour<20))
        cout<<curHourMin-curMinute<<"\n";
    else
        cout<<ans+60-curMinute+nextHourMin<<"\n";
}