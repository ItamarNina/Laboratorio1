#include <iostream>
#include <limits>   //Para usar informacion de propiedades aritmeticas, como max()
//Basicamente es para el codigo de la verificacion de datos
#include <cmath>    //Para usar funciones matematicas
using namespace std;

int main()
{
    cout<<"CALCULADORA DE ECUACIONES CUADRATICAS\n";
    cout<<"(A)x^2 + (B)x + C = 0\n";
    cout<<"El limite de caracteres es el siguiente: +/-999.999\n";
    //Abajo esta la introduccion de datos y la verificacion de los mismos
    //Me hubiera gustado usar una sola verificacion de datos con la funcion void (){}
    //Y que cada vez entregue datos con un diferente nombre, como x, y o z.
    double a;       //primer coeficiente
    while (true)        //Para la verificacion de datos
    {
        cout << "Escriba el numero A: ";
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
        if (a>999.999||a<-999.999)       //poniendo limite al numero de caracteres escritos
        {   cout<<"Limite de caracteres alcanzado\n";
            continue;   //el ciclo iniciará de nuevo
        }
        break; //rompe el ciclo
    }
    cout<<"("<<a<<")x^2 + (B)x + C = 0\n";
    double b;       //segundo coeficiente
    while (true)        //Para la verificacion de datos
    {
        cout << "Escriba el numero B: ";
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
        if (b>999.999||b<-999.999)       //poniendo limite al numero de caracteres escritos
        {   cout<<"Limite de caracteres alcanzado\n";
            continue;   //el ciclo iniciará de nuevo
        }
        break; //rompe el ciclo
    }
    cout<<"("<<a<<")x^2 + ("<<b<<")x + C = 0\n";
    double c;       //tercer coeficiente
    while (true)        //Para la verificacion de datos
    {
        cout << "Escriba el numero C: ";
        cin >> c;
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
        if (c>999.999||c<-999.999)       //poniendo limite al numero de caracteres escritos
        {   cout<<"Limite de caracteres alcanzado\n";
            continue;   //el ciclo iniciará de nuevo
        }
        break; //rompe el ciclo
    }
    cout<<"("<<a<<")x^2 + ("<<b<<")x + ("<<c<<") = 0\n";
    cout<<"\n";
    //Lo siguiente es la obtencion de las soluciones reales o imaginarias
    double D = pow(b,2) - (4*a*c);   //D es la determinante
    if (D>=0)                   
    {
        if (a == 0 && b == 0)     //Casos especiales
        {
            if (c == 0)
            {
                cout<<"Hay soluciones infinitas\n";
            } else
            {
                cout<<"No tiene solucion\n";
            }
        } else   //Si cumple y no es como los casos anteriores son soluciones reales
        {
            double x1 = (-b + sqrt(D)) / (2*a);      //Se calcula cada solucion real
            double x2 = (-b - sqrt(D)) / (2*a);
            if (x1 == x2)                       //Si D = 0 hay una sola solucion
            {
            cout<<"La unica solucion es: "<<x1<<"\n";
            } else                  //Si D es positiva 
            {
            cout<<"La primera solucion es: "<<x1<<"\n";
            cout<<"La segunda solucion es: "<<x2<<"\n";   
            }
        }
    } else                      //Si no cumple son soluciones imaginarias
    {
        double xIm = (sqrt(-D)) / (2*a);       //La parte imaginaria de la solucion
        double xRe = (-b) / (2*a);           //La parte real de la solucion
        cout<<"La primera solucion es: "<<xRe<<" + ("<<xIm<<")i\n";
        cout<<"La segunda solucion es: "<<xRe<<" - ("<<xIm<<")i\n";
    }
    system("pause");
    return 0;
}