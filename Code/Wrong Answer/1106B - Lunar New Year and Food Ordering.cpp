#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m,totDish=0,ans=0;
    cin>>n>>m;
    vector<pair<ll,pair<ll,ll>>>price(n+1);
    vector<pair<pair<ll,ll>,pair<ll,pair<ll,ll>>*>>dish(n+1);
    for (int i=1;i<=n;i++)
    {
        cin>>dish[i].first.first;
        totDish+=dish[i].first.first;
    }
    for (int i=1;i<=n;i++)
    {
        cin>>price[i].first;
        dish[i].first.second=price[i].first;
        price[i].second.first=i;
    }
    sort(price.begin()+1,price.end());
    for (int i=1;i<=n;i++)
    {
        dish[price[i].second.first].second=&price[i];
        price[i].second.second=i;
    }
    while (m--)
    {
        ll t,d,p=0;
        cin>>t>>d;
        if (totDish<d)
        {
            cout<<"0\n";
            price.clear();
            totDish=0;
            continue;
        }
        ll curDish=t;
        while (d)
        {
            /*
            Remainder:
            dish[].first.first -> Jumlah makanan
            dish[].first.second -> Harga makanan
            dish[].second -> Price makanan tadi
            price[].first -> Harga makanan
            price[].second.first -> Index makanannya
            price[].second.second -> Index di list harga yang udah di sort
            */
            p+=min(d,dish[curDish].first.first)*dish[curDish].first.second;
            if (d>=dish[curDish].first.first)
            {
                d-=dish[curDish].first.first;
                dish[curDish].first.first=0;
                //cout<<curDish<<" "<<dish[curDish].second->second.second<<"\n";
                price.erase(price.begin()+dish[curDish].second->second.second);
                curDish=price[1].second.first;
            } else
            {
                dish[curDish].first.first-=d;
                d=0;
            }
        }
        totDish-=t;
        cout<<p<<"\n";
    }
}