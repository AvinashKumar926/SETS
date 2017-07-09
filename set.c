/*TITLE: SET OPERATION
	REPRESENT SETS USING 1-D ARRAYS	AND IMPLEMENT FUNCTIONS TO PERFORM
	1.UNION
	2.DIFERENCE
	3.INTERACTION
	4.SYMMETRIC DIFFERENCE OF TWO SETS
	
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void accept(int Arr[],int size)		//FOR ACCEPTING VALUE
{	int i;
	printf("SIZE=%d",size);
	printf("\nENTER THE ELEMENT IN SET:");	
	for(i=0;i<size;i++)
	{	scanf("%d",&Arr[i]);
	}
}
void display(int Arr[],int size)		//FOR DISPLAY VALUE
{	int i;
	printf("\nTHE ELEMENT IN SET:");
	printf("{");
	for(i=0;i<size;i++)
	{	if(i<size-1)
			printf("%d,",Arr[i]);
		else if(i==size-1)
		{	printf("%d}",Arr[i]);
		}
	}
}
int uni(int A[],int m,int B[],int n,int UNO[])		//for union
{	int i,j,l,k=0;
	for(l=0;l<m;l++)
	{	UNO[k]=A[l];
		k++;	
	}
	for(j=0;j<n;j++)
	{	for(i=0;i<m;i++)
		{	if(B[j]==A[i])
			break;		
		}
		if(i==m)
		{	UNO[k]=B[j];
			k++;		
		}
	}
	return(k);
}
int intersection(int A[],int m,int B[],int n,int INT[])					//for intersection
{	int i,j,l,k=0;
	for(j=0;j<n;j++)
	{	for(i=0;i<m;i++)
		{	if(B[j]==A[i])
			{	break;			
			}
		}
		if(i!=m)
		{	INT[k++]=B[j];
		}		
	}
	return(k);


}
int difference(int A[],int m,int B[],int n,int DIF[])			//for difference
{	int i,j,k=0;
	for(j=0;j<n;j++)
	{	for(i=0;i<m;i++)
		{	if(B[j]==A[i])
			{	break;			
			}
		}
		if(i==m)
		{	DIF[k++]=B[j];
		}	
	}
	return(k);

}

int sdiff(int DIFBA[],int difba,int DIFAB[],int difab,int SDIF[])			//for symmetric	difference
{	int k;
	k=uni(DIFAB,difab,DIFBA,difba,SDIF);	
	return(k);
}


void show(int A[],int m,int B[],int n)	//for showing output
{	printf("\nSET A:");
	display(A,m);
	printf("\nSET B:");
	display(B,n);
}	

int main()
{	int A[20],B[20],UNO[50],DIFAB[50],DIFBA[50],INT[50],SDIF[50];	
	int m,n,uno,difab,difba,in,sd,choice,inp;
	system("clear");
	do
	{	printf("\t\t\t\tWELCOME");
		printf("\nENTER THE NUMBER OF ELEMENT IN SET A:");
		scanf("%d",&m);
		accept(A,m);
		display(A,m);	
		printf("\nENTER THE NUMBER OF ELEMENT IN SET B:");
		scanf("%d",&n);
		accept(B,n);
		display(B,n);
		printf("\n^!^ THANKYOU FOR INPUT ^!^\n");
		getchar();
		getchar();
		system("clear");
		do
		{	printf("\nMENU:\n1.UNION\n2.INTERSECTION\n3.DIFFERENCE\n4.SYMMETRIC DIFFERENCE\n5.EXIT\n");
			printf("\nCHOOSE YOUR CHOICE:");
			scanf("%d",&choice);	
			switch(choice)
			{	case 1:	//union
					show(A,m,B,n);	
					uno=uni(A,m,B,n,UNO);
					printf("\nAFTER UNION:");
					display(UNO,uno);
					break;
				case 2:	//intersection
					show(A,m,B,n);
					in=intersection(A,m,B,n,INT);
					printf("\nAFTER INTERSECTION:");
					display(INT,in);
					break;
				case 3:	//difference
					show(A,m,B,n);
					difba=difference(B,n,A,m,DIFBA);
					printf("\nAFTER DIFFERENCE A-B:");
					display(DIFBA,difba);
					difab=difference(A,m,B,n,DIFAB);
					printf("\nAFTER DIFFERENCE B-A:");
					display(DIFAB,difab);
					break;
				case 4:	//symetric differece
					show(A,m,B,n);
					sd=sdiff(DIFBA,difba,DIFAB,difab,SDIF);
					printf("\nAFTER SYMETRIC DIFFERENCE:");
					display(SDIF,sd);
					break;
				case 5:	exit(0);
				default:printf("^!^SRY WRONG CHOICE^!^");
			}
			printf("\nIF U WANT TO CONTINUE WITH SAME NUMBER PRESS 1 AND IF NOT PRESS 0:\n");
			scanf("%d",&inp);
			system("clear");
		}while(inp==1);
	}while(inp==0);	
	return 0;
}
