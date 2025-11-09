#include <stdio.h>
#include <time.h>
#include <sqlite3.h>

sqlite3* database_setup;

void CreateTable(){
    char* err;
    const char* sql = "CREATE TABLE IF NOT EXISTS logs("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "first_num REAL,"
                      "operator TEXT,"
                      "second_num REAL,"
                      "result REAL,"
                      "time TEXT);";
    if (sqlite3_exec(database_setup, sql,0,0, &err) != SQLITE_OK)
    {
        printf("Error Creating Tables \n", err);
    }
}

void Save_Logs(float first, char operand, float second, float result) {
    char* err;
    time_t t;
    time(&t);
    char* time_str = ctime(&t);
    char sql[200];
    sprintf(sql, "INSERT INTO logs (first_num, operator, second_num, result, time) "
                 "VALUES (%f, '%c', %f, %f, '%s');",
                 first, operand, second, result, time_str);
    if (sqlite3_exec(database_setup, sql, 0, 0, &err) != SQLITE_OK) {
        printf("Insert Error: %s\n", err);
    }
}

// void Calculate_Logs(float first, char operand, float second, float result){
//     static int logs_number = 0;
//     logs_number++;
//     FILE* ptr = fopen("logs.txt", "a+w");
//     if (ptr == NULL)
//     {
//         printf("Error Opening File \n");
//     }
//     time_t t;
//     time(&t);
//     fprintf(ptr, "Your Log number %d is Ready : \n", logs_number);
//     fprintf(ptr, "First Number is : %2.f \n", first);
//     fprintf(ptr, "Operand is : %c \n", operand);
//     fprintf(ptr, "Second Number is : %2.f \n", second);
//     fprintf(ptr, "Result is : %2.f \n", result);
//     fprintf(ptr, "Time is : %s \n", ctime(&t));
//     fprintf(ptr, "*********************************** \n");


//     fclose(ptr);
// }

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

    int return_code = sqlite3_open("calculator_logs.db",&database_setup);
    if (return_code != SQLITE_OK)
    {
        printf("File not Open there.", sqlite3_errmsg(database_setup));
    }
    printf("Database Connected Successfully.");
    CreateTable(); // ساخت جدول
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

    Save_Logs(first_number, operand, second_number, result);

    printf("Want to Continue ? (y / n) ");
    scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');


    sqlite3_close(database_setup);
    printf("Game Over \n");
    return 0;
}

