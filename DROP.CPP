#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<bios.h>
#include<dos.h>
#include<process.h>
#include<fstream.h>
#include "PLATFORM.CPP"
#include "BALL.CPP"
#include "MBALL.CPP"
int pl_col, bk_col, score, lvl_count, lvl_speed, quit, lives, lvl, reset;
platform p[10];
ball b;
mball m;
class player
{
    int score;
    char na[10];
 public:
	void disp();
	player()
	{
		score = 0;
		na[0] = '\0';
	}
	void scoreupdate(int);

}ob,pl;
void player::scoreupdate(int score)
{
	player a[6],k,b,t;
	k.score = score;
	int m=0,j;
	int flag=1;
	fstream f("c:\\tc\\bin\\drop\\tbr.dat",ios::binary|ios::in);
	if(!f)
	{
		cout<<"ERROR."; return;
	}
	while(f.read((char*)&b,sizeof(b)))
	{
		a[m]=b; m++;
	}
	f.close();
	for(int i=0; i<m&&flag;i++)
	{
		if(k.score>a[i].score)
		{    int j=4;
			cout<<"Highscore!";
			cout<<"Enter your name : ";
			cin>>k.na;
			while(j>=i)
			{
				a[j+1] = a[j];
				j--;
			}
			a[i]=k; flag=0;
		}
	}
	fstream g("c:\\tc\\bin\\drop\\tbr.dat",ios::binary|ios::out);
	for(int l = 0;l<5; l++)
	{
		g.write((char*)&(a[l]) , sizeof(a[l]));
	}
	g.close();
}
void player::disp()
{
	int i = 0;
	ifstream f("c:\\tc\\bin\\drop\\tbr.dat",ios::binary|ios::in);
	cout<<"HIGHSCORES\n\n";
	cout<<"\t\tNAME\t\tSCORE\n";
	f.read((char*)&ob,sizeof(ob));
	while(i<5)
	{
		cout<<"\t\t"<<ob.na<<"\t\t"<<ob.score<<"\n";
		f.read((char*)&ob,sizeof(ob));i++;
	}
	f.close();
}
void disp_menu()
{
	cleardevice();
	setcolor(4);
	setfillstyle(1,4);
	settextstyle(6,HORIZ_DIR,8);
	outtextxy(100,60,"DROP");
	settextstyle(6,HORIZ_DIR,5);
	outtextxy(390,210,"Start");
	delay(800);
	outtextxy(390,270,"Highscores");
	delay(800);
	outtextxy(390,330,"Exit");
	settextstyle(6,HORIZ_DIR,3);
	outtextxy(2,440,"Press Enter to Select");
}
void main()
{
    int gd=9,gm=2, complete, x=0, y=0, x1=60,y1=0, k;
	char a[10];
	randomize();
	initgraph(&gd,&gm,"c:\\turboc3\\bgi\\");
	cleardevice();
	setbkcolor(15);
	setcolor(4);
	setfillstyle(1,4);
	settextstyle(6,HORIZ_DIR,8);
	outtextxy(100,60,"DROP");
	delay(3000);
	for(;gm<6;gm++)
	{
		sound(100+random(2000));
		delay(900);
		nosound();
	}
    do
    {

	do
	{
	    lives=0;
	    disp_menu();
	    do
	    {
	    m.get_input();
	    delay(3);
	    if(x>640)
	    {
		delay(10);
		if(y==0) k=1;
	    else if(y==60) k=-1;
		 while((y==0 && x1!=0) || (y==60 && x1!=60))
	{
	    delay(10);
	    setcolor(15);
	    line(300+x1,0,300+x1,480);
	    x1+=-k;
	    setcolor(4);
	    line(300+x1,0,300+x1,480);
	    line(0,160+y,640,160+y);
	}
		setcolor(15);
		line(0,160+y,640,160+y);
		y+=k;
		setcolor(4);
		line(0,160+y,640,160+y);
		line(300+x1,0,300+x1,480);
	    }
	    else
		{
		    putpixel(x,160+y,4);
		    x++;
		    putpixel(300+x1,y1,4);
		    y1++;
		}
	    }while(key!=ENTER);
	    switch(m.gety())
	    {
		case 302:cleardevice();
			//ifstream f("c:\\tc\\bin\\drop\\des.txt");
			//f.getline(a,100);
			//cout<<a;
			pl.disp();
			getch();
			key=0;
			break;
		case 362:key=300;
	    }
	    x=y=y1=0;x1=60;
	}while(m.gety()!=242 && key!=300);
	lvl=1;
	p[0].reset(p,480);
	lives=3;
	score=0;
	quit=0;
	complete=0;
	cleardevice();
	while(key!=283 && lives-1 && key!=300)
	{
	    if(quit) lives--;
	    if(complete){lvl++;complete=0;}
	    p[0].reset(p);
	    lvl_speed=10/lvl;
	    if(lvl==2 || lvl==4) {pl_col=8;bk_col=15;}
		else {pl_col=lvl;bk_col=(pl_col+lvl)%15;}
	    setfillstyle(1,pl_col);
	    bar(0,0,639,479);
	    setfillstyle(1,bk_col);
	    setcolor(bk_col);
	    bar(196,0,444,480);
	    setfillstyle(1,pl_col);
	    quit=0;
	    reset=1;
	    delay(500);
	    key=0;
	    while(!quit && key!=283 && !complete)
	    {
		x1=lives;
		b.get_input();
		p[0].gen_map(p,b);
		if(quit)
		{sound(1000);delay(200);nosound();sound(500);delay(300);nosound();}
		setfillstyle(1,pl_col);
		bar(170,4,195,48);
		setcolor(15);
		settextstyle(2,1,5);
		itoa(lvl,a,10);
		if(x1!=lives) bar(440,0,460,480);
		outtextxy(442,435,"Level");
		outtextxy(442,420,a);
		itoa(lives,a,10);
		outtextxy(442,20,"Lives");
		outtextxy(442,5,a);
		itoa(score,a,10);
		outtextxy(180,70,"Score");
		outtextxy(180,5,a);
		delay(20-lvl*3);
		if(score>1000*lvl) complete++;
	    }
	}
	nosound();
    if(key!=300)
    {
	cleardevice();
	setcolor(4);
	settextstyle(3,HORIZ_DIR,10);
	outtextxy(130,20,"SCORE");
	itoa(score,a,10);
	pl.scoreupdate(score);
	settextstyle(2,HORIZ_DIR,10);
	outtextxy(300,200,a);
	settextstyle(7,HORIZ_DIR,2);
	outtextxy(300,400,"Press any key to continue...");
	getch();//getch();getch();
    }
    }while(key!=300);
    cleardevice();
	settextstyle(5,HORIZ_DIR,3);
	outtextxy(120,170,"Thank you for playing- SaNiMuSh");
	delay(2000);
    closegraph();
}
