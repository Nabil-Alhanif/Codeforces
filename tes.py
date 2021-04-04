import math

if __name__=="__main__":
    a,b,c=input().split()
    GCD=math.gcd(a,b)
    if c%GCD:
        print("There is no integer solution!\n")
        quit()
    