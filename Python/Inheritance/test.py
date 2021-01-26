from office import Office

def test_office():
    print("test office:")
    office = Office()
    office.hire_manager("Ayelet")
    office.hire_manager("Baruch")
    office.hire_manager("Efrat")
    print("the managers in the office:")
    for manager in office.managers:
        print(manager.name)

    office.managers[0].hire_employee("gili", "count")
    office.managers[0].hire_employee("ayala", "beaty")
    print(f"the clerks of manager {office.managers[0].name}:")
    for employee in office.managers[0].employees:
        print(employee.name)

    office.managers[1].hire_employee("bar", "cpp")
    office.managers[1].hire_employee("yeal", "python")
    print(f"the clerks of manager {office.managers[1].name}:")
    for employee in office.managers[1].employees:
        print(employee.name)

    office.managers[2].hire_employee("toto", "tea")
    office.managers[2].hire_employee("roy", "tea")
    print(f"the clerks of manager {office.managers[2].name}:")
    for employee in office.managers[2].employees:
        print(employee.name)

    office.hire_cleaner("ilana")
    office.hire_cleaner("papi")
    office.hire_cleaner("tri")

    print("start work day")
    office.start_work_day()

    print("start work day 30 times")
    for i in range(30):
        office.start_work_day()
    print("check who got a raise:")
    office.managers[0].raise_salaries()
    office.managers[1].raise_salaries()
    office.managers[2].raise_salaries()

