w, h = 3, 3

matrix = [[0 for x in range(w)] for y in range(h)]

for x in range(0,w):
	for y in range(0,h):
		matrix[x][y] = int(input("Inter The data")) 

for x in range(0, w):
	for y in range(0, h):
		print "%6.d" %matrix[x][y]

