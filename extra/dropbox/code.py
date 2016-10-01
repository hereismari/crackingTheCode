
n = 8
lamps = [[1, 6], [5, 6], [7, 3], [3, 2]]
queries = [[3, 4], [7, 6]]

def horizontal_compare(a, b):
    if a[0] != b[0]:
        return a[0] - b[0]
    else:
        return a[1] - b[1]

def vertical_compare(a, b):
    if a[1] != b[1]:
        return a[1] - b[1]
    else:
        return a[0] - b[0]

def diagonal_compare(a, b):
    d1 = abs(a[0] - a[1])
    d2 = abs(b[0] - b[1])
    if d1 != d2:
        return d1 - d2
    elif a[0] != b[0]:
        return a[0] - b[0]
    else:
        return a[1] - b[1]

hor = sorted(lamps, cmp=horizontal_compare)
ver = sorted(lamps, cmp=vertical_compare)
dia = sorted(lamps, cmp=diagonal_compare)

print hor
print ver
print dia
