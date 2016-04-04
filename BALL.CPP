#include "BALL.H"
#include<bios.h>
#include<stdlib.h>
#include<iostream.h>
#include<math.h>
extern int reset, pl_col, lvl_count,lvl_speed, score, lives, quit;
long key;
void ball::get_input()
{
     if(reset) {x=320;y=20;xspeed=yspeed=0;reset=0;}
	 int i, flag, temp, temp2;
	 temp=key;
	 if(bioskey(1)!=0) key=bioskey(0);
	 if(key!=UP && key!=DOWN && key!=RIGHT && key!=LEFT && key!=283) key=temp;
     switch(key)
     {
		case UP: score+=1000;break;
case  LEFT :flag=1;
					for(i=0;i<=r;i++)
                        if(getpixel(x-r-1,y+i)==pl_col || getpixel(x-r-1,y-i)==pl_col)
                           flag=0;
					if(flag) xspeed=-MAX_XSPEED;
                        else xspeed=0;
					break;
		case  RIGHT:flag=1;
					for(i=0;i<=r;i++)
                        if(getpixel(x+r+1,y+i)==pl_col || getpixel(x+r+1,y-i)==pl_col)
                            flag=0;
					if(flag) xspeed=MAX_XSPEED;
					    else xspeed=0;
					break;
		case  DOWN :xspeed=0;
	}
    flag=1;temp=y;temp2=x;
	for(i=0;i<=r;i++)
        if(getpixel(x+i,y+r+1)==pl_col || getpixel(x-i,y+r+1)==pl_col)
            flag=0;
             else if(getpixel(x+i,y+r+6)==pl_col || getpixel(x-i,y+r+6)==pl_col)
                flag=0;
    if(flag) yspeed=MAX_YSPEED;
        else yspeed=0;
    x+=xspeed;
    y+=yspeed-PL_SPEED;
    if(temp!=y || temp2!=x) {if(temp<y)score+=abs(y-temp)/5;erase_ball(temp2, temp);draw_ball();}
    if(y>SCREEN_H || y<0) quit++;
}
