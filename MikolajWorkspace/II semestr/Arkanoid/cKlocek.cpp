#include "cKlocek.h"
//#include "cFizyka.h
#include <cstdlib>
#include <ctime>

cKlocek::cKlocek(float x,float y):cProstokat(){
	//srand(time(nullptr));
	this->y = y;
	this->x = x;
	this->setGeometria(this->x, this->y, -this->width / 2, -this->height / 2, this->width / 2, this->height / 2);
	this->punkty = rand()%5+1;
	this->odpornosc = this->punkty;
	this->R = (double)((rand() % 1000) / 1000.0);
	this->G = (double)((rand() % 1000) / 1000.0);
	this->B = (double)((rand() % 1000) / 1000.0);

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