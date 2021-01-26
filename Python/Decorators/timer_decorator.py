import datetime


def time_function(func):
    def inner(*args, **kwargs):
        time_before = datetime.datetime.now()
        res = func(*args,**kwargs)
        time_after = datetime.datetime.now()
        exe_time = time_after - time_before
        print("function exe time:", exe_time)
        return res
    return inner


@time_function
def sum_many(n):
    return sum([i for i in range(n)])




