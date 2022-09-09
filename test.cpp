#include "Flight.h"
#include "List.h"
#include <stdlib.h>

// debe llenar una lista de pCantidad vuelos aleatorios cuya hora y minutos de partida esten entre pStartHour y pEndHour
// tomando en cuenta las restricciones de los minutos de salida segun el ejercicio 3 del caso #3
void fillFlights(int pCantidad, int pStartHour, int pEndHour) {
    Flight* flight = new Flight(rand() % 24 + 0, rand() % 59 + 0);
    List<Flight>* flightsList = new List<Flight>();
    while(flightsList->getSize() <= pCantidad){
        Flight* flight = new Flight(rand() % 24 + 0, rand() % 59 + 0);
        if(flight->getExitHour() >= pStartHour && flight->getExitHour() <= pEndHour){
            flightsList->add(flight);
        }
    }
} 


int main() {
    Flight vuelo(4,35);
    cout << vuelo.flightTimeString() << "y el entero es: " << vuelo.getIntTimeValue() << endl;

    Flight otroVuelo(14,20);
    cout << otroVuelo.flightTimeString() << "y el entero es: " << otroVuelo.getIntTimeValue() << endl;
}