import sys
import random

try: input = raw_input  # in python 2, this line redefines input() as raw_input()
except NameError: pass  # in python 3, exception happens, so input() method remains the same
# using this, in both python 2 and 3, you can use "input(....)" method to prompt input from users.


def sortStr(x):
    return "".join(sorted(x))


def trans(strLis):
    hashmap_word = {}
    for word in strLis:
        sort = sortStr(word)
        if sort not in hashmap_word:
            hashmap_word[sort] = [word]
        else:
            hashmap_word[sort].append(word)
    return hashmap_word


def shuffle(word):
    temp = list(word)
    random.shuffle(temp)
    return "".join(temp)

fname = sys.argv[1]
print("-" * 60)
print("Welcome to tonytian's word unscrambler!")
print("-" * 60)

hashmap_len = {}
allWord=[]
with open(fname) as fhand:
    words = fhand.read().strip().split("\n")
    for word in words:
        word = word.strip()
        allWord.append(word)
        if len(word) not in hashmap_len:
            hashmap_len[len(word)] = [word]
        else:
            hashmap_len[len(word)].append(word)

counter = 0
while True:
    num = input("First, pick the length of the word you want to be challenged:\n"
                "(type q to quit or type Enter to pick a random word) : ")
    if num.strip() == "q":
        print("-" * 60)
        print "Thanks for enjoying tonytian's word unscrambler!\nYou finished ", counter, " games"
        print "Send me ", counter, " bitcoins for the game fee. (just kidding)"
        print("-" * 60)
        break
    if num and int(num) not in hashmap_len:
        print("There is no word with length " + str(int(num)) + ". Choose a different length")
        print
        continue
    counter += 1
    if num and int(num) in hashmap_len:
        words = hashmap_len[int(num)]
        n = random.randint(0, len(words))
        word = words[n]
        anss = trans(words)[sortStr(word)]
    else:
        n = random.randint(0, len(allWord))
        word = allWord[n]
        anss = trans(hashmap_len[len(word)])[sortStr(word)]
    ans = input("Unscramble the word \"" + str(shuffle(word)) + "\" : ")
    if ans in anss:
        print("Correct!")
    else:
        print("Sorry.. incorrect")
    print "Correct answer(s) : ", anss    # I only modified some print commands with commas
    print                                 # that are not compatible with python2

exit()