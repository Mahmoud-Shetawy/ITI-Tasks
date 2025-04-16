class Person :
    def __init__(self,name , money , mood , healthRate):
        self.name = name 
        self.money = money 
        self.mood = mood 
        self.healthRate = healthRate   
        pass
    def sleep(self,hours) :
        if(hours ==  7 ) :
            self.mood = 'happy '
        elif(hours < 7 ) :
            self.mood = "lazy"
        else :
            self.mood = "tired"
     
    def eat (self , meals) :
        if(meals == 3 ) :
            self.healthRate = 100
        elif(meals == 2) :
            self.healthRate = 75
        elif(meals == 1 ) :
            self.healthRate = 50
    
    def buy (self,items) :
         self.money -= items * 10
            
        
    
class Employee(Person) :
    def __init__(self, name, money, mood, healthRate,id , car , email , salary , distance_to_work):
        super().__init__(name, money, mood, healthRate)
        self.id = id 
        self.car = car 
        self.email = email 
        self.salary = salary
        self.distance_to_work = distance_to_work
        pass
    def work (self,hours):
        if(hours ==  8) :
            self.mood = 'happy '
        elif(hours < 8 ) :
            self.mood = "lazy"
        else :
            self.mood = "tired"
    
class Office : 
    def __init__(self,name , employees):
        self.name = name 
        self.employees = employees 
        pass
class Car :
    def __init__(self,name, fuel_rate,velocity):
        self.name = name 
        self.fuel_rate = max(0, min(100, fuel_rate))
        self.velocity = max(0, min(200, velocity))
    
        pass
    def run (self ,velocity , distance ):
        if self.fuel_rate <= 0:
            print("Car has no fuel. Please refuel.")
            return
        self.velocity = max(0, min(200, velocity))  # Ensure valid velocity
        fuel_consumption = distance * 2  # Example: Each km reduces fuel by 2%

        if self.fuel_rate >= fuel_consumption:
            self.fuel_rate -= fuel_consumption
            print(f"Car ran {distance} km at {self.velocity} km/h. Remaining fuel: {self.fuel_rate}%")
            self.stop(0)  # Destination reached
        else :
            max_distance = self.fuel_rate / 2  # Maximum possible distance
            print(f"Car ran out of fuel after {max_distance} km!")
            self.fuel_rate = 0
            self.stop(distance - max_distance)  # Remaining distance to cover
    def stop(self, remaining_distance):
        """Stops the car and prints if it arrived or not."""
        self.velocity = 0
        if remaining_distance > 0:
            print(f"Car stopped with {remaining_distance} km left to reach the destination!")
        else:
            print("Car arrived at the destination!")