#-----------------------------------------
        # Q 1
#-----------------------------------------
# text = input("Q1 - please,enter Text :")
# count = 0
#
# for letter in text:
#     if letter in "aeiouAEIOU":
#         count = count + 1
#
# print("count of Vowels is :", count)
#

#-----------------------------------------
        # Q 2
#-----------------------------------------

text = input("Q2 - please,enter Text :")
count = text.lower().count("iti")
print("count of Vowels is :", count)



#-----------------------------------------
        # Q 3
#-----------------------------------------

text = input("Q3 - please,enter Text  :")
count = 0
newText = ""

for letter in text:
    if letter in "aeiouAEIOU":
        count += 1
    else:
        newText = newText + letter
print("count of Vowels is :", count)
print("NewText after remove Vowels is :", newText)

#-----------------------------------------
        # Q 4
#-----------------------------------------

text = input("Q4 - please,enter Text  :")

print("index of i is :", text.index("i"))

#-----------------------------------------
        # Q 5
#-----------------------------------------


count = int(input("Q5 - please,enter number :"))

for i in range(1, count+ 1):
    print(" " * (count - i) + "*" * i)