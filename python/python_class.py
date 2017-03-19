class Vehical :
    def __init__(self, speed, number, color):
        self.speed = speed
        self.number = number
        self.color = color

    def start(self):
        print "Starting"

    def stop(self):
        print "Stopping"

    def accelerate(self):
        print "accelerating"
	
	def break_(self):
		print "breaking.."


class plane(Vehical):
	def __init__(self, speed, number, color):
		Vehical.__init__(self, speed, number, color)
	def fly(self):
		print "flying"


plane1 = plane(300, 707, 'blue')
plane1.start() 
