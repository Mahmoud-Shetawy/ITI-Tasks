
def twoArg (length, start):
    ListNumber=[]
    for i in range(1,length+1):
        ListNumber.append(i+start)
    return ListNumber

try:
    lengthArr = int(input("Enter a number of Length: "))
    startArr = int(input("Enter a number of start index: "))
    result = twoArg(lengthArr, startArr)
    print(f"list of Number {result}")
except ValueError:
    print("Invalid input")
