
flg = 0
def reverse_(x):
	rem = 0
	rev = 0
	y = x

	if flg == 1:
		if(x==x.reverse()):
			print(x)
	else:
   		while x>0:
			rem = x%10
			rev = rev * 10 + rem
			rem/= 10
		if(y == rev):
			print(y)

for x in range(10,1000):
	for i in range(2,x):
		if (x % i) == 0:
			break
	else:
		print(x)
		s = str(x)
		if s[len(s)-1] == 0 :
			flg = 1
			reverse_(s)
		else:
			reverse_(x)

		
			

