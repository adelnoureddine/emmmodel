import sys
number = sys.argv[1]
n = int (number)
def hanoi(n, startPeg=1, endPeg=3):
    if n:
        hanoi(n-1, startPeg, 6-startPeg-endPeg)
        print "Move the disk %d from %d to %d" % (n, startPeg, endPeg)
        hanoi(n-1, 6-startPeg-endPeg, endPeg)
 
hanoi(n)
        

 