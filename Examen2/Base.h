#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>

using namespace std;

class Base{
	private:
		char tipo;
		int familiar;
		
	public:
		Base();
		~Base();
		Base(char, int);
		//setters
		void SetTipo(char);
		void SetFamiliar(int);
		//getters
		char GetTipo();
		int GetFamiliar();
};

#endif // BASE_HPP


