#include "cKlocek.h"
//#include "cFizyka.h
#include <cstdlib>
#include <ctime>

cKlocek::cKlocek():cProstokat(){
	srand(time(NULL));
	this->y = 0.35;
	this->x = 1.0 / rand();
	this->setGeometria(this->x, this->y, -this->width / 2, -this->height / 2, this->width / 2, this->height / 2);

}
int cKlocek::GetPunkty(){
	return this->punkty;
}
void cKlocek::Odbicie(float alpha){
	this->odpornosc--;
	if (odpornosc == 0){
		this->widoczny = false;
	}
	CFizyka::Odbicie(alpha);
}
cKlocek::~cKlocek(){

}