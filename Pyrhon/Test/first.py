MoneyType = [1,3,5]
def kid(moneyleft):
    if moneyleft == 0:
        return 0
    ans = 2e9
    for type in MoneyType:
        if moneyleft >= type:
            ans = min(kid(moneyleft - type) + 1,ans)
