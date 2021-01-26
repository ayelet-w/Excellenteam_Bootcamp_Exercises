

def my_reduce(func, iter_input, initial=None):
    if len(iter_input) <= 1:
        return None
    if initial:
        result = func(initial, iter_input[0])
    else:
        result = iter_input[0]
    for i in range(1, len(iter_input)):
        result = func(result, iter_input[i])
    return result



