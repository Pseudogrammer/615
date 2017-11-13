import sys;

#############################################################
## this is the changeMoney funcion from HW1
## arguments:
##   total : total amount of money to pay
##   units : list of possbile bills
#############################################################
def changeMoney(total, units):
    if ( total == 0 ): ## exact
        return [{}]
    elif ( total < 0 ):
        return []
    else:
        n = len(units)
        ret = []
        for i in range(0,n):
            sols = changeMoney(total-units[i],units[i:n])
            for sol in sols:
                if ( units[i] in sol ):
                    sol[units[i]] += 1
                else:
                    sol[units[i]] = 1
                ret.append(sol)
        return ret
#############################################################
#### end of function changeMoney()
#############################################################

dollars = int(sys.argv[1])
bills   = [int(x) for x in sys.argv[2:len(sys.argv)]]
bills.sort(reverse=True)
ways = changeMoney(dollars, bills)
print("There are " + str(len(ways)) + " possible ways to make "+str(dollars))
for way in ways:
    print(dict(sorted(way.items())))
