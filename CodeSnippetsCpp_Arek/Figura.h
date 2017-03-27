#pragma once
class Figura
{

protected:
	float x, y;
	double c_r, c_g, c_b;
public:
	bool czyKlinieta(float x, float y);
	void Draw();
	virtual void MoveLeft() = 0;
	virtual void MoveRight() = 0;
	virtual void MoveDown() = 0;
	virtual void MoveUp() = 0;
	Figura();
	~Figura();
};

