#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Quiz #6
// 1. Utilizando esta classe agregue los atributos del vuelo: aerolinea, numero de vuelo, cantidad de pasajeros
// 2. Complete el constructor de la clase, de tal forma que se pueda modificar el flightTime para una hora y minutos específicos
// 3. Implementar alguna forma de convertir el time a un número entero de tal forma que entre menor la hora menor el número, eso en getIntTimeValue()
// 4. En el test.cpp, implementar la función fillFlights()
// fecha de entrega: jueves 8 de setiembre antes de las 10pm
// entrega al asistente al correo: kevinqj.2002@gmail.com
// subject: estructuras de datos - quiz #6
// adjuntan el archivo test.cpp y Flight.h

class Flight {

    private: 
        string airline;
        int flightNumber;
        int amountPassengers;
        time_t flightTime;
        int exitHour;
        int exitMinutes;

    public: 
        Flight(int pHour, int pMinutes) {
            exitHour = pHour;
            exitMinutes = pMinutes;
            flightNumber = 0;
            amountPassengers = 0;
            airline = "";
            this->flightTime = time(NULL);
            tm *currentTime = localtime(&this->flightTime);
            int currentHour = currentTime->tm_hour;
            int currentMinutes = currentTime->tm_min;
            this->flightTime -= currentHour * 3600;

            this->flightTime -= currentMinutes * 60;

            this->flightTime += exitHour * 3600;

            this->flightTime += pMinutes * 60;
        }

        char* flightTimeString() {
            char* result = ctime(&this->flightTime);
            return result;
        }

        int getIntTimeValue() {
            int result = ((flightTime/ 60) / 60);
            return result;
        }

        int getExitHour(){
            return this->exitHour;
        }

        int getExitMinutes(){
            return this->exitMinutes;
        }
};
