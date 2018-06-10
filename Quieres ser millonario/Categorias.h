#ifndef CATEGORIAS_HPP
#define CATEGORIAS_HPP

#include <iostream>

using namespace std;

class Categorias{
	private:
		int nCategoria;
		string dCategoria;
		
	public:
		//Constructores y Destructores
		Categorias();
		~Categorias();
		Categorias(int);
		Categorias(int, string);
		
		//Setters y Getters
		void SetNCategoria(int);
		void SetDCategoria(string);
		
		int GetNCategoria();
		string GetDCategoria();
		
		void MostrarCategoria();
};

#endif //CATEGORIAS_HPP
