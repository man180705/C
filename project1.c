#include<stdio.h>
#include<stdbool.h>

int i,j,k=0,l=0,g,h=0,f=0;
int x,y;
bool flag = false;
char a[3][3];
char choice;
char ch[1];
char swap;

void print_board();
void enter_entry();
void player_move();
void reset_board(int ,int);
void new_board1(char a[3][3],int n,int m);
void new_board2(char a[3][3],int n,int m);
void new_board3(char a[3][3],int n,int m);
void new_board4(char a[3][3],int n,int m); 
int rows();
int columns();
void check_board();

int main()
{
	printf("enter the numbers(the input should be continuous,positive and single digit(without any space))\n");
	enter_entry();
	print_board();
	printf("\n");
	
	do
	{
		rows();
		columns();
		check_board();
		player_move();
		if(((k>=0) || (k<=2))  &&  ((l>=0) || (l<=2)))
		{
			reset_board(k,l);
		}
		else
		{
			rows();
			columns();
			reset_board(k,l);	
		}
		check_board();
		print_board();
		f++;
	} while(flag == false );
	
	if(flag == true)
	{
		printf("you take %d moves.",f);
		printf("the board is now sorted,hence you won the game.\n");
	}
	return 0;
}

void print_board()
{	
	printf(" %c | %c | %c ",a[0][0],a[0][1],a[0][2]);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c ",a[1][0],a[1][1],a[1][2]);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c ",a[2][0],a[2][1],a[2][2]);
	printf("\n");
	return;
}

void enter_entry()
{
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%c",&a[i][j]);
		}
	}
	//a[2][2]=' ';
}

int rows()
{
	k=0;
	printf("please enter the address of empty row(1-3)");
	scanf("%d",&k);
	printf("you entered row as %d",k);
	k = k-1;
	printf("%d",k);
	return k;
}

int columns()
{
	l=0;
	printf("\nplease enter the address of empty column(1-3)");
	scanf("%d",&l);
	printf("you entered row as %d",l);
	l = l-1;
	return l;
}

void player_move()
{
	printf("\nPLAYER please enter your choice(you can enter only one choice as (w,W,a,A,s,S,d,D)) :\n ");
	scanf("%s",&ch[0]);
	if((ch[0] =='W') || (ch[0] =='w') || (ch[0] =='a') || (ch[0] =='A') || (ch[0] =='s') || (ch[0] =='S') || (ch[0] =='d') || (ch[0]=='D'))
	{
		printf("\nthe choice of the player is %c\n",ch[0]);
	}
	else
	{
		printf("\nenter correct choice");
		//scanf("%c",&ch);
		player_move();
	}
}

void reset_board(int u,int v)
{
	{
		if(ch[0] == 'w' || ch[0] == 'W')
		{
			new_board1(a,u,v);
		}
			
		else if (ch[0] == 'a' || ch[0] == 'A')
		{
			new_board2(a,u,v);
		}
		
		else if (ch[0] == 's' || ch[0] == 'S')
		{
			new_board3(a,u,v);
		}
		else if (ch[0] == 'd' || ch[0] == 'D')
		{
			new_board4(a,u,v);
		}
	}	
	return;
}

void new_board1(char a[3][3],int n,int m)
{
	swap = a[n][m];
	a[n][m] = a[n-1][m];
	a[n-1][m] = swap;
}

void new_board2(char a[3][3],int n,int m)
{
	swap = a[n][m];
	a[n][m] = a[n][m-1];
	a[n][m-1] = swap;
}

void new_board3(char a[3][3],int n,int m)
{
	swap = a[n][m];
	a[n][m]= a[n+1][m];
	a[n+1][m] = swap;
	return;
}

void new_board4(char a[3][3],int n,int m)
{
//	swap=&a[k][l];
//	g=0;
//	g=l+1;
	swap = a[n][m];
	a[n][m] = a[n][m+1];
	a[n][m+1] = swap;
}

void check_board()
{
	if(a[2][2] ==' ')
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<2;j++)
			{
				if((a[i][j] < a[i][j+1]) && (a[0][2] < a[1][0]) && (a[1][2] < a[2][0]))
				{
					h = 0;	
				}
				else 
				{
					flag = false;
					break;
				}
			}
		}
		if(h == 0) flag = true;
	}
	else flag = false;
	return;
}