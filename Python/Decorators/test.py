import timer_decorator
import print_function_information
import slow_down
import number_of_calls
from cache_decorator import fibonacci


def test_timer_decorator():
    print("test timer decorator:")
    print(timer_decorator.sum_many(10000000))


def test_print_func_info():
    print("test print function info:")
    print_function_information.add(1, 2, age=3, text="hello")


def test_slow_down():
    print("test slow down:")
    print(slow_down.add(1,2))


def test_number_of_calls():
    print("test number of calls function:")
    number_of_calls.add(1, 2)
    number_of_calls.add(1, 2)
    print(number_of_calls.add(1, 2))


def test_cache():
    print("test cache:")
    print(fibonacci(2))
    print(fibonacci(4))

def test_all():
    test_timer_decorator()
    test_print_func_info()
    test_slow_down()
    test_number_of_calls()
