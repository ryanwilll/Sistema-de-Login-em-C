#include <stdio.h> //Padrão
#include <stdlib.h> //Padrão
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

typedef struct{
    char login[30]; // vetor login da struct pessoa
    char senha[30]; // vetor senha da struct pessoa
} pessoa; pessoa p[1];  // diminuindo o nome da struct para "p" e o "[1]" é o máximo de pessoas com logins e senhas


int main()
{
    // Esse sistema de login foi utilizado para criar um sistema hospital, por isso o título.
    printf("\t\t\t\t************************************************\n");
    printf("\t\t\t\t*            SISTEMA HOSPITALAR DE             *\n");
    printf("\t\t\t\t*          GERENCIAMENTO DE PACIENTES          *\n");
    printf("\t\t\t\t************************************************\n");
    int n1,n2;
    char login[30]; // responsável por armazenar o login inserida pelo usuário
    char senha[30]; // responsável por armazenar a senha inserida pelo usuário

    strcpy(p[0].login, "admin"); // Definindo o login "admin" na struct
    strcpy(p[0].senha, "admin"); // Definindo a senha "admin"  na struct

    /*system("cls"); Clear para o CMD (Windows) */

    printf("\nInforme o seu Login: ");
    scanf("%s", login);

    char buffer[256] = {0};
    char c;
    int pos = 0;

    printf("%s", "Informe sua Senha: ");
    do {
        c = getch();

        if( isprint(c) )
        {
            buffer[ pos++ ] = c;
            printf("%c", '*');
        }
        else if( c == 8 && pos )
        {
            buffer[ pos-- ] = '\0';
            printf("%s", "\b \b");
        }
    } while( c != 13 );

    if((strcmp(login,p[0].login)==0) && (strcmp(buffer,p[0].senha)==0)){
        Beep(1200,200);
        system("cls");
        printf("Logado!");
    }else{
        Beep(565,600);

        printf("\n\t\t\t\t\tLogin e/ou senha incorretos\n\n");
        Sleep(1000);
        system("cls");
        return main();
    }
    getch();
};
