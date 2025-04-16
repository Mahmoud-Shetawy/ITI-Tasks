def reverseFun(ls):
    newList = []
    for index in range(0,len(ls)):
        char = ls.pop(0)
        # print(char)
        newList.insert(0,char)
    print(f"List of word Afetr reversed :{newList}")
    return newList


def reverseString (text):
    charList = []
    charList.extend(text)
    print(f"List of word before reversed :{charList}")
    word =  ''.join(reverseFun(charList))
    return word

try:
    inputText = input("Enter a text: ")
    result = reverseString(inputText)
    print(f"the Word after Reversed  :  {result}")
except ValueError:
    print("Invalid input")
