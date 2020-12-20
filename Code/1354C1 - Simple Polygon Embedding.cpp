#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        double n;
        cin>>n;
        double angle=360/(n*4);
        double res=cos(angle*PI/180.0)/sin(angle*PI/180.0);
        cout<<fixed<<setprecision(10)<<res<<"\n";
    }
}