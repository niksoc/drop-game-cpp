#ifndef _ball
#define _ball
#define SCREEN_W 640
#define SCREEN_H 480
#define MAX_XSPEED 5
#define MAX_YSPEED 10
#define LEFT 0x4B00
#define UP 0x4800
#define RIGHT 0x4D00
#define DOWN 0x5000
#define ENTER 7181
#define BALL_RADIUS 9
#include<graphics.h>
extern int bk_col;
class ball
{

		int x,y;
		int r;
		int xspeed, yspeed;
 public:void get_input();
 		int getx() {return x;}
		int gety() {return y;}
		void draw_ball()
		{
            setfillstyle(1,4);
            setcolor(4);
            circle(x,y,r);
            floodfill(x,y,4);
		}
		ball()
		{
		     x=320;
			 y=10;
			 r=BALL_RADIUS;
			 yspeed=10;
		}
		void erase_ball(int x, int y)
		{
			setcolor(bk_col);
			setfillstyle(1,bk_col);
			circle(x,y,r);
			floodfill(x,y,bk_col);
		}
};
#endif
