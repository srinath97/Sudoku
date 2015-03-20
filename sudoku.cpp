#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
struct node
{
      int r,c;
      node* next;
};
node *top=0;
void push(int v1,int v2)
{
   node *temp=new node;
   if(temp)
   {
       temp->r=v1;
       temp->c=v2;
       temp->next=top;
       top=temp;
   }
}
int pop(int &v1,int &v2)
{
    if(top!=0)
    {
          v1=top->r;
          v2=top->c;
          top=top->next;
          return 1;
    }
    else
    	return 0;
}    
struct sudo
{
	int val;
	int f;
};
sudo a[9][9];
int check(int i ,int j)
{
	int v;
	for(v=0;v<9;v++)
	{
		if(a[i][v].val==a[i][j].val&&j!=v)
			return 0;
	}
	for(v=0;v<9;v++)
	{
		if(a[v][j].val==a[i][j].val && i!=v)
			return 0;
	}
	int k,l;
	if(i<=2)
		k=0;
	else if(i>=3&&i<=5)
		k=3;
	else
		k=6;
	if(j<=2)
		l=0;
	else if(j>=3&&j<=5)
		l=3;
	else
		l=6;
	int m=k+2,n=l+2;
	for(k=m-2;k<=m;k++)
	{
		for(l=n-2;l<=n;l++)
		{
			if(a[k][l].val==a[i][j].val&&k!=i&&l!=j)
				return 0;
		}
	}
	return 1;
}
int main()
{
		int i,j,k,l,m,n,flag=1;
		cout<<"Enter a sudoku question. Enter 0 for values to be found\n";
    	for(i=0;i<9;i++)
    	{
    		for(j=0;j<9;j++)
    		{
    			cin>>a[i][j].val;
    			if(a[i][j].val==0)
    				a[i][j].f=0;
    			else
    				a[i][j].f=1;
    		}
    	}
    	for(i=0;i<9&&flag; )
    	{
    		for(j=0;j<9&&flag; )
    		{
    			if(a[i][j].f==0)
    			{
    				push(i,j);
    				do
    				{
    					a[i][j].val++;
    				}while(!check(i,j)&&a[i][j].val<=9);
    				if(a[i][j].val>9)
    				{
    					a[i][j].val=0;
    					pop(i,j);
    					flag=pop(i,j);
    				}
    				else
    				j++;
    			}
    			else
    				j++;
    		}
    		i++;
    	}
    	if(flag==0)
    	{
    	   cout<<"There is no solution for this sudoku!!!";
        }
    	else
    	{
    		cout<<"The solution is:\n";
            for(i=0;i<9;i++)
        	{
        		for(j=0;j<9;j++)
        		{
        			cout<<a[i][j].val<<" ";
                }
        		cout<<"\n";
        	}
        }
    	while(top!=0)
    	{
    		pop(i,j);
    	}
    	cin.get();
    	cin.get();
}
