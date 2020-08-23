#include <stdio.h>
#include <iostream>

class Arreglo
{
  int tam;
  int * elem;
	
public:
  Arreglo(int);

  void operator=(Arreglo);
  void mostrar();
  void cargar();
  int burbuja();
  int insercion();
};

Arreglo::Arreglo(int tam)
{
  this->tam=tam;
  elem = new int[tam];
}

void Arreglo::cargar()
{
  int temp;
  for(int i=0;i<tam;i++)
    {
      temp=0;
      std::cout<<"Ingrese elemento "<<i+1<<": ";
      std::cin>>temp;
      elem[i]=temp;
    }
}

int Arreglo::burbuja()
{
  int i, j, aux , op=0;
  for (i=0;i<tam-1;i++)
    {
      for (j=i+1;j<tam;j++)
	{
	  op++;
	  if (elem[i]>elem[j])
	    {
	      aux=elem[i];
	      elem[i]=elem[j];
	      elem[j]=aux;
	    }
	}
    }
  return op;
}

void Arreglo::mostrar()
{
  std::cout<<"[ ";
  for(int i=0;i<tam;i++)
    {
      std::cout<<elem[i]<<", ";
    }
  std::cout<<" ]"<<std::endl;
}

void Arreglo::operator = (Arreglo A)
{
  this-> tam=A.tam;
  for (int k=0;k<tam;k++)
  {
    elem[k]=A.elem[k];
  }
}

int Arreglo::insercion()
{
  int op=0,aux,a=0;;
  for (int i=0;i<tam;i++)
    {
      aux=elem[i];
      a=i-1;
      op++;
      while (a>=0 && elem[a]>aux)
      {
	elem[a+1]=elem[a];
	a--;
	op++;
      }
      elem[a+1]=aux;
    }
  return op;
}

int main(int argc, char *argv[])
{
  int n,oper=0;
  std::cout<<"Ingrese el tamaño del arreglo"<<std::endl;
  std::cin>>n;
  Arreglo A(n) , B(n);
  std::cout<<"Ingrese los datos del arreglo"<<std::endl;
  A.cargar();
  B=A;
  std::cout<<"El arreglo sin ordenar seria"<<std::endl;
  B.mostrar();
  std::cout<<"Se ordenan los elementos con burbuja"<<std::endl;
  oper=A.burbuja();
  std::cout<<"El arreglo ordenado seria"<<std::endl;
  A.mostrar();
  std::cout<<"El Numero de operaciones hechas es: "<<oper<<std::endl;
  A=B;
  oper=0;
  std::cout<<"-----------------"<<std::endl;
  std::cout<<"El arreglo sin ordenar seria"<<std::endl;
  B.mostrar();
  std::cout<<"Se ordenan los elementos con inserccion"<<std::endl;
  oper=A.insercion();
  std::cout<<"El arreglo ordenado seria"<<std::endl;
  A.mostrar();
  std::cout<<"El Numero de operaciones hechas es: "<<oper<<std::endl;
  
}
