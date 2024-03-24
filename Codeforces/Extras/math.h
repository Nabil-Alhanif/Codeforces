#include <bits/stdc++.h>
using namespace std;

template <class T>
inline T ceil(T a, T b) // Get ceil of a / b
{
    if (b > 0)
        return ((a + b - 1) / b);
    return 0;
}
 
template <class T>
inline T arithmeticSum(T a)
{
    return (((a * a) + a) / 2);
}
 
template <class T>
inline T arithmeticSum(T a, T b)
{
    return arithmeticSum(a) - arithmeticSum(b);
}
