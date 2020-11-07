#include <bits/stdc++.h>
using namespace std;
// HAI
int main()
{
  // I HAS A TUX
  double tux;
  // GIMMEH TUX
  cin>>tux;
  // I HAS A FOO ITS 0
  double foo=0;
  // I HAS A BAR ITS 0
  double bar=0;
  // I HAS A BAZ ITS 0
  double baz=0;
  // I HAS A QUZ ITS 1
  double quz=1;

  // TUX IS NOW A NUMBR

  // IM IN YR LOOP NERFIN YR TUX TIL BOTH SAEM TUX AN 0
  while (tux--)
  {
    // I HAS A PUR
    double pur;
    //GIMMEH PUR
    cin>>pur;
    //PUR IS NOW A NUMBR

    //FOO R SUM OF FOO AN PUR
    foo+=pur;
    // BAR R SUM OF BAR AN 1
    bar++;

    //BOTH SAEM BIGGR OF PRODUKT OF FOO AN QUZ AN PRODUKT OF BAR BAZ AN PRODUKT OF FOO AN QUZ
    //O RLY?
    //YA RLY
    if (max(foo*quz,bar*baz)==foo*quz)
    {
      // BAZ R FOO
      baz=foo;
      //QUZ R BAR
      quz=bar;
    }
    // OIC
    //IM OUTTA YR LOOP
  }
  //BAZ IS NOW A NUMBAR

  //VISIBLE SMOOSH QUOSHUNT OF BAZ QUZ
  cout<<baz/quz<<"\n";
  //KTHXBYE
  return 0;
}
