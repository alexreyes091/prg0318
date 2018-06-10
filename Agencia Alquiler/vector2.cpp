#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int main()
{
vector<char> valores(10); // iniciar con diez elementos
// llenar con letras mayúsculas al azar
for(unsigned i=0; i<valores.size(); ++i)
valores[i] = 'A' + (rand() % 26);
vector<char> aux(valores); // aux es copia de valores
// ordenar aux utilizando el método de burbujeo
for(unsigned i=0; i<aux.size(); ++i)
{
		for(unsigned j=1; j<aux.size(); ++j)
		{
			if(aux[j] < aux[j-1])
			{
				char c = aux[j];
				aux[j] = aux[j-1];
				aux[j-1] = c;
			}	
		}
	
}

// mostrar por pantalla
for(unsigned i=0; i<aux.size(); ++i)
cout << aux[i] << endl;

cout<<endl;
for(unsigned i=0; i< valores.size(); ++i)
cout << valores[i] << endl;
return 0;
}
