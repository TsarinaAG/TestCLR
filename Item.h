#pragma once
using namespace System::Drawing;
class Item
{
	double x;
	double y;
	double R;
public:
	Item();
	Item(double x, double y, double R);
	void Move(double x, double y);
	void Draw(Graphics ^gr);
	~Item(){} // inline
};

