
def function_information(func):
    def inner(*args, **kwargs):
        print("name:", func.__name__)
        print("args:", args)
        print("kwargs", kwargs)
        print("return value:", func(*args, **kwargs))
        print("type return value:", type(func(*args, **kwargs)))
    return inner


@function_information
def add(*args, **kwargs):
    return sum(args)



