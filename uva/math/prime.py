maxnum = 100001
shoplist = [0]
for i in range(1, maxnum):
	shoplist.append(0)

for i in range(2, maxnum):
	for j in range (2, maxnum / i + 1):
		if i*j < maxnum:
			shoplist[i*j] = 1

prime = []
for i in range(2, maxnum):
	if shoplist[i] == 0:
		prime.append(i)
print len(prime)
