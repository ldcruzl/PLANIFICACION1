#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

struct Proceso {
    string id;
    int llegada;
    int servicio;
    int inicio;
    int finalizacion;
    int espera;
    int retorno;
    double retorno_normalizado;
};

int main() {
    int n;

    cout << "Cantidad de procesos (3 a 5): ";
    cin >> n;

    if (n < 3 || n > 5) {
        cout << "Error: ingrese entre 3 y 5 procesos." << endl;
        return 1;
    }

    vector<Proceso> procesos(n);

    for (int i = 0; i < n; i++) {
        cout << "\nProceso " << i + 1 << endl;
        cout << "Identificador: ";
        cin >> procesos[i].id;
        cout << "Tiempo de llegada: ";
        cin >> procesos[i].llegada;
        cout << "Tiempo de servicio: ";
        cin >> procesos[i].servicio;
        if (procesos[i].llegada < 0 || procesos[i].servicio <= 0) {
            cout << "Error: los tiempos ingresados no son validos." << endl;
            return 1;
        }
    }

    // Ordenar los procesos por tiempo de llegada
    stable_sort(procesos.begin(), procesos.end(), [](const Proceso &a, const Proceso &b) {
            return a.llegada < b.llegada;
        });

    int tiempo_actual = 0;
    double suma_espera = 0;
    double suma_retorno = 0;

    for (int i = 0; i < n; i++) {
        procesos[i].inicio = max(tiempo_actual, procesos[i].llegada);

        procesos[i].finalizacion = procesos[i].inicio + procesos[i].servicio;

        procesos[i].espera = procesos[i].inicio - procesos[i].llegada;

        procesos[i].retorno = procesos[i].finalizacion - procesos[i].llegada;

        procesos[i].retorno_normalizado = static_cast<double>(procesos[i].retorno) / procesos[i].servicio;

        tiempo_actual = procesos[i].finalizacion;

        suma_espera += procesos[i].espera;
        suma_retorno += procesos[i].retorno;
    }

    cout << "\nRESULTADOS DEL ALGORITMO FCFS\n\n";

    cout << left
         << setw(12) << "Proceso"
         << setw(12) << "Llegada"
         << setw(12) << "Servicio"
         << setw(12) << "Inicio"
         << setw(12) << "Final"
         << setw(12) << "Espera"
         << setw(12) << "Retorno"
         << "Retorno Norm." << endl;

    for (const auto &p : procesos) {
        cout << left
             << setw(12) << p.id
             << setw(12) << p.llegada
             << setw(12) << p.servicio
             << setw(12) << p.inicio
             << setw(12) << p.finalizacion
             << setw(12) << p.espera
             << setw(12) << p.retorno
             << fixed << setprecision(2)
             << p.retorno_normalizado << endl;
    }

    cout << "\nTiempo medio de espera: " << fixed << setprecision(2) << suma_espera / n << endl;

    cout << "Tiempo medio de retorno: " << suma_retorno / n << endl;

    return 0;
}