//Fun easy physics
/* Made this project to test out things I learned.
It is a fun project to start.
The project can use some updates so feel free to update it. */

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

double V;  // Velosety
double Vi; // Intentional velosety
double a;  // Acseleration
double t;  // Time in seconds
double Xo; // The meters from start x as
double X;  // The meters at end x as
double d;  // Distance traveld

int time()
{
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
}

double dt()
{
    d = X - Xo;
    if (V == 0 && d > 0)
    { 
        V = d / t;
        cout << "Velosety =\t" << V << " m/s" << endl;
    }
    if (d == 0 && V > 0)
    {
        d = V * t;
        cout << "Distance =\t" << d << " m" << endl;
    }
    if (t == 0 && V > 0)
    {
        t = d / t;
        cout << "Time =\t" << d << " s" << endl;
    }
}

double vviat()
{
    double vforvi = V; // to not calculate Vi after V is > 0
    if (V == 0 && a > 0 && t > 0)
    {
        V = Vi + (a * t) ;
        cout << "Velosety =\t" << V << " m/s \t After " << t << " seconds."<< endl;
    }
    if (Vi == 0 && vforvi > 0)
    {
        Vi = V / (a * t) ;
        cout << "Intentional velosety =\t" << Vi << " m/s" << endl;
    }
    if (a == 0 && V > 0)
    {
        a = V / (t + Vi) ;
        cout << "Acseleration =\t" << a << " m/s2" << endl;
    }
    if (t == 0)
    {
        t = V / (a + Vi) ;
        cout << "Seconds =\t" << t << " s" << endl;
    }
}

double xxo() // Distance
{
    if (X == 0)
    {
        X = Xo + (((Vi * t) + (0,5 * a * (t * t))) /10);
        cout << "Distance =\t" << X << " m" << endl;
    }
    if (a == 0 && V == 0)
    {
        a = X / (Xo + (Vi * t) + (0,5 * (pow(t, 2))));
        cout << "Acseleration =\t" << X << " m/s2" << endl;
    }   
}

double vviaxxo()
{
    if (V == 0 && t == 0)
    {
        V = sqrt ((pow (Vi, 2))+ (2 * a * (X - Xo)));
        cout << "Velosety =\t" << V << " m/s" << endl;
    }
    if (a == 0 && t == 0)
    {
        //V = sqrt ((pow (Vi, 2))+ (2 * a * (X - Xo)));
        cout << "Acseleration =\t" << a << " don't m/s2" << endl;
    }
    if (Vi == 0 && t == 0)
    {
        //V = sqrt ((pow (Vi, 2))+ (2 * a * (X - Xo)));
        cout << "Intentional velosety =\t" << Vi << " don't m/s" << endl;
    }
    if (d == 0 && t == 0)
    {
        //V = sqrt ((pow (Vi, 2))+ (2 * a * (X - Xo)));
        cout << "Distance traveld =\t" << d << " don't m" << endl;
    }
}

double varw(std::vector<double>Eval)
{ 
    if (Eval[2] == 0 && Eval[3] == 0)
    {
        Eval[3] = Eval[0] * Eval[1];
        Eval[2] = Eval[0] / Eval[1];
    }
    if (Eval[1] == 0 && Eval[2] == 0)
    {
        Eval[1] = Eval[3] / Eval[0];
        Eval[2] = pow(Eval[1], 2) / Eval[3];
    }
    if (Eval[0] == 0 && Eval[2] == 0)
    {
        Eval[0] = Eval[3] / Eval[1];
    }
    else
    {
        return 0 ;
    }

    cout << endl;

    for (int i = 0; i < Eval.size(); i++)
        {
            cout << "| " << Eval[i] << '\t';
        }
    cout << endl << "| V\t" << "| A\t" << "| R\t" << "| W\t" << endl;
}

int main()
{   
    time();

    for (int i = 0; i < i + 1; i++)
    {    
        int Menu_choise;
        cout << endl << "(0) Quet calculation" << endl << "(1) Calculate speed stuf.." << endl << "(2) Calculate elektro stuf.." << endl << "(3) Add new calculations.." << endl; 
        cin >> Menu_choise; cout << endl;

        if (Menu_choise == 1) // basic
        {
            cout << "Velosety m/s:\t"; cin >> V;
            cout << "Intentional velosety m/s:\t"; cin >> Vi;
            cout << "Acseleration m/s2:\t"; cin >> a;
            cout << "Seconds s:\t"; cin >> t;

            cout << "Starting point m:\t"; cin >> Xo;
            cout << "Ending point m:\t"; cin >> X;

            dt();
            vviat();
            xxo();
            vviaxxo();
        }
        if (Menu_choise == 2) //vector
        {
            double v;
            double A;
            double R;
            double W;
            
            std::vector<double>Eval{};

            cout << "Volt V:\t"; cin >> v; Eval.push_back(v); // v = eval[0]
            cout << "Amps A:\t"; cin >> A; Eval.push_back(A); // A = eval[1]
            cout << "Ohm R:\t"; cin >> R; Eval.push_back(R); // R = eval[2]
            cout << "Watt W:\t"; cin >> W; Eval.push_back(W); // W = eval[3]
            
            varw(Eval);
        }
        if (Menu_choise == 3)
        {
            std::string file_txt;
            std::ofstream file ("calculations.txt", std::ios::app);
            cout << "Fill in the calculation that you like to add." << endl;
            cin >> file_txt;
            file << file_txt << endl;
            cout << "Thx for the feed back!" << endl;
            file.close();
        }
        else 
        {
            return 0;
        }     
    }
}