from exercise2 import get_list_element
from exercise3 import exe3


def test_exe2():
    print("test get list element:")
    get_list_element([1, 2], 2)


def test_exe3():
    print("test exercise 3:")
    exe3()


def test_all():
    test_exe2()
    test_exe3()