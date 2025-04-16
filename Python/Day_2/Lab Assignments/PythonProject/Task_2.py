
try:
    multNumber = int(input("Enter a number: "))
    ListNumber = []
    for index in range(1,multNumber+1):
        unmutaList = []
        for i in range(1,index+1):
            unmutaList.append(i*index)
        ListNumber.append(unmutaList)
except ValueError:
    print("Invalid input")


print(f"multiplication table: {ListNumber}")
