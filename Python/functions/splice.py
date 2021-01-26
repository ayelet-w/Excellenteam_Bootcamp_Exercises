
def splice(target, start, delete_count=None, *items):

    if delete_count is None:
        delete_count = len(target) - start

    # store removed range in a separate list and replace with *items
    total = start + delete_count
    removed = target[start:total]
    target[start:total] = items

    return target, removed


