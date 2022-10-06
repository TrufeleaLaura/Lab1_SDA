#include "IteratorMultime.h"
#include "Multime.h"
#include <iostream>


IteratorMultime::IteratorMultime(const Multime& m) : mult(m) {
	//teta(1)
	curent = 0;//seteaza iteratorul pe prima pozitie din vector
}

void IteratorMultime::prim() {
	//teta(1)
	curent = 0;//reseteaza iteratorul pe prima pozitie
}

void IteratorMultime::urmator() {
	//teta(1)
		if (curent < mult.dim())
			curent++;
		else 
		{
			throw (curent + 1);
		}
} 

TElem IteratorMultime::element() const {
	//teta(1)
	return mult.e[curent];
}

bool IteratorMultime::valid() const {
	//teta(1)
	return curent < mult.dim(); //verifica daca iteratorul indica spre un element al vectorului
}





