import math

if __name__=="__main__":
    ans = 0
    ans2 = 0
    i = 4
    while(1):
        ans2 = ans2 + 1
        ans = ans + i
        i = i + 5
        if (ans>1030):
            break
    print(ans2)
