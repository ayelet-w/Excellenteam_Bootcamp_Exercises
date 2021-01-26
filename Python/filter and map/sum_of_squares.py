def sum_of_squares(numbers):
    even_list = list(filter(lambda num: num % 2 == 0, numbers))
    even_list.sort()
    four_big_list = even_list[-4:]
    return sum(map(lambda num: num ** 2, four_big_list))




