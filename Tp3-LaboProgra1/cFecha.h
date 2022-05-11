#ifndef _CFECHA_H
#define _CFECHA_H
#include "gbl.h"

class cFecha {
    public:

        #pragma region Constructor_Destructor
        
        /// <summary>
        /// Constructor por defecto
        /// </summary>
        cFecha();
        
        /// <summary>
        /// Destructor por defecto
        /// </summary>        
        ~cFecha();

        /// <summary>
        /// Setea la hora en la que se pretende realizar el transplante
        /// </summary>
        /// <param name="_horaTransplante">: Hora en la que se realizara el transplante</param>
        /// <returns>True en caso de poder setear la hora, false en caso contrario</returns>
        bool setHoraTransplante(time_t _horaTransplante) {
            try {
                if (!horaTransplante) {
                    this->horaTransplante = &_horaTransplante;
                    return true;
                }
                else throw exception("No se pudo setear la hora de transplante");
            }
            catch (exception& e) {
                cout << "Error: " << e.what() << endl;
                return false;
            }
        }

        bool setHoraAblacion(time_t _horaAblacion) {
            try {
                if (!horaAblacion) {
                    this->horaAblacion = &_horaAblacion;
                    return true;
                }
                else throw exception("No se pudo setear la hora de ablacion");
            }
            catch (exception& e) {
                cout << "Error: " << e.what() << endl;
                return false;
            }
        }

        /// <summary>
        /// Obtiene la diferencia de horas transcurridas entre la hora de trasnplante y la de ablacion (en horas)
        /// </summary>
        /// <returns></returns>
        int getDiffHour() {
            int resul = 0;
            try {
                if (horaAblacion && horaTransplante) {
                    resul = difftime(*horaTransplante, *horaAblacion) / 3600;
                    if (resul < 20)
                        return resul;
                    else
                        throw exception("No se puede realizar el transplante: pasaron mas de 20 horas");
                }
                else 
                    throw exception("No se pudo obtener la diferencia de las horas transcurridas");
            }
            catch (exception& e) {
                cout << "Error: " << e.what() << endl;
                return 0;
            }
        }
       
        #pragma endregion

    private: 
    
        #pragma region Atributos
        
        time_t* horaAblacion;
        time_t* horaTransplante;

        #pragma endregion

};

#endif // _CFECHA_H