def cache(func):
    def inner(n):
        if inner.cache_dict.get(n):
            return inner.cache_dict[n]
        inner.cache_dict[n] = func(n)
        return inner.cache_dict[n]
    inner.cache_dict = dict()
    return inner


@cache
def fibonacci(num):
    print("calculating: ", num)
    if num < 0:
        print("Incorrect input")
    elif num == 0:
        return 0
    elif num == 1:
        return 1

    else:
        return fibonacci(num-1)+fibonacci(num-2)



