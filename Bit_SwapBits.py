//doubt
def swapBits(x, p1, p2, n):
	set1 = (x >> p1) & ((1<< n) - 1)
	set2 = (x >> p2) & ((1 << n) - 1)
	xor = (set1 ^ set2)
	xor = (xor << p1) | (xor << p2)
	result = x ^ xor
	return result
x,p1,p2,n=map(int,input().split())
res = swapBits(x,p1,p2,n)
print(res)
