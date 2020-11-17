#include <bits/stdc++.h>
using namespace std;
class dsu
{
    private:
    int dsuSize;
    vector<vector<int>>child;
    vector<int>parent;

    public:
    dsu(int n)
    {
        dsuSize=n;
        child.resize(n);
        parent.resize(n);
        for (int i=0;i<n;i++)
        {
            child[i].push_back(i);
            parent[i]=i;
        }
    }

    int findSet(int n)
    {
        return parent[n];
    }

    int getSize(int n)
    {
        return child[findSet(n)].size();
    }

    void printAllSize()
    {
        for (int i=0;i<dsuSize;i++)
            cout<<getSize(i)<<" ";
        cout<<"\n";
    }
    
    void combine(int a,int b)
    {
        a=findSet(a);
        b=findSet(b);
        if (a!=b)
        {
            if (child[a].size()<child[b].size())
                swap(a,b);
            while (!child[b].empty())
            {
                int cur=child[b].back();
                child[b].pop_back();
                parent[cur]=a;
                child[a].push_back(cur);
            }
        }
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    dsu yaDSU(n);
    while (m--)
    {
        int size;
        cin>>size;
        if (size)
        {
            size--;
            int fir;
            cin>>fir;
            fir--;
            while (size--)
            {
                int cur;
                cin>>cur;
                cur--;
                yaDSU.combine(fir,cur);
            }
        }
    }
    yaDSU.printAllSize();
}