#include "Item.h"


Item::Item()
{
	x = y = 0.0;
	R = 100.0;
}
Item::Item(double x, double y, double R){
	this->x = x; this->y = y; this->R = R;
}
void Item::Move(double x, double y){
	this->x = x; this->y = y;
}
void Item::Draw(Graphics ^gr){
	gr->DrawEllipse(gcnew Pen(Color::DarkGreen),
		(float)(x - R), (float)(y - R), (float)(2 * R),
		(float)(2 * R));
}
