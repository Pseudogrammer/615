import sys
import copy

n = len(sys.argv)
money = float(sys.argv[1])
s= 1e-10


units = []
for i in range(2, n):
    units += [float(sys.argv[i])]


def count(lis):
    dic={}
    for i in lis:
        if i in dic:
            dic[i]+=1
        else:
            dic[i]=1
    return dic


def getWays(total, unit):
    m = len(unit)
    results = []
    result = []
    helper(total, unit, 0, m, result, results)

    print("There are " + str(len(results)) + " possible ways to make " + str(total))

    for res in results:
        print(count(res))


def helper(remain, unit_list, start, size, result, results):
    if 0-s < remain < s:
        results.append(result)
        return
    elif remain < 0:
        return
    else:
        for i in range(start, size):
            result.append(unit_list[i])
            temp = copy.deepcopy(result)
            helper(remain - unit_list[i], unit_list, i, size,
                   temp, results)
            result.pop()

getWays(money, sorted(units, reverse=True))
