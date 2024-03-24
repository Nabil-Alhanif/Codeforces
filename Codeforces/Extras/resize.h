#include <bits/stdc++.h>
using namespace std;
 
template <class T>
inline void resizeVect1D(vector<T> &vect, int n)
{
    vect.resize(n);
}
 
template <class T>
inline void resizeVect2D(vector<vector<T>> &vect, int n, int m)
{
    vect.resize(n);
    for (auto &i:vect)
        i.resize(m);
}
