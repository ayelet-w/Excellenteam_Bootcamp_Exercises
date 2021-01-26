from time import sleep


def slow_down(func):
    def inner(*args, **kwargs):
        sleep(1)
        res = func(*args, **kwargs)
        return res
    return inner


@slow_down
def add(x, y):
    return x+y

