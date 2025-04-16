var __extends = (this && this.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (Object.prototype.hasOwnProperty.call(b, p)) d[p] = b[p]; };
        return extendStatics(d, b);
    };
    return function (d, b) {
        if (typeof b !== "function" && b !== null)
            throw new TypeError("Class extends value " + String(b) + " is not a constructor or null");
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
//! ------------------------------------------
//TODO                Q1
// --------------------------------------------
var Arr = [2, 1, "Sheto", 3];
//! ------------------------------------------
//TODO                Q1-SUB1
//! --------------------------------------------
function arrCheck(arrParam) {
    // var flag ;
    var sum = 0;
    var text = "";
    if (arrParam.every(function (element) { return typeof element === "number"; })) {
        for (var index = 0; index < arrParam.length; index++) {
            sum += arrParam[index];
        }
        return sum;
    }
    else if (arrParam.every(function (element) { return typeof element === "string"; })) {
        text = arrParam.join(" ");
        return text;
    }
    else {
        var arrAfterFilter = arrParam.filter(function (element) { return typeof element === "number"; });
        arrAfterFilter.sort(function (a, b) { return a - b; });
        return arrAfterFilter;
        // console.log("🚀💥 --> arrCheck --> arrAfterFilter:", arrAfterFilter);
    }
}
console.log(arrCheck(Arr));
// !------------------------------------------
//TODO                Q2
// !--------------------------------------------
var Shape = /** @class */ (function () {
    function Shape() {
    }
    return Shape;
}());
var Rectangle = /** @class */ (function (_super) {
    __extends(Rectangle, _super);
    function Rectangle(w, h) {
        var _this = _super.call(this) || this;
        _this.w = w;
        _this.h = h;
        return _this;
    }
    Rectangle.prototype.getArea = function () {
        return this.w * this.h;
    };
    return Rectangle;
}(Shape));
var Circle = /** @class */ (function (_super) {
    __extends(Circle, _super);
    function Circle(r) {
        var _this = _super.call(this) || this;
        _this.r = r;
        return _this;
    }
    Circle.prototype.getArea = function () {
        return Math.PI * this.r * this.r;
    };
    return Circle;
}(Shape));
var Employee = /** @class */ (function () {
    function Employee(id, fname, lname, age, salary, address) {
        this.id = id;
        this.fname = fname;
        this.lname = lname;
        this.age = age;
        this.salary = salary;
        this.address = address;
    }
    Employee.prototype.getSalary = function () {
        return this.salary;
    };
    return Employee;
}());
//!------------------------------------------
//TODO                Q4
//!--------------------------------------------
var Manager = /** @class */ (function (_super) {
    __extends(Manager, _super);
    function Manager() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    Manager.prototype.showData = function (empId) {
        if (this.id === empId)
            console.log("".concat(this.fname, " ").concat(this.lname, ", Age: ").concat(this.age, ", Salary: ").concat(this.salary));
    };
    return Manager;
}(Employee));
var employee = new Employee(1, "mahmoud", "Shetawy", 23, 50000, {
    city: "shebeen",
    street: "5 paris",
});
console.log(employee.getSalary());
var manager = new Manager(1, "mahmoud", "Shetawy", 23, 50000, {
    city: "shebeen",
    street: "5 paris",
});
manager.showData(1);
//!------------------------------------------
//TODO                Q4
//!--------------------------------------------
var Weekday;
(function (Weekday) {
    Weekday[Weekday["Sat"] = 0] = "Sat";
    Weekday[Weekday["Sun"] = 1] = "Sun";
    Weekday[Weekday["Mon"] = 2] = "Mon";
    Weekday[Weekday["Tue"] = 3] = "Tue";
    Weekday[Weekday["Wed"] = 4] = "Wed";
    Weekday[Weekday["Thu"] = 5] = "Thu";
    Weekday[Weekday["Fri"] = 6] = "Fri";
})(Weekday || (Weekday = {}));
function dayIsWeekend(day) {
    return day === Weekday.Fri || day === Weekday.Sat;
}
console.log(dayIsWeekend(Weekday.Sat));
console.log(dayIsWeekend(Weekday.Mon));
