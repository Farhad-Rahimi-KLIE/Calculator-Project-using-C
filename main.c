#include <stdio.h>

float SumNumbers(float first, float second){
    return first + second;
}

float SubstracNumbers(float first, float second){
    return first - second;
}

float MultiplayNumbers(float first, float second){
    return first * second;
}

float DivideNumbers(float first, float second){
    return first / second;
}

int main()
{
    float first_number, second_number, result;
    char Operand, choice;
    do
    {
        printf("Welcome to Farhad Rahimi Klie Calculator... \n");
        printf("Enter your First Number ");
        scanf("%f", &first_number);

        printf("Enter your Operand (+, -, *, /) ");
        scanf(" %c", &Operand);
        
        printf("Enter your Second Number ");
        scanf("%f", &second_number);



        switch (Operand)
        {
        case '+':
            result = SumNumbers(first_number, second_number);
            break;
        case '-':
            result = SubstracNumbers(first_number, second_number);
            break;
        case '*':
            result = MultiplayNumbers(first_number, second_number);
            break;
        case '/':
            result = DivideNumbers(first_number, second_number);
            break;    
        default:
            printf("Please Enter valid Integers...");
            break;
        }
        printf("\n");
        printf("First Number is : %.2f \n", first_number);
        printf("************* \n");

        printf("Operand is : %c \n", Operand);
        printf("************* \n");

        printf("Second Number is : %.2f \n", second_number);
        printf("************* \n");

        printf("The Result is : %.2f \n", result);
        printf("****************** \n");

        printf("\n");

        printf("want to continue ? (y / n)");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    printf("game is over \n");
    return 0;
}