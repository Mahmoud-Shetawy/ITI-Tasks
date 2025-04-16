checkArray=[]
while(True):
    try:
        inputNumber = int(input("Enter a number: "))
        if type(inputNumber) is int:
            checkArray.append(inputNumber)
        if len(checkArray) == 5:
            print(checkArray)
            break;
    except ValueError:
        print("Invalid input")
