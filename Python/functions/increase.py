def increase(key_, amount=1):
    def increase_func(dict_input):
        dict_input[key_] += amount
    return increase_func


def salary_retires(employee):
    years = 70 - employee["age"]
    i = 1
    increase_the_employee_age_by_2 = increase("age", 2)
    increase_the_employee_salary_by_1000 = increase("salary", 1000)
    while i < years/2:
        increase_the_employee_age_by_2(employee)
        increase_the_employee_salary_by_1000(employee)
        i += 1
    return employee["salary"]




