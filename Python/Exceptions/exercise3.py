
def exe3():
    try:
        age = int(input("How old are you? "))
    except ValueError as e:
        print("value error exception:", e.args)

