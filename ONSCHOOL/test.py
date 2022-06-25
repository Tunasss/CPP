t = int(input())
for i in range(t):
    s = input()
    print(s[-1])
    print(s[0])
    if len(s) % 2 == 0 and s[0] != ')' and s[-1] != '(':
        print('YES')
    else:
        print('NO')