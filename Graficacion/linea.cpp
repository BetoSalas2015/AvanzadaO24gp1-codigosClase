#include <stdio.h>
//#include <graphics.h>

void basicoLinea(int x1, int y1, int x2, int y2)
{
	
}

void BressenhamLinea(int x1, int y1, int x2, int y2) 
{
	
}

int main()
{
	int x1, y1, x2, y2;
	printf("Dame las coordenadas del primer punto:  ");
	scanf("%d,%d", &x1,&y1);
	printf("Dame las coordenadas del segundo punto:  ");
	scanf("%d,%d", &x2,&y2);
	
	basicoLinea(x1, y1, x2, y2);
	return 0;
}