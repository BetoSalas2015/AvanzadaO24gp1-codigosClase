 #include <graphics.h>

int main(int argc, char const *argv[])
{
    int gd = DETECT, gm, midx, midy, maxx, maxy;
    
    initgraph(&gd, &gm, (char *)"");
    maxx = getmaxx();
    maxy = getmaxy();
    midx = maxx/2;
   	midy = maxy/2;
    line(midx,0,midx,maxy);
    line(0, midy, maxx, midy);
    circle(midx + 150, midy + -150, 100);
    getch();
    closegraph();
    return 0 ;
}
