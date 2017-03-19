def outer():
	a = 325
	def inner():
		a = 10;
		print a;
	inner()
	print a
outer()

