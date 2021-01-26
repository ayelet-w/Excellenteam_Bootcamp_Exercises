import reduce
from splice import splice
import max_arguments
import increase


def test_reduce():
    print("test reduce:")
    print(reduce.my_reduce(lambda x, y: x + y, [1, 2, 3]))
    print(reduce.my_reduce(lambda x, y: x * y, [1, 2, 3, 4, 5]))
    print(reduce.my_reduce(lambda x, y: x * y, [1, 2, 3, 4, 5], 0.5))


def test_max_arguments():
    print("test max arguments:")
    print(max_arguments.max_arguments())  # 0
    print(max_arguments.max_arguments(1, 2, 3, 7))  # 4
    print(max_arguments.max_arguments(9, 2))  # 4
    print(max_arguments.max_arguments(1, 2, 3, 4, 5))  # 5


def test_increase():
    print("test increase")
    employee = {
        "name": "Momo",
        "age": 61,
        "salary": 10000
    }

    increase_the_employee_age = increase.increase("age")
    increase_the_employee_age(employee)
    print(employee)

    increase_the_employee_salary = increase.increase("salary", 1000)
    increase_the_employee_salary(employee)
    print(employee)

    print(increase.salary_retires(employee))


def test_splice():
    print("test splice:")
    # remove 1 element
    nums = [1, 2, 3]
    nums, deleted = splice(nums, 0, 1)
    print(nums)  # should be [2,3]

    # add 1 element
    nums = [1, 2, 3]
    nums, deleted = splice(nums, 0, 0, 0);
    print(nums);  # should be [0,1,2,3]

    # add 2 elements
    nums = [1, 2, 3]
    nums, deleted = splice(nums, 0, 0, -1, 0);
    print(nums);  # should be [-1,0,1,2,3]

    # replace 1 element
    nums = [1, 2, 3]
    nums, deleted = splice(nums, 1, 1, 55);
    print(nums);  # should be [1,55,3]

    # delete all elements from index to end
    nums = [1, 2, 3, 4, 5]
    nums, deleted = splice(nums, 1);
    print(nums);  # should be [1]

    # returns list of deleted elements as the second parameter
    nums = [1, 2, 3]
    nums, deleted = splice(nums, 1);
    print(deleted);  # should be [2,3]

    # returns an list of the deleted element (1 element)
    nums = [1, 2, 3]
    nums, deleted = splice(nums, 1, 1);
    print(deleted);  # should be [2]

    # returns an empty list when no elements are deleted
    nums = [1, 2, 3]
    nums, deleted = splice(nums, 1, 0, 5);
    print(deleted);  # should be []

    # delete all but 2 last ones
    nums = [1, 2, 3, 4]
    nums, deleted = splice(nums, -2);
    print(deleted);  # should be [3,4]


def test_all():
    test_reduce()
    test_max_arguments()
    test_increase()
    test_splice()
