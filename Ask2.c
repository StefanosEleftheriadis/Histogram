#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ArraySize 100

//******************************************
void read(int Rresults[ArraySize],int *Rstudcount);
float Average(const int Aresults[ArraySize],int Astudcount);
float Standard_deviation(const int Sresults[ArraySize],int Sstudcount, float Savg);
void gradecount_percentage(const int Gresults[ArraySize],int Gcount_phasma[10],int Gstudcount);
int Maximum(const int Mcount_phasma[10]);
void display(const int Dcount_phasma[10],float DstandDevation,float Davg,int DMax);
void histogram(const int Hcount_phasma[10],int HMax);
//******************************************

//******************************************
int main()
{
	int results[ArraySize],studcount,count_phasma[10]={0},Max;
	float avg,standDevation;
	
	//Read the input
	read(results,&studcount);
	
	//Find the average
	avg=Average(results,studcount);
	
	//Find the Standard deviation
	standDevation=Standard_deviation(results,studcount,avg);
	
	//Find the number of students in every phasma
	//count_phasma is an array to save the number of students in every phasma
	gradecount_percentage(results,count_phasma,studcount);

	// Find the maximum result
	Max=Maximum(count_phasma);
	
	system("CLS");
	
	//Print the output
	display(count_phasma,standDevation,avg,Max);
	
	system("pause");
	return 0;
}
//******************************************

//******************************************
void read(int Rresults[ArraySize],int *Rstudcount)
{
	int counter;
	
	do{
		printf("Enter the number of students(1-100): ");
		scanf("%d",Rstudcount);
	
		if(*Rstudcount<1 || *Rstudcount>100)
		{
			printf("Wrong Input!\n");
		}
	}while(*Rstudcount<1 || *Rstudcount>100);
	
	for(counter=0;counter<*Rstudcount;counter++)
	{
		do{
			printf("Enter the grade of student[%d](0-100): ",counter);
			scanf("%d",&Rresults[counter]);
			
			if(Rresults[counter]<0 || Rresults[counter]>100)
			{
				printf("Wrong Input!\n");
			}
		}while(Rresults[counter]<0 || Rresults[counter]>100);
	}
}
//******************************************

//******************************************
float Average(const int Aresults[ArraySize],int Astudcount)
{
	int counter;
	float sum=0.0,average;
	
	for(counter=0;counter<Astudcount;counter++)
	{
		sum+=Aresults[counter];
	}
	average=sum/counter;
	
	return average;
}
//******************************************

//******************************************
float Standard_deviation(const int Sresults[ArraySize],int Sstudcount, float Savg)
{
	int counter;
	float sum=0.0,standard_deviation;
	
	for(counter=0;counter<Sstudcount;counter++)
	{
		sum+=pow((Sresults[counter]-Savg),2);
	}

	standard_deviation=sqrt(sum/counter);
	
	return standard_deviation;
}
//******************************************

//******************************************
void gradecount_percentage(const int Gresults[ArraySize],int Gcount_phasma[10],int Gstudcount)
{
	int icount,counter;
	
	//calculate the phasma
	
	for(icount=0;icount<Gstudcount;icount++)
	{
		if(Gresults[icount]>=90)
		{
			Gcount_phasma[9]+=(1*100/Gstudcount);
		}
		else if(Gresults[icount]>=80)
		{
			Gcount_phasma[8]+=(1*100/Gstudcount);
		}
		else if(Gresults[icount]>=70)
		{
			Gcount_phasma[7]+=(1*100/Gstudcount);
		}
		else if(Gresults[icount]>=60)
		{
			Gcount_phasma[6]+=(1*100/Gstudcount);
		}
		else if(Gresults[icount]>=50)
		{
			Gcount_phasma[5]+=(1*100/Gstudcount);
		}
		else if(Gresults[icount]>=40)
		{
			Gcount_phasma[4]+=(1*100/Gstudcount);
		}
		else if(Gresults[icount]>=30)
		{
			Gcount_phasma[3]+=(1*100/Gstudcount);
		}
		else if(Gresults[icount]>=20)
		{
			Gcount_phasma[2]+=(1*100/Gstudcount);
		}
		else if(Gresults[icount]>=10)
		{
			Gcount_phasma[1]+=(1*100/Gstudcount);
		}
		else
		{
			Gcount_phasma[0]+=(1*100/Gstudcount);
		}
		
	}
	
}
//******************************************

//******************************************
int Maximum(const int Mcount_phasma[10])
{
	int counter, maxx;
	
	maxx=Mcount_phasma[0];
	
	for(counter=1;counter<10;counter++)
	{
		if(maxx<Mcount_phasma[counter])
		{
			maxx=Mcount_phasma[counter];
		}
	}
	
	return maxx;
}
//******************************************

//******************************************
void display(const int Dcount_phasma[10],float DstandDevation,float Davg,int DMax)
{
	printf("Average= %.2f\nStandard Deviation = %.2f\n",Davg,DstandDevation);
	
	histogram(Dcount_phasma,DMax);
}
//******************************************

//******************************************
void histogram(const int Hcount_phasma[10],int HMax)
{
	int counter,ycount;
	
	printf("    ^\n");
	do{
		//y aksona
		for(ycount=HMax;ycount>=1;ycount--)
		{
			printf("%3d%%",ycount);
		
		
			printf("|");
			
			if(ycount==HMax)
			{
				//histogram
				for(counter=0;counter<10;counter++)
				{
					printf("\t");
					if(Hcount_phasma[counter]>=HMax)
					{
						printf("%c",254);
					}
					else
					{
						printf(" ");
					}
				}
				HMax--;
			}
			printf("\n");
		}
	}while(HMax>0);
	
	for(counter=0;counter<=90;counter++)
	{
		printf("_");
	}
	printf(">\n");
	
	//x aksonas
	for(counter=0;counter<=90;counter+=10)
	{
		if(counter==0)
		{
			printf("\t<10");
		}
		else if(counter==90)
		{
			printf("\t>=90%%");
		}
		else
		{
			printf("\t%d-%d%%",counter,counter+9);
		}
	}
	printf("\n");
	
}
//******************************************
