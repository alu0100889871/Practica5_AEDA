#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

//Insercción (comparar con la izquierda hasta el final)

template<class T>
int insercion(vector<T>& secuencia, bool estadistica){
	int comparaciones = 0;
	for(int i = 1; i < secuencia.size(); i++){
		int j = i; //flecha de comparación
		T actual = secuencia[i]; //numero actual
		comparaciones++;
		while (actual < secuencia[j-1] && j > 0){ //mientras el número de la izq sea mayor que el numero actual y comparar mayor que 0 ya que a la izquierda de 0 no hay nada
			int contador = 0;
			if(contador != 0) comparaciones++;
			if(!estadistica){
				getchar();
				for(int i = 0; i<secuencia.size(); i++)
					cout<<secuencia[i]<<" ";
				cout<<endl;
				cout<< actual <<" < "<<secuencia[j-1]<<endl;
			}
			secuencia[j] = secuencia[j-1]; //intercambio 
			j--; //para comprobar numero izq mayor al actual
			contador++;
		}
		secuencia[j] = actual; //para refrescar en qué número va cada iteración
	}
	return comparaciones;
}

//Burbuja (intercambiar numeroActual > númeroSiguiente y comprobar en toda la lista)

template<class T>
int burbuja(vector<T>& secuencia, bool estadistica){
	int comparaciones= 0;
	bool intercambio = true;
	while(intercambio){ //para recorrer toda la lista
		intercambio = false; //cuando termina siendo false sale del while
		for(int i = 0; i<secuencia.size()-1; i++){
			comparaciones++;
			if(secuencia[i] > secuencia[i+1]){
				T actual = secuencia[i];
				secuencia[i] = secuencia[i+1];
				secuencia[i+1] = actual;
				intercambio = true;
			}
			if(!estadistica){
				getchar();
				for(int t = 0; t<secuencia.size(); t++)
					cout<<secuencia[t]<<" ";
				cout<<endl;
				cout<<secuencia[i]<<" < "<<secuencia[i+1]<<endl;
			}
		}
	}
	return comparaciones;
}

//DeltaSort

template<class T>
void deltasort(float d, vector<T>& secuencia, int& comparaciones, bool estadistica){
	for (int i = d; i < secuencia.size(); i++){
		T actual = secuencia[i];
		int j = i;
		comparaciones++;
		while ((j >= d) && (actual < secuencia[j-d])){ //mientras no se llegue al incremento se va reduciendo entre eso y comparando
			int contador = 0;
			if(contador!=0) comparaciones++;
			if(!estadistica){
				getchar();
				for(int i = 0; i<secuencia.size(); i++)
					cout<<secuencia[i]<<" ";
				cout<<endl;
				cout<<actual<<" < "<<secuencia[j-d]<<endl;
			}
			secuencia[j] = secuencia[j-d]; //intercambio
			j = j - d; //reducimos
			contador++;
		}
		secuencia[j] = actual;
	}
}

//ShellSort

template<class T>
int ShellSort(vector<T>& secuencia, float alpha, bool estadistica){
	int delta = alpha*secuencia.size(); //distancia de los elementos que se van a comparar
	int comparaciones = 0;
	while(delta>=1){
		deltasort<T>(delta,secuencia, comparaciones, estadistica);
		delta = delta / 2; 
	}
	if(!estadistica){
		getchar();
		for(int i = 0; i<secuencia.size(); i++)
			cout<<secuencia[i]<<" ";
		cout<<endl;
	}
	return comparaciones;
}

//QuickSort pivote en medio y cambiandose con los lados

template<class T>
void QuickSort(vector<T>& secuencia, int ini, int fin, int& comparaciones, bool estadistica){

	 int i = ini;
	 int f = fin;
	 int p = secuencia[(i+f)/2] ;

	while (i < f){

		while (secuencia[i] < p ) {i++; comparaciones++;}
	
		while (secuencia[f] > p ) {f--; comparaciones++;}
		
		if(!estadistica){
			getchar();
			for(int t = 0; t<secuencia.size(); t++)
				cout<<secuencia[t]<<" ";
				cout<<endl;
				cout<<secuencia[i]<<"  "<<secuencia[f]<<endl;
				cout<<"Pivote: "<<p<<endl;
				cout<<"inicio: "<<ini<<" fin: "<<fin<<endl;
		}
	
		if (i <= f){
			T actual = secuencia[i] ;
			secuencia[i] = secuencia[f] ;
			secuencia[f] = actual ;
			i++; 
			f--;
	
		}
	}
	if (ini < f) QuickSort<T>(secuencia, ini, f,comparaciones, estadistica);


	if (i < fin) QuickSort<T>(secuencia, i, fin,comparaciones, estadistica);
}

//Seleccion

template<class T>
int Seleccion(vector<T>& secuencia, bool estadistica){
	int comparaciones= 0;
	for (int i = 0; i < secuencia.size()-1; i++){
		int min = i; //ponemos la primera posición como la min
		for (int j = i+1; j < secuencia.size(); j++){
			comparaciones++;
			if (secuencia[j] < secuencia[min]) //ir buscando el minimo e intercarmbiamos
				min = j; //nuevo minimo
			if(!estadistica){
				getchar();
				for(int t = 0; t<secuencia.size(); t++)
					cout<<secuencia[t]<<" ";
					cout<<endl;
					cout<<"El mínimo es: "<<secuencia[min]<<endl;
					cout<<"Posición: "<<i<<endl;
			}
		}
		int actual = secuencia[min];
		secuencia[min] = secuencia[i];
		secuencia[i] = actual; //intercambio
	}
	return comparaciones;
}

//Max_heap

template<class T>
void max_heap(int i, vector<T>& secuencia, int n, int& comparaciones, bool estadistica){
	
	int actual = secuencia[i];
	bool terminar = false;
	while ( (2*(i+1)-1 < n) && (!terminar)){
		int h = 0; //auxiliar
		int h1 = 2*(i+1)-1; //hijo izquierdo
		int h2 = h1 + 1; //hijo derecho
		if (h1 == n-1)
			h = h1;
		else if (secuencia[h1] > secuencia[h2]){
			h = h1;
			comparaciones++;
		}else{
			h = h2;
			comparaciones++;
		} 
		if(!estadistica)
			cout<<"Secuencia["<<h<<"]: "<<secuencia[h]<<" actual: "<<actual<<endl;
		if (secuencia[h] > actual){ 
			comparaciones++;
			secuencia[i] = secuencia[h];
			secuencia[h] = actual;
			i = h;
		}else{
			terminar = true;
		}
	}
}

//HeapSort

template<class T>
int HeapSort(vector<T>& secuencia,bool estadistica){
	int comparaciones= 0;
	for (int i = (secuencia.size()-1)/2; i >= 0; i--){ //la mitad para coger el último padre por la izquierda
		if(!estadistica){
			getchar();
			for(int i = 0; i<secuencia.size(); i++)
				cout<<secuencia[i]<<" ";
			cout<<endl;
		}
		max_heap(i, secuencia, secuencia.size(), comparaciones,estadistica); //creamos el árbol con el máximo en la cima
	}
	if(!estadistica){
		cout<<endl;
		for(int i = 0; i<secuencia.size(); i++)
  			cout<<secuencia[i]<<" ";
  		cout<<endl;
	}
	for (int i = secuencia.size()-1; i > 0; i--) //ordenamos el vector
	{
		int actual = secuencia[0];
		secuencia[0] = secuencia[i];
		secuencia[i] = actual; //cambiamos el ultimo nodo por el primero
		if(!estadistica){
			getchar();
			for(int i = 0; i<secuencia.size(); i++)
				cout<<secuencia[i]<<" ";
			cout<<endl;
		}
		max_heap(0,secuencia,i,comparaciones,estadistica);
	}

	return comparaciones;
}

