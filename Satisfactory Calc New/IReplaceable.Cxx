#include "IReplaceable.Hxx"

void IReplaceable::SetPositionX(int _x) {
	positionX = _x;
}

void IReplaceable::SetPositionY(int _y) {
	positionY = _y;
}

void IReplaceable::SetPosition(int _x, int _y) {
	SetPositionX(_x);
	SetPositionY(_y);
}