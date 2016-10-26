# your code goes here

def flat(original_key, result, dic):

	for key in dic.iterkeys():
		if type(dic[key]) is dict:
			if original_key == '':
				flat(key, result, dic[key])
			else:
				flat(original_key + '.' + key, result, dic[key])
		else:
			if original_key == '':
				result[key] = dic[key]
			else:
				result[original_key + '.' + key] = dic[key]

def solve(dic):
	result = {}
	flat('', result, dic)
	return result

print solve({
  'Key1': '1',
  'Key2': {
    'a' : '2',
    'b' : '3',
    'c' : {
      'd' : '3',
      'e' : '1'
      }
    }
})
