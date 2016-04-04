#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include "PLATFORM.H"
#include "MBALL.H"
extern int lvl, quit, lives;
mball life(-10,-10);
int platform::check_mb(platform *p)
{
    for(int i=0;i<10;i++)
    {
       if(p[i].y>0)
        if(mb) return 0;
    }
    return 1;
}
int platform::mindist(platform *p, int a)
{
    for(int i=0;i<10;i++)
    {
        if(p[i].y>a) return 1;
    }
    return 0;
}
void platform::draw_platform(platform *p, ball &b)
{
    {
	if(!random(1000)) mb++;
	    setcolor(pl_col);
	    setfillstyle(1,pl_col);
	    if(!type)
	    {
            bar(x,y+3,x+l,y+10);
            for(int i=x;i<x+l-3;i+=6)
            {
                bar(i,y-2,i+2,y+3);
            }
		}
		else
        {
            if(!random(1000) && y>=470 && check_mb(p)) mb++;
            if(mb)
            {
                life.erase_ball();
                life.move_ball(x+l/2, y-5);
                life.draw_ball();
                if(abs(life.getx()-b.getx())<17 && abs(life.gety()-b.gety())<17) {mb=0;life.move_ball(-10,-10);lives++;sound(2000);delay(40);nosound();}
            }
            setfillstyle(1,pl_col);
            bar(x,y,x+l,y+10);
        }
    }
}
void platform::reset(platform *p,int a=100)
{
    for(int i=0;i<10;i++)
    {
        if(p[i].y<a) p[i].y=-20;
    }
}
void platform::gen_map(platform *p, ball &b)
{
    for(int i=0;i<10;i++)
    {
        if(p[i].y!=-20)
            {
                p[i].erase_platform();
                p[i].y-=PL_SPEED;
		p[i].draw_platform(p,b);
                if(!p[i].type && b.getx()>=p[i].x-9 && b.getx()<p[i].x+p[i].l+9 && b.gety()>p[i].y-20 && b.gety()<p[i].y) quit++;
            }
        if(p[i].y==-20)
        {
           p[i].mb=0;
           if(!mindist(p, 400))
             p[i].set_platform(random(5));
        }

    }

}

