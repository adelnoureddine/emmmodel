import sys
number = sys.argv[1]
n = int (number)
def fibRec(n):
    if n < 2:
        return n
    else:
        return fibRec(n-1) + fibRec(n-2)
print ("The Fibonacci of " +str(n)+ " is "+str(fibRec(n)))