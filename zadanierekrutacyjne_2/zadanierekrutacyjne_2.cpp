#include <iostream>

using namespace std;

void wyjscie(int n, double x[], double y[], int zycie[]);

/*
Każdy punkt w układzie współrzędnych ma 4 życia. Potrzebujemy tylko te punkty, które są krawędziami figury, która otoczy resztę punktów.
Dlatego funkcja ta porównuje jeden punkt z całą resztą wprowadzonych punktów.
I jeżeli znajdzie się x, który jest bardziej na prawo od obranego punktu to wtedy traci jedno życie.
Jeżeli znajdzie się x, który jest bardziej na lewo obranego punktu to wtedy traci kolejne życie.
Analogicznie jest z y, jeśli znajdzie się punkt który ma wyżej y to traci kolejne, albo jak znajdzie sie punkt który ma niżej y to znowu traci życie.
I w taki sposób eliminujemy punkty wewnętrzne. I wtedy zostają punkty krawędziowe, którym zostało conajmniej jedno życie.
*/
void eliminacja_punktow_wewnetrzych(int n, double x[], double y[], int zycie[])
{
    //flaga oznaczająca, że jeśli jakiś inny punkt jest na prawo od wybranego punktu to dostaje wartość true
    bool x_prawy; 
    //flaga oznaczająca, że jeśli jakiś inny punkt jest na lewo wzgledem osi x od wybranego punktu to zwraca wartość true
    bool x_lewy;
    //flaga oznaczająca, że jeśli y jakiegoś punktu jest powyżej y wybranego to wtedy zwraca wartość true
    bool y_gorny;
    //flaga oznaczająca, że jeśli y jakiegoś punktu jest poniżej y wybranego to wtedy zwraca wartość true
    bool y_dolny;
    

    for (int i = 0; i < n; i++)
    {
        //przyznanie wszystkim flagom wartości false
        x_prawy = false;
        x_lewy = false;
        y_gorny = false;
        y_dolny = false;

        //porownanie jednego punktu z reszta
        for (int j = 0; j < n; j++) 
        {
            if (x[i] == x[j] && y[i] == y[j]) break; //jeśli trafi na ten sam punkt, to wtedy bierze nastepny
            if (x[i] >= x[j] && x_prawy == false) //sprawdzane są 2 parametry, aby nie było sytuacji takiej, że będą np. dwa punkty wysunięte na prawo od naszego punktu i odbierze dwa życia
            {
                x_prawy = true;
                zycie[i]--;
            }
            if (x[i] <= x[j] && x_lewy == false)
            {
                x_lewy = true;
                zycie[i]--;
            }
            if (y[i] >= y[j] && y_dolny == false)
            {
                y_dolny = true;
                zycie[i]--;
            }
            if (y[i] <= y[j] && y_gorny == false)
            {
                y_gorny = true;
                zycie[i]--;
            }
        }
    }
    wyjscie(n, x, y, zycie);
}

void wyjscie(int n, double x[], double y[], int zycie[])
//funkcja zwracająca punkty, które nie są wewnętrznymi punktami
{
    for (int i = 0; i < n; i++)
    {
        if (zycie[i] > 0)
        {
            cout << x[i] <<  " " << y[i] << endl;
        }
    }
}


int main()
{
    //wprowadzanie danych wejściowych
    int n; //liczba punktów
    cin >> n;
    double* x = new double[n]; //współrzędne x
    double* y = new double[n]; //współrzędne y
    int* zycie = new int[n]; //do każdego punktu przypisuję parametr, którym jest życie i każdy punkt ma 4 życia
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
       zycie[i] = 4;
    }
    // ------------------
 
    system("cls");

    eliminacja_punktow_wewnetrzych(n, x, y, zycie);

    delete[]x;
    delete[]y;
    delete[]zycie;

}

