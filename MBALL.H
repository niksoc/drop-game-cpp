#ifndef _mball
#define _mball
#include<graphics.h>
#include "BALL.H"
extern int bk_col, lives;
class mball
{

		int x,y;
		int r;
 public:void get_input();
 		int getx() {return x;}
		int gety() {return y;}
		mball(int x1=370, int y1=242)
		{
		     x=x1;
			 y=y1;
			 r=5;
		}
		void move_ball(int x1, int y1)
		{
            x=x1;
			y=y1;
		}
		void draw_ball()
		{
            setfillstyle(1,4);
            setcolor(4);
            circle(x,y,r);
            floodfill(x,y,4);
		}
		void erase_ball()
		{
            if(!lives) bk_col=15;
            setcolor(bk_col);
			setfillstyle(1,bk_col);
			circle(x,y,r);
			floodfill(x,y,bk_col);
		}

};
#endif
