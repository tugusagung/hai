#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

void option(), clear();
float input(), addition(), subtract(), multiply(), divide();
int modulus();
bool again();

float f1, f2, result, userInput;
int i1, i2, result2, ret;
char tmp, opt, start[10], x;

int main()
{
    system("cls");
    option();
    
    printf("\nChoose option : ");
    scanf("%c", &opt);
    
    if (getchar() != '\n'){
        clear();
        main();
        return 0;
    }

    x = tolower(opt);
        switch(x)
        {
            case '1':
            system("cls");
                result = addition();
                printf("Result : %g\n", result);
                if (again()){
                    clear();
                    main();
                }
                break;
            case '2':
            system("cls");
                result = subtract();
                printf("Result : %g\n", result);
                if (again()){
                    clear();
                    main();
                }
                break;
            case '3':
            system("cls");
                result = multiply();
                printf("Result : %g\n", result);
                if (again()){
                    clear();
                    main();
                }
                break;
            case '4':
            system("cls");
                result = divide();
                if (result == 'x'){
                    result = divide();
                }
                printf("Result : %g\n", result);
                if (again()){
                    clear();
                    main();
                }
                break;
            case '5':
            system("cls");
                result2 = modulus();
                if (result2 == 'x'){
                    result2 = modulus();
                }
                printf("Result : %i\n", result2);
                if (again()){
                    clear();
                    main();
                }
                break;
            case 'x' :
            system("cls");
                return 0;
                break;
        }
    return 0;
}

void option(){
    printf(",____________________________,\n");
    printf("|                            |\n");
    printf("|     Select Your Option     |\n");
    printf("|____________________________|\n");
    printf("|                            |\n");
    printf("| 1 = Addition               |\n");
    printf("| 2 = Subctraction           |\n");
    printf("| 3 = Multiplication         |\n");
    printf("| 4 = Division               |\n");
    printf("| 5 = Modulus                |\n");
    printf("| X = Exit                   |\n");
    printf("|____________________________|\n");
}

float input(){
    if (scanf("%f", &userInput) == 0){
        printf("Please put a valid integer : ");
        clear(); 
        userInput = input();
        return userInput;
    }
    else{
        if (getchar() != '\n'){
            clear();
            printf("Please put a valid integer : ");
            userInput = input();
            return userInput;
        }
        return userInput;
    }
}
void clear(){
    do
    {
        tmp = getchar();
    }
    while (tmp != '\n');
}

bool again(){
    printf("\nDo you want to start the program again? (y/n)\n");
    scanf("%s", &start);
    if (strlen(start) == 1){
        if (start[0] == 'y' || start[0] == 'Y'){
            return 1;
        }
        else if (start[0] == 'n' || start[0] == 'N'){
            return 0;
        }
    }
    system("cls");
    ret = again();
    return ret;
}

float addition(){
    printf(",____________________________,\n");
    printf("|                            |\n");
    printf("|          Addition          |\n");
    printf("|____________________________|\n\n");

    printf("Add the first number : ");
        f1 = input();
    printf("Add the second number : ");
        f2 = input();
    return f1 + f2;
}

float subtract(){
    printf(",____________________________,\n");
    printf("|                            |\n");
    printf("|        Subctraction        |\n");
    printf("|____________________________|\n\n");

    printf("Add the first number : ");
        f1 = input();
    printf("Add the second number : ");
        f2 = input();
    return f1 - f2;
}

float multiply(){
    printf(",____________________________,\n");
    printf("|                            |\n");
    printf("|       Multiplication       |\n");
    printf("|____________________________|\n\n");

    printf("Add the first number : ");
        f1 = input();
    printf("Add the second number : ");
        f2 = input();
    return f1 * f2;
}

float divide(void){
    printf(",____________________________,\n");
    printf("|                            |\n");
    printf("|          Division          |\n");
    printf("|____________________________|\n\n");

    printf("Add the first number : ");
        f1 = input();
    printf("Add the second number : ");
        f2 = input();
        if (f2 == 0){
            system("cls");
            printf("Division by zero is not allowed\n");
            return 'x';
        }
    return f1 / f2;
}

int modulus(){
    printf(",____________________________,\n");
    printf("|                            |\n");
    printf("|          Modulus           |\n");
    printf("|____________________________|\n\n");

    printf("Add the first number : ");
        i1 = (int) input();
    printf("Add the second number : ");
        i2 = (int) input();
    
    if (i2 == 0){
        system("cls");
        printf("Modulus by zero is not allowed\n");
        return 'x';
    }
    return i1 % i2;
}