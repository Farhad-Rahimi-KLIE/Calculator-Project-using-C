#include <stdio.h>
#include <time.h>

void Calculate_Logs(float first, char operand, float second, float result){
    static int logs_number = 0;
    logs_number++;
    FILE* ptr = fopen("logs.txt", "a+w");
    if (ptr == NULL)
    {
        printf("Error Opening File \n");
    }
    time_t t;
    time(&t);
    fprintf(ptr, "Your Log number %d is Ready : \n", logs_number);
    fprintf(ptr, "First Number is : %2.f \n", first);
    fprintf(ptr, "Operand is : %c \n", operand);
    fprintf(ptr, "Second Number is : %2.f \n", second);
    fprintf(ptr, "Result is : %2.f \n", result);
    fprintf(ptr, "Time is : %s \n", ctime(&t));
    fprintf(ptr, "*********************************** \n");


    fclose(ptr);
}

float Sum(float first, float second){
    return first + second;
}

float Substract(float first, float second){
    return first - second;
}

float Multiplay(float first, float second){
    return first * second;
}

float Divide(float first, float second){
    return first / second;
}

int main()
{
    float first_number, second_number, result;
    char operand, choice;

    do
    {

    printf("Welcome to farhad rahimi klie Calculator using C \n");

    printf("please enter your first number  ");
    scanf("%f", &first_number);

    printf("please enter your Operand (+, -, *, /) ");
    scanf(" %c", &operand);

    printf("please enter your second number  ");
    scanf("%f", &second_number);

    switch (operand)
    {
    case '+':
        result = Sum(first_number, second_number);
        break;
    case '-':
        result = Substract(first_number, second_number);
        break;
    case '*':
        result = Multiplay(first_number, second_number);
        break;
    case '/':
        result = Divide(first_number, second_number);
        break;
    default:
       printf("please enter valid data...");
        break;
    }

    printf("First Number is : %.2f \n", first_number);
    printf("Operand is : %c \n", operand);
    printf("Second Number is : %.2f \n", second_number);
    printf("Result of both is : %.2f \n", result);

    Calculate_Logs(first_number, operand, second_number, result);

    printf("Want to Continue ? (y / n) ");
    scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    printf("Game Over \n");
    return 0;
}