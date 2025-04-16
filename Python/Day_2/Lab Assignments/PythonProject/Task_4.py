
def checkNumber (num):
    if num % 3 == 0 and num % 5 == 0:
        return "FizzBuzz"
    elif num % 5 == 0:
        return "Buzz"
    elif num % 3 == 0:
        return "Fizz"

try:
    numberCheck = int(input("Enter a number of Length: "))
    result = checkNumber(numberCheck)
    print(f"the result is :  {result}")
except ValueError:
    print("Invalid input")
