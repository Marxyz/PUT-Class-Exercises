#include "cRobot.h"

cRobot::cRobot():active(-1), platform(), mapWsk(1), automove(false)
{
	/*map.resize(25);
	for(auto itr = map.begin(); itr!=map.end(); ++itr)
	{
		map.resize(3);
	}
	map[0][0] = platform.GetX();
	map[0][1] = platform.GetY();
	map[0][2] = platform.GetAlpha();*/
	beginTime = GetTickCount();
}

cRobot::cRobot(float a, float b):active(-1), platform(a,b), mapWsk(1), automove(false)
{
	beginTime = GetTickCount();

	map.resize(1);
	for (auto itr = map.begin(); itr != map.end(); ++itr)
	{
		itr->resize(3);
	}
	map[0][0] = platform.GetX();
	map[0][1] = platform.GetY();
	map[0][2] = platform.GetAlpha();
}

void cRobot::SetAutomove()
{
	bool tmp = this->automove;
	automove = !tmp;
}

float cRobot::GetPlatformX()
{
	return platform.GetX();
}

float cRobot::GetPlatformY()
{
	return platform.GetY();
}

float cRobot::GetPlatformAlpha()
{
	return platform.GetAlpha();
}

void cRobot::Draw()
{
	platform.Draw();
	for (cSegment element : segments)
	{
		element.Draw();
	}
}

void cRobot::Move(float a, float b)
{
	platform.Move(a, b);
}

void cRobot::MoveTo(float a, float b)
{
	platform.MoveTo(a, b);
}

void cRobot::Rotate(float alpha)
{
	platform.Rotate(alpha);
}

void cRobot::RotateTo(float alpha)
{
	platform.RotateTo(alpha);
}

void cRobot::SetColor(float a, float b, float c)
{
	platform.SetColor(a, b, c);
}

void cRobot::RotateSegment(float alpha)
{
	segments[active].Rotate(alpha);
}

void cRobot::AddSegment()
{
	cSegment *seg = new cSegment(.1, .3);
	seg->SetColor(0.663, 0.663, 0.663);
	segments.push_back(*seg);
	active = segments.size() - 1;
}

void cRobot::DeleteSegment()
{
	if (segments.size() > 0) {
		auto wsk = 0;
		for (auto itr = segments.begin(); itr != segments.end(); ++itr) {
			if (wsk == active) {
				segments.erase(itr);
				break;
			}
			wsk++;
		}
		active = segments.size() - 1;
	}
}

void cRobot::NextSegment()
{
	if (active<segments.size() - 1) {
		active++;
	}
}

void cRobot::PrevSegment()
{
	if (active>0) {
		active--;
	}
}

void cRobot::SavePosition()
{
	/*map[mapWsk][0] = platform.GetX();
	map[mapWsk][1] = platform.GetY();
	map[mapWsk][2] = platform.GetAlpha();
	mapWsk++;*/
	std::vector<float> tmp;
	tmp.push_back(platform.GetX());
	tmp.push_back(platform.GetY());
	tmp.push_back(platform.GetAlpha());
	map.push_back(tmp);
	for (auto itr = map.begin();itr != map.end(); ++itr)
	{
		for (auto itrx = itr->begin(); itrx != itr->end(); ++itrx)
		{
			std::cout << *itrx << " ";
		}
		std::cout << std::endl << std::endl << std::endl;
	}
}

void cRobot::Update(int time)
{
	if(automove == true)
	{
		if (mapWsk < map.size()) {
			bool wskX = false;
			bool wskY = false;
			bool wskAlpha = false;
			int deltaTime = time - beginTime;
			float deltaAlpha = (map[mapWsk][2] - map[mapWsk - 1][2])* deltaTime / 1000;
			float deltaX = (map[mapWsk][0] - map[mapWsk - 1][0]) * deltaTime / 1000;
			float deltaY = (map[mapWsk][1] - map[mapWsk - 1][1]) * deltaTime / 1000;
			beginTime += deltaTime;
			if(deltaX >0.1 )
			{
				deltaX = 0.0;
			}

			
			if(deltaY>0.1)
			{
				deltaY = 0.0;
			}
			std::cout << time << " " << beginTime << " " << deltaX << " " << deltaY << " " << deltaAlpha << " " << deltaTime << std::endl;
			
			if((int)(map[mapWsk][0]*100)==(int)(platform.GetX()))
			{
				wskX = true;
			}
			if((int)(map[mapWsk][1] * 100) == (int)(platform.GetY()))
			{
				wskY = true;
			}
			if((int)(map[mapWsk][1] * 100) == (int)(platform.GetY()))
			{
				wskAlpha = true;
			}
			
			if(wskX == true && wskY ==true && wskAlpha == true)
			{
				mapWsk++;
			}

			if (wskX == false && wskY == false) platform.Move(deltaX, deltaY);
			if (wskX == false && wskY == true) platform.Move(deltaX, 0.0);
			if (wskX == true && wskY == false) platform.Move(0.0, deltaY);
			if(wskAlpha == false) platform.Rotate(deltaAlpha);

			
		}
			
	}
	//std::cout << beginTime << " "<<time<<std::endl;
}


