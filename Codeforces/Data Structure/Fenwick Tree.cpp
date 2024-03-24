#include <bits/stdc++.h>

using namespace std;

class FenwickTree
{
    vector<int> bit;
    int size;

    FenwickTree(int n) {
        this->size = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            this->add(i, a[i]);
    }

    int get(int idx) {
        if (idx < 0)
            return 0;

        int ret = 0;
        for (; idx > 0; idx -= (idx & -idx))
            ret += this->bit[idx];
        return ret;
    }

    int get(int l, int r) {
        int ret;
        ret = this->get(r) - this->get(l - 1);
        return ret;
    }

    void add(int idx, int delta) {
        for (; idx < this->size; idx += (idx & -idx))
            bit[idx] += delta;
    }
};
