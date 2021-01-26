from employee import Employee


class Cleaner(Employee):
    def __init__(self, name, salary=1000):
        super().__init__(name, salary)

    def work(self):
      print(f"{self.name} is cleaning")


