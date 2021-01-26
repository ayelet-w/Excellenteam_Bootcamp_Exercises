
def max_arguments(*args, max_args=[0]):
    if len(args) > max_args[0]:
        max_args[0] = len(args)
    return max_args[0]


