#ifndef _player
#define _player
class player
{
    int score;
    char na[10];
 public:void disp();
	void scoreupdate(int);

};
void player::scoreupdate(int score)
{
	player a[5],k,b,t;
	k.score = score;
	int m=0,j;
	int flag=1;
	fstream f("tbr.bak",ios::binary ,ios::out);
	if(!f){
	cout<<"ERROR."; return;};
	while(f.read((char*)&b,sizeof(b)))
	{
		a[m]=b; m++;
	}
	f.close();
	for(int i=0; i<m&&flag;i++)
	{

		if(k.score>a[i].score)
		{    int j=i+1;
			cout<<"Highscore!";
			cout<<"Enter your name : ";
			cin>>k.na;
					  while(j<=5)
					    {
							t = a[j];
							a[j]=a[j-1];
							a[j+1] = t;
							j++;
							flag=0;

					    }
						a[i]=k;
		}

	}
	for(int l = 0;l<m; l++)
	{
		f.write((char*)&(a[l]) , sizeof(a[l]));
	}
}
void player::disp()
{
	player ob;
	ifstream f("tbr.bak",ios::binary);
	cout<<"HIGHSCORES\n\n";
	cout<<"\t\tNAME\t\tSCORE\n";
	f.read((char*)&ob,sizeof(ob));
	while(!f.eof())
	{
		cout<<"\t\t"<<ob.na<<"\t\t"<<ob.score<<"\n";
		f.read((char*)&ob,sizeof(ob));
	}
	f.close();
}

#endif
