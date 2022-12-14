#include < iostream.h>
#include <graphics.h>
#include < math.h>
#include < conio.h>
void move(int .j,int h,int &x, int &y)
{
if(j== 1) y-=h;
else if(j==2) x+=h;
else if(j==3} y+=h;
else if(j==4) x-=h;
lineto(x,y);
}
void hilbert(int r, int d, int t, int u, int i, int h, int &x, int &y)
{ if(i >0)
{ i- -;
hilbert (d,r, u,e ,i,h,x,y);
move(r ,h,x,y);
hilbert(r,d,t,u,i,h,x,y);
move (d,h,x,y);
hilbert(r,d,e,u,i,h,x,y);
move(e,h,x,y);
hilbert (u,t ,d,r ,i,h,x,y);
}
}
void main ( )
{ int n,xl,yl;
int xO=50,yO= 150,x,y,h= 10,r=2,d=3,t=4, u=l;
int driver=DETECT,mode=O;
initgraph( &driver ,&mode, " ");
count < < "Give the value of n:";
cin»n;
x=xO;y=yO;
moveto(x,y);
hilbert(r,d,t,u,n,h,x,y);
getch( );
restorecrtmode;
}
