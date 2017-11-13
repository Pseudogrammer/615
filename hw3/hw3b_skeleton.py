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

##############################################################
## TODO: implement the function above.
##############################################################

dollars = int(sys.argv[1])
bills   = [int(x) for x in sys.argv[2:len(sys.argv)]]
ways = dpChangeMoney(dollars, bills, {})
print("There are " + str(len(ways)) + " possible ways to make "+str(dollars))
for way in ways:
    print(sorted(way.items()))
