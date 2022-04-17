#include "Multime.h"
#include "IteratorMultime.h"
#include <iostream>
#include <set>


using namespace std;

//o posibila relatie
bool rel(TElem e1, TElem e2) {
	//teta(1)
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}

Multime::Multime() {
	
	this -> cp = 2;
	this -> e = new TElem[cp];
	this -> n = 0;
}

void Multime::redim() {
	//teta(1)

	//alocam un spatiu de capacitate dubla
	TElem* eNou = new TElem[2 * cp];

	//copiem vechile valori in noua zona
	for (int i = 0; i < n; i++)
		eNou[i] = e[i];

	//dublam capacitatea
	cp = 2 * cp;

	//eliberam vechea zona
	delete[] e;

	//vectorul indica spre noua zona
	e = eNou;
}




bool Multime::adauga(TElem elem) {
	//O(n) 

	int var,i;
	var = false;//pres ca nu se gaseste deja in multime
	for (i = 0; i < n; i++)
		if (e[i] == elem)
			var = true;
	if (var == false)
	{
		if (n == cp)
			redim();
		i = 0;
		while (elem > e[i] && i < n) i++;
		for (int j = n; j > i; j--)
			e[j] = e[j - 1];
		this->e[i] = elem;
		n++;
		return true;
	}
	return false;

}


bool Multime::sterge(TElem elem) {
	//O(n)

	for (int i = 0; i < n; i++)
	{
		if (e[i] == elem)
		{
			for (int j = i; j < n - 1; j++)
				e[j] = e[j + 1];
			e[n - 1] = 0;
			n--;
			return true;
		}
	}
	return false;
	
}

bool Multime::cauta(TElem elem) const {
	//O(n)
	for (int i = 0; i < n; i++)
		if (e[i] == elem)
			return true;
	return false;
}


int Multime::dim() const {
	//teta(1)
	return n;
}



bool Multime::vida() const {
	//teta(1)
	if(n==0)
		return true;
	return false;
}

IteratorMultime Multime::iterator() const {
	//teta(1)
	return IteratorMultime(*this);
}


Multime::~Multime() {
	//teta(1)
	delete[] e;
}






