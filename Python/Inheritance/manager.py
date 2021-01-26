from employee import Employee
from clerk import Clerk


class Manager(Employee):
    def __init__(self, name, salary=20000):
        super().__init__(name, salary)
        self.employees = []

    def hire_employee(self, name, skill):
        employee = Clerk(name)
        employee.add_skill(skill)
        self.employees.append(employee)

    def work(self, office):
        for employee in self.employees:
            employee.work(office.documents)

    def raise_salaries(self):
        BONUS = 1000
        for employee in self.employees:
            if employee.count_documents >= 170:
                employee.salary += BONUS
                print(f"manager {self.name} raise the salary for {employee.name} to {employee.salary}")


