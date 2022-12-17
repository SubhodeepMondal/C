#include "device.h"
void lineBres (int xa, int ya, int xb, int yb)
{
	int dx = abs( xa - xb), dy = ( ya - yb);
	int p = 2*dy -dx;
	int twoDy = 2 * dy, twoDyDx = 2* ( dy- dx);
	int x, y, xEnd;
	if(xa > xb)
	{
		x = xb;
		y = yb;
		xEnd = xa;
	}
	else{


