from numpy import random

from document import Document
from employee import Employee


class Clerk(Employee):
    def __init__(self, name, salary=15000):
        super().__init__(name, salary)
        self.skills = []
        self.count_documents = 0

    def add_skill(self, skill):
        self.skills.append(skill)

    def work(self, documents):
        number = int(random.randint(1, 10))
        for i in range(number):
            document = Document(self.name, self.skills[0])
            self.add_document(document,documents)
        self.count_documents += number
        print(f"{self.name} added {number} documents")
        for document in documents:
            if document.d_type in self.skills and self.name != document.employee_name:
                self.handle(document)
                break

    @staticmethod
    def add_document(document, documents_list):
        documents_list.append(document)

    def handle(self, document):
        print(f"{self.name} handle document:{document.employee_name} {document.d_type}")
