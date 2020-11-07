Root
#include <bits/stdc++.h>
using namespace std;
int main() {
	int input;
	cin>>input;
	int mod=input%1000;
	int n=input/1000;
	int ans=1;
	for (n; n>0; n-=2) {
		ans*=n;
		ans%=mod;
	}
	cout<<ans<<"\n";
}
/*
n=int(input())
mod=n%1000
n//=1000
ans=1
#print(n)
while (n>0):
    ans*=n
    n-=2
ans%=mod
print(ans)
*/
/*
$n=<>;
$mod=$n%1000;
$n-=$mod;
$n=$n/1000;
$ans=1;
while($n>0) {
    $ans*=$n;
    $n-=2;
    $ans%=$mod;
}
print "$ans";
*/
/*
import java.util.Scanner;  // Import the Scanner class

public class MyClass {
  public static void main(String[] args) {
    Scanner myObj = new Scanner(System.in);  // Create a Scanner object
    //System.out.println("Enter username");

    Integer n = myObj.nextInt();  // Read user input
    //System.out.println("Username is: " + userName);  // Output user input
    Integer mod=n%1000;
    n-=mod;
    n/=1000;
    Integer ans=1;
    while (n>0) {
        ans*=n;
        ans%=mod;
        n-=2;
    }
    System.out.println(ans);
  }
}
*/
