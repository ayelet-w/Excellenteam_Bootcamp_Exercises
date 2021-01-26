from document import Document
from manager import Manager
from cleaner import Cleaner


class Office:
    def __init__(self):
        self.documents = []
        self.managers = []
        self.cleaners = []

    def hire_cleaner(self, name):
        cleaner = Cleaner(name)
        self.cleaners.append(cleaner)

    def hire_manager(self, name):
        manager = Manager(name)
        self.managers.append(manager)

    def start_work_day(self):
        for manager in self.managers:
            manager.work(self)
        for cleaner in self.cleaners:
            cleaner.work()


