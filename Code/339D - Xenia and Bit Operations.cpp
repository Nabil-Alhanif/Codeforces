#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e13;

class SegTree{
public:
	ll MAXN;
	vector<ll>tree;
	vector<ll>array;
	SegTree(ll n, bool op)
	{
		MAXN=n;
		tree.resize(MAXN*4);
		array.resize(MAXN);
		for (int i=0;i<MAXN;i++)
			cin>>array[i];
		this->build(1, 0, MAXN-1, op);
	}

	void build(ll vertex, ll leftBound, ll rightBound, bool op)
	{
		if (leftBound==rightBound)
			tree[vertex] = array[leftBound];
		else
		{
			ll mid = (leftBound+rightBound)/2;
			build(vertex*2, leftBound, mid, op^1);
			build(vertex*2+1, mid+1, rightBound, op^1);
            if (op)
                tree[vertex] = tree[vertex*2]|tree[vertex*2+1];
            else tree[vertex] = tree[vertex*2]^tree[vertex*2+1];
		}
	}

	void update(ll vertex, ll leftBound, ll rightBound, ll position, ll newValue, bool op)
	{
		if (leftBound==rightBound)
			tree[vertex]=newValue;
		else
		{
			ll mid=(leftBound+rightBound)/2;
			if (position<=mid)
				update(vertex*2, leftBound, mid, position, newValue,op^1);
			else
				update(vertex*2+1, mid+1, rightBound, position, newValue, op^1);
            if (op)
                tree[vertex] = tree[vertex*2]|tree[vertex*2+1];
            else tree[vertex] = tree[vertex*2]^tree[vertex*2+1];
		}
	}
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, pp;
    cin >> n >> m;
    pp = pow(2, n);
    SegTree tree(pp, n%2);
    //for (auto i:tree.tree)
    //    cout << i << " "; cout<<"\n";
    //cout << tree.tree[1] << "\n";
    while (m--)
    {
        ll p, b;
        cin >> p >> b;
        tree.update(1, 0, pp-1, p-1, b, n%2);
        cout << tree.tree[1] << "\n";
    }
}