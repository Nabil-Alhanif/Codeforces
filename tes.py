def func(x):
    return ((25 ** x) / ((25 ** x) + 5))

ans = 0.0
for i in range(1, 2024):
    ans = ans + func(i / 2024)

print(ans)
