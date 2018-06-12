#ifndef REGISTROBASE_HPP
#define REGISTROBASE_HPP

#include <iostream>
#include <string>

using namespace std;

class RegistroBase{
	private:
		string usuario;
		string fecha;
		string tipoTransaccion;
		
	public:
		//constructores y destructores
		RegistroBase();
		~RegistroBase();
		RegistroBase(string, string, string);
		//setters
		void SetUsuario(string);
		void SetFecha(string);
		void SetTipoTransaccion(string);
		//getters
		string GetUsuario();
		string GetFecha();
		string GetTipoTransaccion();
		//otros metodos
		virtual void MostrarInfo(); //Solo para fines de prueba
};

#endif // REGISTROBASE_HPP

