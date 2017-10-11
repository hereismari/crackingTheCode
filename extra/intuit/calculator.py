def simplify_expression(expression, i=0, previous_operation=''):
    if previous_operation == '-':
      result = '+'
    else:
      result = previous_operation
    while i < len(expression):
        if expression[i] == '(':
            # before is empty or parenthesis no need to add operator
            if i == 0 or expression[i-1] == '(':
              new_previous_operation = ''
            # if operator than add operator
            elif expression[i-1] == '+':
                new_previous_operation = '+'
            else:
                new_previous_operation = '-'
            
            # simplify expression until the end of the parenthesis
            aux, k = simplify_expression(expression, i+1, new_previous_operation)
            result += aux  # add aux to result
            i = k + 1  # move pointer to the end of the parenthesis
            
        elif expression[i] == ')':
            # if closing and previous_operation is a minus invert result
            if previous_operation == '-':  
              inverted_result = ''
              for e in result:
                  if e == '+':
                      inverted_result += '-'
                  elif e == '-':
                      inverted_result += '+'
                  else:
                      inverted_result += e
              print 'inverted:', inverted_result
              return inverted_result, i
            else:
              print 'regular:', result
              return result, i
        elif i == len(expression)-1 or expression[i+1] != '(':
            result += expression[i]
            i += 1
        else:
            i += 1
            
    return result, 0

assert simplify_expression('5+3-2-((2-5)-(3+1))', '5+3-2-2+5+3-1')
assert simplify_expression('(1+2+3-3)+(5-3)-(2-(1-1)-(1+(4-1)))','1+2+3-3+5-3-2+1-1+1+4-1')
assert simplify_expression('1-((2-3))', '1-2+3')

