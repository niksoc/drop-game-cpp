#ifndef _platform
#define _platform
#define PL_SPEED 5
#include<graphics.h>
#include "BALL.H"
extern int pl_col, bk_col, lvl;
class platform
{
        int x,y;
        int l;
        int type;
        int mb;
 public:platform()
        {
            y=-20;
            mb=0;
        }
        void reset(platform *p, int);
        void set_platform(int t)
        {
            x=(200/MAX_XSPEED+random(180/MAX_XSPEED))*MAX_XSPEED-4;
            y=480;
            l=(60/MAX_XSPEED+random(350/MAX_XSPEED-x/MAX_XSPEED))*MAX_XSPEED+4;
            type=t;
        }
	void draw_platform(platform *,ball &);
        void erase_platform()
        {
            setcolor(bk_col);
            setfillstyle(1,bk_col);
            bar(x,y,x+l,y+10);
        }
        void gen_map(platform *, ball &);
        int mindist(platform *, int);
        int check_mb(platform *);
};
#endif
