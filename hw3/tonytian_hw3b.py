import sys
import copy

##############################################################
## Skeleton code of dynamic programming version of changeMoney
## Arguments:
## - total  : (integer) total amount of money to make
## - unit   : list of containing units of bills in integer
## - stored : dictionary containing a stored information to avoid
##            redundancy
##############################################################
def dpChangeMoney(total, units, stored):
    if total == 0:
        return [{}]
    n = len(units)
    if (total, n) not in stored:
        result = []
        for i in range(0, n):
            unit = units[i]
            if total < unit:
                continue
            solutions = copy.deepcopy(dpChangeMoney(total - unit, units[i:n], stored))
            for sol in solutions:
                if unit in sol:
                    sol[unit] += 1
                else:
                    sol[unit] = 1
                result.append(sol)
        stored[(total, n)] = result
    return stored[(total, n)]

##############################################################
## TODO: implement the function above.
##############################################################

dollars = int(sys.argv[1])
bills   = [int(x) for x in sys.argv[2:len(sys.argv)]]
ways = dpChangeMoney(dollars, bills, {})
print("There are " + str(len(ways)) + " possible ways to make "+str(dollars))
for way in ways:
    print(sorted(way.items()))