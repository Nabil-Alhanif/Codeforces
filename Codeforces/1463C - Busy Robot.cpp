#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie();cout.tie(0);
    ll t;
    cin>>t;
    while (t--)
    {
        ll curPos=0,curTime=0,lastPos=0,lastTime=0;
        ll n,ans=0;
        cin>>n;
        pair<ll,ll>move[n];
        for (int i=0;i<n;i++)
            cin>>move[i].first>>move[i].second;
        lastTime=move[0].first;
        for (int i=0;i<n-1;i++)
        {
            if (move[i].first>=curTime)
            {
                lastTime=move[i].first;
                lastPos=curPos;
                curTime=lastTime+abs(move[i].second-curPos);
                curPos=move[i].second;
            }
            ll ccPos = curPos;
            ll sPos = lastPos;
            if (move[i+1].first<curTime)
            {
                ll timeDif = curTime-move[i+1].first;
                if (curPos>=lastPos)
                    ccPos-=timeDif;
                else ccPos+=timeDif;
            }
            if (move[i].first>lastTime)
            {
                ll timeDif = move[i].first-lastTime;
                if (curPos>=lastPos)
                    sPos+=timeDif;
                else sPos-=timeDif;
            }
            ll minPos = min(sPos,ccPos), maxPos = max(sPos,ccPos);
            if (move[i].second>=minPos&&move[i].second<=maxPos)
                ans++;
        }
        if (move[n-1].first>=curTime)
            ans++;
        else
        {
            ll ccPos = curPos;
            ll sPos = lastPos;
            if (move[n-1].first>lastTime)
            {
                ll timeDif = move[n-1].first-lastTime;
                if (curPos>=lastPos)
                    sPos+=timeDif;
                else sPos-=timeDif;
            }
            ll minPos = min(sPos,ccPos), maxPos = max(sPos,ccPos);
            if (move[n-1].second>=minPos&&move[n-1].second<=maxPos)
                ans++;
        }
        
        cout<<ans<<"\n";
    }
}