//! ------------------------------------------
//TODO                Q1
// --------------------------------------------
const Arr: (string | number)[] = [2, 1, "Sheto", 3];

//! ------------------------------------------
//TODO                Q1-SUB1
//! --------------------------------------------
function arrCheck(arrParam: (string | number)[]) {
    // var flag ;
    var sum: number = 0;
    var text: string = "";
    if (arrParam.every((element) => typeof element === "number")) {
        for (let index = 0; index < arrParam.length; index++) {
            sum += arrParam[index];
        }
        return sum;
    } else if (arrParam.every((element) => typeof element === "string")) {
        text = arrParam.join(" ");
        return text;
    } else {
        var arrAfterFilter: number[] = arrParam.filter(
            (element) => typeof element === "number"
        );
        arrAfterFilter.sort((a, b) => a - b);
        return arrAfterFilter;
        // console.log("🚀💥 --> arrCheck --> arrAfterFilter:", arrAfterFilter);
    }
}
console.log(arrCheck(Arr));

// !------------------------------------------
//TODO                Q2
// !--------------------------------------------

abstract class Shape {
    abstract getArea(): number;
}

class Rectangle extends Shape {
    constructor(private w: number, private h: number) {
        super();
    }
    getArea() {
        return this.w * this.h;
    }
}

class Circle extends Shape {
    constructor(private r: number) {
        super();
    }
    getArea() {
        return Math.PI * this.r * this.r;
    }
}

//!------------------------------------------
//TODO                Q3
//!--------------------------------------------
interface IEmployee {
    id: number;
    fname: string;
    lname: string;
    age: number;
    salary: number;
    address: {city: string; street: string};
    getSalary(): number;
}

class Employee implements IEmployee {
    constructor(
        public id: number,
        public fname: string,
        public lname: string,
        public age: number,
        public salary: number,
        public address: {city: string; street: string}
    ) {}
    getSalary() {
        return this.salary;
    }
}

//!------------------------------------------
//TODO                Q4
//!--------------------------------------------

class Manager extends Employee {
    showData(empId: number) {
        if (this.id === empId)
            console.log(
                `${this.fname} ${this.lname}, Age: ${this.age}, Salary: ${this.salary}`
            );
    }
}

const employee = new Employee(1, "mahmoud", "Shetawy", 23, 50000, {
    city: "shebeen",
    street: "5 paris",
});
console.log(employee.getSalary());

const manager = new Manager(1, "mahmoud", "Shetawy", 23, 50000, {
    city: "shebeen",
    street: "5 paris",
});
manager.showData(1);

//!------------------------------------------
//TODO                Q4
//!--------------------------------------------

enum weekDay {
    Sat,
    Sun,
    Mon,
    Tue,
    Wed,
    Thu,
    Fri,
}

function dayIsWeekend(day: weekDay): boolean {
    return day === weekDay.Fri || day === weekDay.Sat;
}

console.log(dayIsWeekend(weekDay.Sat));
console.log(dayIsWeekend(weekDay.Mon));
