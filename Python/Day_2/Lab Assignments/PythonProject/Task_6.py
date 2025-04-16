def alphOrder(nums):
    longest = current = nums[0]

    for i in range(1, len(nums)):
        if nums[i] >= nums[i - 1]:
            current += nums[i]
        else:
            if len(current) > len(longest):
                longest = current
            current = nums[i]

    if len(current) > len(longest):
        longest = current

    return longest

try:
    inputText = input("Enter a Text: ")
    print(f"Longest substring in alphabetical order of {inputText} is : {alphOrder(inputText)}")
except ValueError:
    print("Invalid input")


# abdulrahman
