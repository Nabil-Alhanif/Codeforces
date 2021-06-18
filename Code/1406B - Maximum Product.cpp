#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll INF = 1e18, MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, ans = -INF;
        cin >> n;
        vector<ll> neg, pos;
        while (n--)
        {
            ll tmp;
            cin >> tmp;
            if (tmp<0)
                neg.push_back(tmp);
            else pos.push_back(tmp);
        }
        sort(pos.begin(), pos.end(), greater<ll>());
        sort(neg.begin(), neg.end(), greater<ll>());
        ll pos_size = pos.size();
        ll neg_size = neg.size();
        vector<ll> pref(neg_size), suff(neg_size);

        if (!neg_size)
        {
            ll local_max = 1;
            for (int i=0; i<5; i++)
                local_max *= pos[i];
            ans = max(ans, local_max);
            cout << ans << "\n";
            continue;
        }

        if (!pos_size)
        {
            ll local_max = 1;
            for (int i=0; i<5; i++)
                local_max *= neg[i];
            ans = max(ans, local_max);
            cout << ans << "\n";
            continue;
        }

        pref[0] = neg[0];
        for (int i=1; i<min(neg_size, (ll)6); ++i)
        {
            pref[i] = pref[i-1]*neg[i];
        }

        suff[0] = neg[neg_size-1];
        for (int i=neg_size-2; i>=max((ll)0, neg_size-7); --i)
        {
            int poss = neg_size - 1 - i;
            suff[poss] = suff[poss-1]*neg[i];
        }

        /*
        for (auto i:pref)
            cout << i << " ";
        cout << "\n";

        for (auto i:suff)
            cout << i << " ";
        cout << "\n";
        */

        int lim = min(pos_size, (ll)5);
        for (int i=0; i<lim; i++)
        {
            int kur = 3 - i;
            if (neg_size<=kur)
                continue;
            ll local_max = 1;
            for (int j=0; j<=i; j++)
                local_max *= pos[j];
            if (kur>=0)
                local_max *= max(suff[kur], pref[kur]);
            ans = max(ans, local_max);
        }
        cout << ans << "\n";
    }
}
