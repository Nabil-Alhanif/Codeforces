#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
ll INF = 1e18, MOD = 1e9+7;

class SegTree
{
private:
	ll MAXN;
	vector<pair<ll, ll>> tree; // min, max
	vector<ll> array;

public:
	SegTree(ll n)
	{
		MAXN = n;
		tree.resize(MAXN * 4);
		array.resize(MAXN);

		for (int i = 0; i < MAXN; i++)
			cin >> array[i];
		this->build(1, 0, MAXN-1);
	}

	pair<ll, ll> merge(pair<ll, ll> left_node, pair<ll, ll> right_node)
	{
        pair<ll, ll> ret;
        ret.first = min(left_node.first, right_node.first);
        ret.second = max(left_node.second, right_node.second);
        return ret;
	}

	void build(ll vertex, ll left_bound, ll right_bound)
	{
		if (left_bound == right_bound)
		{
			tree[vertex].first = array[left_bound];
            tree[vertex].second = array[left_bound];
		}
		else
		{
			ll mid = (left_bound + right_bound) / 2;
			build(vertex * 2, left_bound, mid);
			build(vertex * 2 + 1, mid + 1, right_bound);
			tree[vertex] = merge(tree[vertex * 2], tree[vertex * 2 + 1]);
		}
	}

	pair<ll, ll> sum(ll vertex, ll left_bound, ll right_bound, ll left_index, ll right_index)
	{
		if (left_index > right_index || left_index > right_bound || right_index < left_bound)
			return {0, 0};
		if (left_index == left_bound && right_index==right_bound)
			return tree[vertex];

		ll mid=(left_bound + right_bound) / 2;
		if (right_index<=mid)
			return sum(vertex*2, left_bound, mid, left_index, right_index);
		else if (left_index>mid)
			return sum(vertex*2+1, mid+1, right_bound, left_index, right_index);
		else
			return merge(sum(vertex*2, left_bound, mid, left_index, mid), 
				sum(vertex*2+1, mid+1, right_bound, mid+1, right_index));
	}

	void update(ll vertex, ll left_bound, ll right_bound, ll position, ll new_value)
	{
		if (left_bound == right_bound)
        {
            tree[vertex].first = new_value;
            tree[vertex].second = new_value;
        }
		else
		{
			ll mid=(left_bound+right_bound)/2;
			if (position<=mid)
				update(vertex*2, left_bound, mid, position, new_value);
			else
				update(vertex*2+1, mid+1, right_bound, position, new_value);
			tree[vertex] = merge(tree[vertex*2],tree[vertex*2+1]);
		}
	}
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k;
    cin >> n >> k;

    vector<ll> height(n);
    ll min_height = INF, max_height = -INF, t = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];

        if (height[i] < min_height)
        {
            s = i;
            min_height = height[i];
        }
        
        if (height[i] > max_height)
        {
            t = i;
            max_height = height[i];
        }
    }
    
    ll instability = max_height - min_height;
    if (instability == 0)
        return cout << "0 0\n", 0;

    vector<pair<ll, ll>> move;
    while (k--)
    {
        move.push_back({t, s});
        height[t]--;
        height[s]++;

        min_height = INF;
        max_height = -INF;

        for (int i = 0; i < n; i++)
        {
            if (height[i] < min_height)
            {
                s = i;
                min_height = height[i];
            }
            
            if (height[i] > max_height)
            {
                t = i;
                max_height = height[i];
            }
        }

        instability = max_height - min_height;
        if (instability == 0)
            break;
    }

    cout << instability << " " << move.size() << "\n";
    for (auto i:move)
        cout << i.first+1 << " " << i.second+1 << "\n";
}
