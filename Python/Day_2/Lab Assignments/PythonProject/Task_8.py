import re

def is_valid_email(email):
    pattern = r'^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$'
    return re.match(pattern, email) is not None

def check_valid_name():
    while True:
        name = input("Enter your name: ")
        if name and not name.isdigit():
            return name
        print("Invalid name! Please enter a valid name.")

def check_valid_email():
    while True:
        email = input("Enter your email: ")
        if is_valid_email(email):
            return email
        print("Invalid email! Please enter a valid email.")

name = check_valid_name()
email = check_valid_email()

print("User Info:")
print(f"Name: {name}")
print(f"Email: {email}")
