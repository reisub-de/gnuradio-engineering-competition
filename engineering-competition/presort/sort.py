import csv

with open('d_new.csv', 'rb') as f1:
	for row in f1:
		d_str=row.replace(" ","").split(",")
with open('p_new.csv', 'rb') as f2:
	for row in f2:
		p_str=row.replace(" ","").split(",")


zipped = [(int(a), int(b)) for (a,b) in zip(p_str,d_str)]

# print(sorted(zip(p_str,d_str)))
# print sorted(zipped)

sort_tup = sorted(zipped)
# print(sort_tup)
(p,d) = zip(*sort_tup)

print p
print "\n\n\n"
print d
