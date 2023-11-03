#include <stdio.h>
#include <cs50.h> //Biblioteca do CS50

int main(void)
{
    string  name;

    name = get_string("Qual é seu nome? \n");
    //get_string é uma funcão específica da bilbioteca do CS50
    printf("hello, %s \n", name);
}