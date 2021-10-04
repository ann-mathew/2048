#include <iostream>
using namespace std;
#define n 4
int a[n][n]={0};

int random_index(int x) 	//generates random index btw 0 and n-1
{
	int index=rand()%x;
	return index;
}

void generate_random()   //fills grid with a 2/4
{
	while(true)
	{
		int i=random_index(n);
		int j=random_index(n);
		if(a[i][j]==0)
		{	
			int temp=rand()%2;
			if(temp==0)
				a[i][j]=2;
			else
				a[i][j]=4;
			break;
		}
	}
}

void initilaize()   //initializes grid
{
	int i=random_index(n);
	int j=random_index(n);
	a[i][j]=2;
	i=random_index(n);
	j=random_index(n);
	a[i][j]=2;              
}

void display()              //display
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<"   ";
	}

	char ch;
	cout<<"\nEnter move\n";
	cin>>ch;
	switch(ch)
	{
	  case 'a': move_left();
	  			display();
				break;
	  case 'w': move_up();
	  			display();
				break;
	  case 'd': move_right();
	  			display();
				break;
	  case 's': move_down();
	  			display();
				break;                  

	}
}

bool is_8086()                  //checks if 8086 formed
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i][j]==8086)
				return true;
	return false;
}

bool is_full()                  //checks if grid is full
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i][j]==0)
				return false;
	return true;
}


void move_up()                //moves numbers up
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(!a[j][i])
				for(int k=j+1;k<n;k++)
					if(a[k][i])
					{
						a[j][i]=a[k][i];
						a[k][i]=0;
						break;
					}
}

void move_down()             //moves numbers down
{
	for(int i=0;i<n;i++)
		for(int j=n-1;j>=0;j--)
			if(!a[j][i])
				for(int k=j-1;k>=0;k--)
					if(a[k][i])
					{
						a[j][i]=a[k][i];
						a[k][i]=0;
						break;
					}
}

void move_left()            //moves numbers left
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(!a[i][j])
				for(int k=j+1;k<n;k++)
					if(a[i][k])
					{
						a[i][j]=a[i][k];
						a[i][k]=0;
						break;
					}
}

void move_right()            //moves numbers right
{
	for(int i=0;i<n;i++)
		for(int j=n-1;j>=0;j--)
			if(!a[i][j])
				for(int k=j-1;k>=0;k--)
					if(a[i][k])
					{
						a[i][j]=a[i][k];
						a[i][k]=0;
						break;
					}
}

void merge_up();
void merge_down();
void merge_left();
void merge_right();

int main()
{
	initilaize();
	display();
	return 0;
}