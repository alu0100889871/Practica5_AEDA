#include<cstdio>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include <limits.h>

#include"DNI/DNI.hpp"
#include"MetodosOrdenacion/MetodosOrdenacion.hpp"


using namespace std;


void modo_demostracion(void){
	int N = 0;
	int algoritmo;
	float alpha = 0;
	bool estadistica = false;

	cout<<"Introduce el tamaño del vector a ordenar: ";
	cin>>N;
	
	cout<<"Introduce el algoritmo a utilizar:"<<endl;
	cout<<"1. Inserción"<<endl;
	cout<<"2. Burbuja "<<endl;
	cout<<"3. ShellSort"<<endl;
	cout<<"4. QuickSort"<<endl;
	cout<<"5. Seleccion"<<endl;
	cout<<"6. HeapSort"<<endl;
	cin>>algoritmo;
	vector<DNI> v(N,0);
	
	cout<<"DNI generados de forma random: ";
	for(int i = 0; i<v.size(); i++){
		v[i] = rand() % 40000000 + 30000000; //desde 40000000 hasta 70000000
		cout<<v[i]<<" ";
	}
	cout<<endl;


	int comparaciones = 0;
	cout<<endl;
	switch(algoritmo){
	case 1: insercion<DNI>(v, estadistica);
			for(int i = 0; i<v.size(); i++)
				cout<<v[i]<<" ";
			break;
	case 2: burbuja<DNI>(v,estadistica);
				break;
	case 3: cout<<"Introduce un alpha: "<<endl;
			cin >> alpha;
			ShellSort<DNI>(v,alpha, estadistica);
				break;
	case 4: QuickSort<DNI>(v,0,v.size()-1, comparaciones,estadistica);
			for(int i = 0; i<v.size(); i++)
				cout<<v[i]<<" ";
			break;
	case 5: comparaciones= Seleccion<DNI>(v,estadistica);
			for(int i = 0; i<v.size(); i++)
				cout<<v[i]<<" ";
			break;
	case 6: comparaciones = HeapSort<DNI>(v,estadistica);
			for(int i = 0; i<v.size(); i++)
				cout<<v[i]<<" ";
			break;
	}


}

//Para en el bucle del modo estadistica coger el algoritmo

int algoritmo(int tipo, vector<DNI>& v){
	int comparaciones= 0;
	bool estadistica = true;
	switch(tipo){
	case 1: comparaciones = insercion<DNI>(v,estadistica);
			break;
	case 2: comparaciones = burbuja<DNI>(v,estadistica);
			break;
	case 3:	comparaciones = ShellSort<DNI>(v,0.5,estadistica);
			break;
	case 4: QuickSort<DNI>(v,0,v.size()-1, comparaciones,estadistica);
			break;
	case 5: comparaciones = Seleccion<DNI>(v,estadistica);
			break;
	case 6: comparaciones = HeapSort<DNI>(v,estadistica);
	}
return comparaciones;
}

void modo_estadistica(void){
	int N = 0;
	int pruebas;
	
	cout<<"Introduce el tamaño de la secuencia a ordenar: ";
	cin>>N;

	cout<<"Introduce el número de pruebas: ";
	cin>>pruebas;
	
	cout<<"\t\t\t\t\tNúmero de Comparaciones"<<endl;
	cout<<"\t\t\t\tMínimo\t\tMáximo\t\tMedio"<<endl;
	
	vector<DNI> v(N,0);
	for(int i = 1; i<=6; i++){
		int maximo= 0, minimo= INT_MAX, suma = 0;
		int comparaciones= 0;
		for(int j=0 ; j < pruebas; j++){
			for(int t = 0; t<v.size(); t++)
				v[t] = rand() % 40000000 + 30000000;
			comparaciones = algoritmo(i,v);
			if(comparaciones < minimo) minimo = comparaciones;
			if(comparaciones > maximo) maximo = comparaciones;
			suma += comparaciones;
			comparaciones = 0;
		}
		switch(i){
			case 1: cout<<"Inserción";
					break;
			case 2: cout<<"Burbuja  ";
					break;
			case 3: cout<<"ShellSort";
					break;
			case 4: cout<<"QuickSort";
					break;
			case 5:	cout<<"Selección";
					break;
			case 6:	cout<<"HeapSort ";
		}
		cout<<"\t\t\t"<<minimo<<"\t\t"<<maximo<<"\t\t"<<suma/N<<endl;
	}
}

int main(void){

	int modo;
	cout<<"Elige un modo:"<<endl;
	cout<<"1. Modo demostración"<<endl;
	cout<<"2. Modo estadísticas"<<endl;
	cin>>modo;
	
	switch(modo){
		case 1: modo_demostracion();
				break;
		case 2: modo_estadistica();
	}
}
