#ifdef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>

using namespace std;

class Base{
	private:
		string usuario;
		string fecha;
		string tipoTransaccion;
		
	public:
		//constructores y destructores
		Base();
		~Base();
		Base(string, string, string);
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

#endif // BASE_HPP
