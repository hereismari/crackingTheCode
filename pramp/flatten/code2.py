def flatten(d, key, result):
    for k in d:
        if key == '':
            new_key = k
        else:
            new_key = key + '.' + k

        if type(d[k]) == type(dict()):
           flatten(d[k], new_key, result)
        else:
            result[new_key] = d[k]

    return result

def flat(d):
    return flatten(d, '', {})

a = {
    'Key1': '1',
    'Key2': {
        'a' : '2',
        'b' : '3',
        'c' : {
            'd' : '3',
            'e' : '1'
        }
    }
}

print flat(a)
print flat({})
