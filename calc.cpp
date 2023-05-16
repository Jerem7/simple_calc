#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

char operation;
int ilosc_liczb;
double result = 0;
double number;
void menu(), blad();

int main()
{
    while (true)
    {
        menu();
        cin >> operation;
        if (operation == 'q')
            break;
        else if (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '^' && operation != 's')
        {
            blad();
            continue;
        }
        cout << "Ile liczb bedzie uzytych w obliczeniach?\n";
        cin >> ilosc_liczb;
        while (!cin || ilosc_liczb < 1)
        {
            blad();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> ilosc_liczb;
        }
        for (int i = 0; i < ilosc_liczb; i++)
        {
            cout << "Podaj liczbe nr " << i + 1 << ": ";
            cin >> number;
            if (i > 0)
            {
                menu();
                cin >> operation;
                if (operation == 'q')
                    break;
                else if (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '^' && operation != 's')
                {
                    blad();
                    continue;
                }
            }
            if (operation == '+')
                result += number;
            else if (operation == '-')
                result -= number;
            else if (operation == '*')
            {
                if (i == 0)
                    result = number;
                else
                    result *= number;
            }
            else if (operation == '/')
            {
                if (i == 0)
                    result = number;
                else
                    result /= number;
            }
            else if (operation == '^')
            {
                if (i == 0)
                    result = number;
                else
                {
                    int power;
                    cout<<"Podaj wykladnik ";
                    cin>>power;
                    double temp = number;
                    for(int i=1; i<power; i++)
                        temp *= number;
                    result *= temp;
                }
            }
            else if (operation == 's')
            {
                if (i == 0)
                    result = number;
                else
                {
                    int root;
                    cout<<"Podaj stopien pierwiastka ";
                    cin>>root;
                    double temp = 1.0/root;
                    double original_result = result;
                    for(int i = 1; i < root; i++)
                        result *= original_result;
                }
            }
        }
        cout << "Wynik: " << result << endl;
        result = 0;
    }
}
void menu()
{
    cout << "Podaj, jaka operacje chcesz wykonac: \n+ dla dodawania. \n- dla odejmowania. \n* dla mnozenia. \n/ dla dzielenia. \n^ dla potegowania. \ns dla pierwiastokwania.\nq dla wyjscia z programu.\n";
}
void blad()
{
    cout << "Nieprawidlowy wybor. Prosze wybrac ponownie.\n";
}
