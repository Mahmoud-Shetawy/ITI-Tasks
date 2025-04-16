class Person:
    def __init__(self, name, money, mood, health_rate):
        self.name = name
        self.money = money
        self.mood = mood
        self.health_rate = max(0, min(100, health_rate))
    
    def sleep(self, hours):
        if hours == 7:
            self.mood = "Happy"
        elif hours < 7:
            self.mood = "Tired"
        else:
            self.mood = "Lazy"
        print(f"{self.name} is {self.mood} after sleeping {hours} hours.")
    
    def eat(self, meals):
        if meals == 3:
            self.health_rate = 100
        elif meals == 2:
            self.health_rate = 75
        elif meals == 1:
            self.health_rate = 50
        print(f"{self.name}'s health rate is {self.health_rate}% after eating {meals} meals.")
    
    def buy(self, items):
        self.money -= items * 10
        print(f"{self.name} bought {items} items. Remaining money: {self.money} L.E")

class Car:
    def __init__(self, name, fuel_rate, velocity):
        self.name = name
        self.fuel_rate = max(0, min(100, fuel_rate))
        self.velocity = max(0, min(200, velocity))
    
    def run(self, velocity, distance):
        self.velocity = max(0, min(200, velocity))
        self.fuel_rate -= distance * 0.1
        if self.fuel_rate <= 0:
            self.stop(remaining_distance=distance)
        else:
            print(f"Car {self.name} is running at {self.velocity} km/h with fuel rate {self.fuel_rate}%")
    
    def stop(self, remaining_distance=0):
        self.velocity = 0
        if remaining_distance > 0:
            print(f"Car {self.name} stopped before reaching destination. Remaining distance: {remaining_distance} km")
        else:
            print(f"Car {self.name} has arrived at the destination.")

class Employee(Person):
    def __init__(self, name, money, mood, health_rate, emp_id, car, email, salary, distance_to_work):
        super().__init__(name, money, mood, health_rate)
        self.emp_id = emp_id
        self.car = car
        self.email = email
        self.salary = salary
        self.distance_to_work = distance_to_work
    
    def work(self, hours):
        if hours == 8:
            self.mood = "Happy"
        elif hours < 8:
            self.mood = "Lazy"
        else:
            self.mood = "Tired"
        print(f"{self.name} is {self.mood} after working {hours} hours.")
    
    def drive(self, distance):
        self.car.run(velocity=self.car.velocity, distance=distance)
    
    def refuel(self, gas_amount=100):
        self.car.fuel_rate = max(0, min(100, self.car.fuel_rate + gas_amount))
        print(f"Car {self.car.name} refueled. Fuel rate: {self.car.fuel_rate}%")
    
    def send_mail(self, recipient, subject, message):
        print(f"Sending email to {recipient}\nSubject: {subject}\nMessage: {message}")

class Office:
    employees_num = 0
    
    def __init__(self, name):
        self.name = name
        self.employees = []
    
    def get_all_employees(self):
        return self.employees
    
    def get_employee(self, emp_id):
        for emp in self.employees:
            if emp.emp_id == emp_id:
                return emp
        return None
    
    def hire(self, employee):
        self.employees.append(employee)
        Office.employees_num += 1
        print(f"Hired {employee.name}. Total employees: {Office.employees_num}")
    
    def fire(self, emp_id):
        employee = self.get_employee(emp_id)
        if employee:
            self.employees.remove(employee)
            Office.employees_num -= 1
            print(f"Fired {employee.name}. Total employees: {Office.employees_num}")
    
    def deduct(self, emp_id, deduction):
        employee = self.get_employee(emp_id)
        if employee:
            employee.salary -= deduction
            print(f"Deducted {deduction} L.E from {employee.name}. New salary: {employee.salary}")
    
    def reward(self, emp_id, reward):
        employee = self.get_employee(emp_id)
        if employee:
            employee.salary += reward
            print(f"Rewarded {reward} L.E to {employee.name}. New salary: {employee.salary}")
    
    def check_lateness(self, emp_id, move_hour):
        employee = self.get_employee(emp_id)
        if employee:
            is_late = Office.calculate_lateness(9, move_hour, employee.distance_to_work, employee.car.velocity)
            if is_late:
                self.deduct(emp_id, 10)
            else:
                self.reward(emp_id, 10)
    
    @staticmethod
    def calculate_lateness(target_hour, move_hour, distance, velocity):
        arrival_time = move_hour + (distance / velocity)
        return arrival_time > target_hour
    
    @classmethod
    def change_emps_num(cls, num):
        cls.employees_num = num
        print(f"Total employees updated to {cls.employees_num}")

# Example Usage
office = Office("TechCorp")
car1 = Car("Toyota", 80, 100)
emp1 = Employee("Alice", 5000, "Happy", 100, 1, car1, "alice@mail.com", 2000, 10)

office.hire(emp1)
emp1.work(9)
emp1.eat(2)
emp1.sleep(7)
emp1.drive(5)
emp1.refuel(20)
office.check_lateness(1, 7)
office.fire(1)
