#include <bits/stdc++.h>
using namespace std;
class dsu
{
    private:
    int dsuSize;
    vector<vector<int>>child;
    vector<int>parent;
    vector<int>parentEdge;
    vector<bool>isCyclic;

    public:
    dsu(int n)
    {
        dsuSize=n;
        child.resize(n);
        parent.resize(n);
        parentEdge.resize(n);
        isCyclic.resize(n);
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

    void checkCyclicNoDebug()
    {
        for (int i=0;i<dsuSize;i++)
            if (findSet(i)==i)
            {
                if (child[i].size()<3)
                {
                    isCyclic[i]=0;
                }
                else
                {
                    isCyclic[i]=1;
                    for (auto j:child[i])
                        if (parentEdge[j]!=2)
                        {                            
                            isCyclic[i]=0;
                            break;
                        }
                }
            }
    }

    void checkCyclic()
    {
        cout<<"Running cycle check.....\n";
        for (int i=0;i<dsuSize;i++)
            if (findSet(i)==i)
            {
                cout<<"Checking node "<<i+1<<"\n";
                if (child[i].size()<3)
                {
                    isCyclic[i]=0;
                    cout<<"Node "<<i+1<<" is not a cycle because it's size is less than 3.\n";
                }
                else
                {
                    isCyclic[i]=1;
                    for (auto j:child[i])
                        if (parentEdge[j]!=2)
                        {
                            cout<<"Node "<<i+1<<" is not a cycle because it has more than 2 edges.\n";
                            isCyclic[i]=0;
                            break;
                        }
                    if (isCyclic[i])
                        cout<<"Node "<<i+1<<" is a cycle.\n";
                }
            }
    }

    bool checkCycle(int n)
    {
        return isCyclic[parent[n]];
    }

    int countCycle()
    {
        int ret=0;
        for (int i=0;i<dsuSize;i++)
            if (parent[i]==i)
                if (isCyclic[i])
                    ret++;
        return ret;
    }

    void printAllSize()
    {
        for (int i=0;i<dsuSize;i++)
            cout<<getSize(i)<<" ";
        cout<<"\n";
    }

    void printOverAll()
    {
        for (int i=0;i<dsuSize;i++)
        {
            if (parent[i]==i)
                cout<<"Node "<<i+1<<" is a parent.\n";
            cout<<"Node "<<i+1<<" has "<<getSize(i)<<" friends including it self.\n";
            cout<<"It's child's are: ";
            for (auto j:child[findSet(i)])
                cout<<j+1<<" ";
            cout<<"\n";
            cout<<"Node "<<i+1<<" have "<<parentEdge[i]<<" edges.\n";
            cout<<"Node "<<i+1<<" and friends are "<<(checkCycle(i)?"cycle.\n":"not cycle.\n");
        }
    }
    
    void combine(int a,int b)
    {
        parentEdge[a]++;
        parentEdge[b]++;
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
        int a,b;
        cin>>a>>b;
        yaDSU.combine(a-1,b-1);
    }
    yaDSU.checkCyclicNoDebug();
    //yaDSU.printOverAll();
    cout<<yaDSU.countCycle()<<"\n";
}