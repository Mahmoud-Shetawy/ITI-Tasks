#include <stdio.h>
double add(double num1 ,double num2){

  return num1 + num2;
}
double Sub(double num1 ,double num2){

  return num1 - num2;
}
double MUL(double num1 ,double num2){

  return num1 * num2;
}
double Div(double num1 ,double num2){

  return num1 / num2;
}

int main() {
    double number1, number2, result;
    char operator;
    int flag = 1 , check = 1;
    do {
        printf("Please, enter Number1: ");
        scanf("%lf", &number1);
         _flushall();
        printf("Please, enter Number2: ");
        scanf("%lf", &number2);
         _flushall();

        printf("Please, enter operator (+, -, *, /): ");
        scanf(" %c", &operator);

        switch (operator) {
            case '+':
                  result =add(number1 , number2);
                check = 1;
                break;
            case '-':
               result =Sub(number1 , number2);
                check = 1;
                break;
            case '*':
                result = MUL(number1 , number2);
                check = 1;
                break;
            case '/':
                if(number2 !=0){
                   result = Div(number1 , number2);
                    }else{
                    printf("Error!!!!!!!!");
                    check = 0;
                    }
                break;
            default:
                printf("Please use +, -, * \n");
                check = 0;
                break;
        }
        if(check)
            printf("%lf %c %lf = %lf \n", number1,operator ,number2, result);


    printf("\nYou want to repeat the operation(yes = 1 or No = 0) : ");
    scanf("%i", &flag);
}while(flag);

    return 0;
}
