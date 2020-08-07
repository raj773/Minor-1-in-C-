#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include<math.h>

int main()
{

char buff ;  
FILE *fp = fopen("Book1.csv","r") ;
int i,j,qw,comma=0,ara=0,sum=0;
char n[100000];
int count=0,total=0,line=0,dot=0,check=0,new[100],k=3,z=5;
double l,arr[10000],m,f[10000],dataa[100][100];

int dis[]={},new_mean[3]={0},g1[100][2]={0},g2[100][2]={0},g3[100][2]={0};
int a[100]={0},b[100]={0},c[100]={0};
int mean[3]={250,275,290};
//Counting the line,comma,total words
for(i=0; ;i++){
	buff= fgetc(fp);
	if(buff == EOF){
		break;
	}
	n[i]=buff;
	++total;
	if(buff==','){
		count+=1;
	}
	if(buff== '\n'){
		line+=1;
		if(line == 1){
			qw =i;
		}
	}
}
printf(" \n total Characters:%d \n  Comma:%d \n lines:%d \n",total,count,line);
for(i=qw+1;i<total;i++){
	if(!(n[i]==','||n[i]=='.'||n[i]=='\n')){
		if(comma>=2 && comma <=7){
			arr[ara]=(int)n[i]-'0';
			ara+=1;
			
		}
	}
	else{
		if(n[i]==','){
			comma+=1;
		}
		if(n[i]=='\n'){
			comma=0;
		}
		if(comma>=2 && comma <=7){
			arr[ara] = n[i];
			ara+=1;
			
		}
	}
}
arr[ara]=44;
printf("\n");

for(i=0;i<ara;i++){
	if(arr[i]!=44) {
		l = arr[i];
		while(arr[i]!=44){
			++i;
			if(arr[i]!=44) {
					m = arr[i];
					l= l*10 + m;
			}		
		}
	f[check]= l;
	++check;
	}
}
check=0;
for(i=0;i<line-1;i++){
	for(j=0;j<6;j++){
		dataa[i][j]=f[check];
		++check;
	}
}
for(i=0;i<line-1;i++){
	for(j=1;j<5;j++){
	sum= sum+dataa[i][j];
	}
	if(sum == dataa[i][5]){
		dataa[i][6]=1;
	}
	else{
		dataa[i][6]=0;
	}
	sum=0; 
}


for(i=0;i<line-1;i++){
	for(j=0;j<6;j++){
		printf("%0.0lf \t",dataa[i][j]);	
	}
	printf("\n");
}


//displaying mean values
for (i=0; i<3;i++)
{
	printf("\n");
    printf("mean %d\t", mean[i]);
}


//disttance
for (i=0; i<line-1;i++)
{
	a[i]=abs(dataa[i][z]-mean[0]);
	b[i]=abs(dataa[i][z]-mean[1]);
	c[i]=abs(dataa[i][z]-mean[2]);


}



//grouping

int xx=0,yy=0,zz=0;
for (i=0; i<line-1;i++)
	{
		if((a[i] < b[i])&&(a[i] < c[i]))
		{
		g1[xx][0]=dataa[i][0];
		g1[xx][1]=dataa[i][z];
		xx++;
		}
    	else
        {
        	if(b[i] < c[i])
        	{
        		g2[yy][0]=dataa[i][0];
        		g2[yy][1]=dataa[i][z];
				yy++;
			}
        	
        	else
        	{g3[zz][0]=dataa[i][0];
        	g3[zz][1]=dataa[i][z];
        	zz++;
			}
        }
	}



//update mean
int update_mean(int g1[100][2],int g2[100][2],int g3[100][2])
	{

		
		int sumofa=0,sumofb=0,sumofc=0;
		//length of all the groups using count
		int countg1=0,countg2=0,countg3=0;
		for(i=0;i<100;i++)
		{
			if(g1[i][1]>0)
			countg1=countg1+1;
			if(g2[i][1]>0)
			countg2=countg2+1;
			if(g3[i][1]>0)
			countg3=countg3+1;
		}
	
	
		
		//updating mean
		for(i=0;i<100;i++)
		{
			sumofa=sumofa+g1[i][1];
			sumofb=sumofb+g2[i][1];
			sumofc=sumofc+g3[i][1];
			
		}
		
		new_mean[0]=sumofa/countg1;
		new_mean[1]=sumofb/countg2;
		new_mean[2]=sumofc/countg3;
		
		
		for (j=0; j<3;j++)
		{
			printf("\n");
    		printf("New mean %d\t", new_mean[j]);
		}
	
	}
	
	
//update distance
int update_group(int a[100],int b[100],int c[100],double dataa[100][100],int g1[100][2],int g2[100][2],int g3[100][2])
	{   
		for(i=0;i<100;i++)
		{
			for(j=0;j<3;j++)
			{	
				g1[i][j]=0;
				g2[i][j]=0;
				g3[i][j]=0;
			}
			
		}
		int xx=0,yy=0,zz=0;
		for (i=0; i<line-1;i++)
		{
			if((a[i] < b[i])&&(a[i] < c[i]))
			{
			g1[xx][0]=dataa[i][0];
			g1[xx][1]=dataa[i][z];
			xx++;
			}
	    	else
	        {
	        	if(b[i] < c[i])
	        	{
	        		g2[yy][0]=dataa[i][0];
	        		g2[yy][1]=dataa[i][z];
					yy++;
				}
	        	
	        	else
	        	{g3[zz][0]=dataa[i][0];
	        	g3[zz][1]=dataa[i][z];
	        	zz++;
				}
	        }
		}

	
		
	}
	
int display_group(int g1[100][2],int g2[100][2],int g3[100][2])
	{
				
		printf("\n");		
		for (i=0; i<100;i++)
		{
			printf("%d \t", g1[i][0]);
		}
		printf("\n");
		for (i=0; i<100;i++)
		{
			printf("%d \t", g2[i][0]);
		}
		printf("\n");
		for (i=0; i<100;i++)
		{
			printf("%d \t", g3[i][0]);
		}
	}	
	
	
//update distance	
int	update_dis(int a[100],int b[100],int c[100],double dataa[100][100],int new_mean[3])
	{   
		for (i=0; i<line-1;i++)
		{
			a[i]=abs(dataa[i][z]-new_mean[0]);
			b[i]=abs(dataa[i][z]-new_mean[1]);
			c[i]=abs(dataa[i][z]-new_mean[2]);
		}			
	}

int ii=0;
while(ii<5)
{
	
	update_mean(g1,g2,g3);
	update_dis(a,b,c,dataa,new_mean);
	update_group(a,b,c,dataa,g1,g2,g3);
	//display_group(g1,g2,g3);
	ii+=1;
}
printf("\n");
for(i=0;i<100;i++)
{
    if(dataa[i][0]>0)
	{
	for(j=0;j<100;j++){
	
	if(dataa[i][0]==g1[j][0])
	{	
		printf("\n");
		
		printf("group 1 C %d\t",g1[j][0]);
	}
	}
}}
printf("\n");
for(i=0;i<100;i++)
{
    if(dataa[i][0]>0)
	{
	for(j=0;j<100;j++){
	
	if(dataa[i][0]==g2[j][0])
	{	
		printf("\n");
		
		printf("group 2 B %d\t",g2[j][0]);
	}
	}
}}
printf("\n");
for(i=0;i<100;i++)
{
    if(dataa[i][0]>0)
	{
	for(j=0;j<100;j++){
	
	if(dataa[i][0]==g3[j][0])
	{	
		printf("\n");
		
		printf("group 3 A %d\t",g3[j][0]);
	}
	}
	}
}


}


