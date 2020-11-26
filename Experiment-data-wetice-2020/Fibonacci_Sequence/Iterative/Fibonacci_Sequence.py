import sys
number = sys.argv[1]
n = int (number)
def fibIter(n):
    if n < 2:
        return n
    fibPrev = 1
    fib = 1
    for num in range(2, n):
        fibPrev, fib = fib, fib + fibPrev
    return fib
print ("The Fibonacci of " +str(n)+ " is "+str(fibIter(n)))