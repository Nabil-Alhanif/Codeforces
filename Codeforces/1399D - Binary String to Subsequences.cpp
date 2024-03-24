#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,id=0;string s;
        cin>>n>>s;
        int ar[n];
        vector<int> kel[2];
        for (int i=0;i<n;i++)
        {
            int cur=s[i]-'0';
            if (kel[cur^1].empty())
                kel[cur^1].push_back(++id);
            ar[i]=kel[cur^1].back();
            kel[cur].push_back(kel[cur^1].back());
            kel[cur^1].pop_back();
        }
        cout<<id<<"\n";
        for (int i=0;i<n;i++)
            cout<<ar[i]<<" ";
        cout<<"\n";
    }
}