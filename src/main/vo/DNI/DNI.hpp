#ifndef DNI_HPP_
#define DNI_HPP_

using namespace std;

#include<iostream>

class DNI{
private:
	unsigned int dni_;
public:
	DNI(void);
	DNI(long int dni);
	~DNI();
	long int get_dni(void);
	void set_dni(long int dni);
// friend -> para que puedan acceder miembros que no pertenecen a la clase 
	friend int operator%( DNI& a , int tamanio);
	friend bool operator==(const DNI& a , const int& b);
	friend bool operator!=( DNI& a, int& b);
	friend bool operator<( DNI& a,  int& b);
	operator unsigned int()const {return dni_;};
	int operator%( DNI& a);
	DNI& operator=(DNI Dni);
	bool operator==( DNI& a);
	bool operator!=(DNI& a);
	bool operator<( DNI& a);
	bool operator>( DNI& a);
};

ostream& operator<<(ostream& os, DNI& Dni);

#endif
