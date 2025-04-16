def sumOfNumber(nums):
    sum = 0
    for num in nums:
        sum += num
    return sum

listNumber=[]
while(True):
    try:
        inputNumber = input("Enter a number: ")
        if inputNumber == "done":
            print(f"Count of  Number {listNumber} = {len(listNumber)}")
            print(f"sum of all Number {listNumber} = {sumOfNumber(listNumber)}")
            print(f"Average  of all Number {listNumber} = {sumOfNumber(listNumber)/((len(listNumber),1)[len(listNumber)==0])}")
            break
        if type(int(inputNumber)) is int:
            listNumber.append(int(inputNumber))
        print(listNumber)
    except ValueError:
        print("Invalid input")
