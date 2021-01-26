import math

dividend = float(input("Enter the dividend: "))
divisor = float(input("Enter the divisor: "))
quotient = dividend/divisor
print(math.floor(quotient))


"""
1:
Traceback (most recent call last):
  File "C:/Users/User/PycharmProjects/Exceptions/exercise1 .py", line 5, in <module>
    quotient = dividend/divisor
ZeroDivisionError: float division by zero

2:
Enter the dividend: w
Traceback (most recent call last):
  File "C:/Users/User/PycharmProjects/Exceptions/exercise1 .py", line 3, in <module>
    dividend = float(input("Enter the dividend: "))
ValueError: could not convert string to float: 'w'

3:
Traceback (most recent call last):
  File "C:/Users/User/PycharmProjects/Exceptions/exercise1 .py", line 6, in <module>
    print(math.floor(quotient))
NameError: name 'math' is not defined

"""