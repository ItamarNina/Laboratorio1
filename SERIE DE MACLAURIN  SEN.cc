#include <iostream>
#include <limits>
#include <math.h>


using namespace std;

int fact (int x)
{
    int F = 1;
    for (int i = 1; i <= x; i++)
    {
        F = F*i;
    }
    return F;
}

int main()
{
    cout<<"SERIE DE MACLAURIN DEL SENO\n";
    cout<<"El limite de caracteres del primero es: 15 - 0 y del segundo es: +/-360.000\n";
    int a=0;
    while (true)        //Para la verificacion de datos
    {
        cout << "Escriba el numero de terminos: ";
        cin >> a;
        if (cin.fail()) // Si nada se pone será verdadero
        {   cout<<"Caracter invalido\n";
            cin.clear(); // Para resetear los bits
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            //ignore() es usado para limpiar los datos incorrectos
            continue; // El ciclo iniciará de nuevo
        }
        //Para limpiar datos adicionales como: atr15 (atr es adicional)
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        // Remueve los datos adicionales de la entrada de datos
        if (cin.gcount() > 1) 
        // Devolvera mas de 1 si hay algun sobrante de datos invalidos
        {   cout<<"Caracter invalido, no te pases de listo\n";
            continue; // el ciclo iniciará de nuevo
        }
        if (a>15 || a<=0)       //poniendo limite al numero de caracteres escritos
        {   cout<<"Limite de caracteres alcanzado\n";
            continue;   //el ciclo iniciará de nuevo
        }
        break; //rompe el ciclo
    }
    float b=0;
    while (true)        //Para la verificacion de datos
    {
        cout << "Escriba el valor del angulo: ";
        cin >> b;
        if (cin.fail()) // Si nada se pone será verdadero
        {   cout<<"Caracter invalido\n";
            cin.clear(); // Para resetear los bits
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            //ignore() es usado para limpiar los datos incorrectos
            continue; // El ciclo iniciará de nuevo
        }
        //Para limpiar datos adicionales como: atr15 (atr es adicional)
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        // Remueve los datos adicionales de la entrada de datos
        if (cin.gcount() > 1) 
        // Devolvera mas de 1 si hay algun sobrante de datos invalidos
        {   cout<<"Caracter invalido, no te pases de listo\n";
            continue; // el ciclo iniciará de nuevo
        }
        if (b>360||b<-360)       //poniendo limite al numero de caracteres escritos
        {   cout<<"Limite de caracteres alcanzado\n";
            continue;   //el ciclo iniciará de nuevo
        }
        break; //rompe el ciclo
    }
    float B = b*0.01745329252;
    double seno = 0;

    for (int k = 0; k < a; k++)
    {
        seno = seno + (pow(-1, k)*pow(B, (2*k)+1)) / fact((2*k)+1);
    }
    cout<<"\n"<<"El Sin de ("<<b<<") es "<<seno<<endl;
    system("pause");
    return 0;
}