def merge(l, begin, middle, end):

    aux = []

    i = begin
    j = middle + 1

    while i <= middle and j <= end:
        if l[i] < l[j]:
            aux.append(l[i])
            i += 1
        else:
            aux.append(l[j])
            j += 1

    while i <= middle:
        aux.append(l[i])
        i += 1

    while j <= end:
        aux.append(l[j])
        j += 1

    cont1 = 0
    cont2 = begin

    while cont2 <= end:
        l[cont2] = aux[cont1]
        cont1 += 1
        cont2 += 1

def mergesort(l, begin, end):

    if begin < end:
        middle = begin + (end-begin)/2
        mergesort(l, begin, middle)
        mergesort(l, middle + 1, end)
        merge(l, begin, middle, end)
    return l;

n = int(raw_input())
l = map(int, raw_input().split())

print mergesort(l, 0, n-1)
