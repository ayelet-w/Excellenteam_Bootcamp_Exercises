
def count_calls(func):

    def inner(*args, **kwargs):
        inner.counter += 1
        print("call number:", inner.counter)
        res = func(*args, **kwargs)
        return res
    inner.counter = 0
    return inner


@count_calls
def add(x, y):
    return x+y



