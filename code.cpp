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

bool is_game_over()              //checks if any more moves possible
{
	for(int i=0;i<n;i++)         //merge_up possible
		for(int j=0;j<n;j++)
            if(a[j][i]==a[j+1][i])
                return false;

	for(int i=0;i<n;i++)         //merge_right possible
		for(int j=n-1;j>0;j--)
			if(a[i][j]==a[i][j-1])
                return false;
 
	for(int i=0;i<n;i++)         //merge_left possible
		for(int j=0;j<n-1;j++)
			if(a[i][j]==a[i][j+1])
            	return false;

	for(int i=0;i<n;i++)        //merge_down possible
		for(int j=n-1;j>0;j--)
			if(a[j][i]==a[j-1][i])
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

void merge_up()                //merges upward
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n-1;j++)
			if(a[j][i]==a[j+1][i] && a[j][i]!=0)
			{
				a[j][i]=a[j][i]*2;
                a[j+1][i]=0;
			}
}

void merge_down()              //merges downward
{
	for(int i=0;i<n;i++)
		for(int j=n-1;j>0;j--)
			if(a[j][i]==a[j-1][i] && a[j][i]!=0)
			{
				a[j][i]=a[j][i]*2;
                a[j-1][i]=0;
			}
}

void merge_left()            //merges left
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n-1;j++)
			if(a[i][j]==a[i][j+1] && a[i][j]!=0)
			{
				a[i][j]=a[i][j]*2;
                a[i][j+1]=0;
			}
}

void merge_right()            //merges right
{
	for(int i=0;i<n;i++)
		for(int j=n-1;j>0;j--)
			if(a[i][j]==a[i][j-1] && a[i][j]!=0)
			{
				a[i][j]=a[i][j]*2;
                a[i][j-1]=0;
			}
}

void display()              //display
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<"   ";
	}

	if(is_full())
		if(is_game_over())
		{
			cout<<"\nGame Lost";
			exit (0);
		}

	if(is_8086())
	{
		cout<<"\nGame Won";
		exit (0);
	}

	char ch;
	cout<<"\nEnter move\n";
	cin>>ch;
	switch(ch)
	{
	  case 'a': move_left();
	  			merge_left();
	  			move_left();
	  			generate_random();
	  			display();
				break;
	  case 'w': move_up();
	  			merge_up();
	  			move_up();
	  			generate_random();
	  			display();
				break;
	  case 'd': move_right();
	  			merge_right();
	  			move_right();
	  			generate_random();
	  			display();
				break;
	  case 's': move_down();
	  			merge_down();
	  			move_down();
	  			generate_random();
	  			display();
				break;                  

	}
}

int main()
{
	initilaize();
	display();
	return 0;
}