class Circle :
	#def __init__(self, rad):
	#	self.radius = rad
	radius = 10
	def area(self):
		return 3.14 * self.radius * self.radius

circle1 = Circle();
circle2 = Circle();

print circle1.radius
print circle2.area()
print circle1.__dict__
print circle2.__dict__
