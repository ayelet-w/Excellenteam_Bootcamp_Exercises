def divide(x, y):
    try:
        print(f'{x}/{y} is {x / y}')
    except ZeroDivisionError as e:
        print("Zero:", e.args)
    except TypeError as e:
        print("Type error - must be digit:", e.args)
    except Exception as e:
        print("exception: ",e.args)


"""
one except line:
"""


def divide_one_line(x, y):
    try:
        print(f'{x}/{y} is {x / y}')
    except (ZeroDivisionError, TypeError, Exception) as e:
        print(e)
