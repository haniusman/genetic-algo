#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 
#include <time.h> 
int main(){ 
	struct pop{ 
		float x; 
		float y; 
		float z; 
	}; 
	int N; 
	for(N=0;N<10;N++){ 
	 
	struct pop p[10]; //for population 
	struct pop par[10]; //parent 
	struct pop offI[10]; //intermediate offspring  
	struct pop offF[10]; //final offspring 
	struct pop sur[10];//Srurvivor 
	int i,j,a; 
	float maximum[40]; 
	float avg[40]; 
	struct pop tp[20];//total final population --Generation 
	float tfit=0; //total fitness
	int M;//40 wala loop 
	 
	for(M=0;M<40;M++) 
	{ 
	 
	//random population x,y and computed fitness 
	if(M==0){ 
	printf("\n\nPopulation\n"); 
	printf("X \t Y \t Fitness\n"); 
	for(i=0;i<10;i++){ 
		p[i].x= rand() % 10 -5; 
		p[i].y= rand() % 10 -5; 
		p[i].z= (p[i].x*p[i].x)+(p[i].y*p[i].y); 
		printf("%.1f \t %.1f \t %.1f\n",p[i].x,p[i].y,p[i].z); 
	} 
	//FPS parent selection 
	printf("\n\nParents\n"); 
	printf("\tX \t Y \t Fitness\n"); 
	struct fps{ 
		float fit; 
		float prob; 
		float r1; 
		float r2; 
	}; 
	for(i=0;i<20;i++){ 
		tfit += p[i].z;	 
	} 
	
/*	for(i=0;i<10;i++){ 
		int sno=rand() % 10; 
		printf("sno = %d  ",sno); 
		par[i].x=p[sno].x; 
		par[i].y=p[sno].y; 
		par[i].z= (par[i].x*par[i].x)+(par[i].y*par[i].y);	 
		printf("%.1f \t %.1f \t %.1f\n",par[i].x,par[i].y,par[i].z);	 
	} */
	
	printf("\nTotal fitness = %f",tfit); 
	 
	struct fps T[10];//fps table 
	float temp=0; 
	printf("\n\nFit\t\tProb\t\tRange\n"); 
	for(i=0;i<10;i++){ 
		T[i].fit=p[i].z; 
		T[i].prob = T[i].fit / tfit; 
		T[i].r1 = temp; 
		T[i].r2 = temp+T[i].prob; 
		temp =T[i].r2; 
		printf("%.3f\t\t%.3f\t\t%.3f--%.3f\n",T[i].fit,T[i].prob,T[i].r1,T[i].r2); 
	} 
	//Float random 
	srand((unsigned int)time(NULL)); 
    float a = 1.0,frand[10]; 
    for (i=0;i<10;i++){ 
    	frand[i]=((float)rand()/(float)(RAND_MAX)) * a; 
    } 
    printf("\n\nSurvivor\n"); 
	printf("X \t Y \t Fitness\n"); 
     
    int j; 
    for(i=0;i<10;i++){ 
    	for(j=0;j<20;j++){ 
    		if(frand[i]>=T[j].r1&&frand[i]<T[j].r2){ 
    			par[i].x=p[j].x; 
    			par[i].y=p[j].y; 
    			par[i].z=p[j].z; 
			} 
		} 
		printf("frand = %f\n",frand[i]); 
		printf("%.2f \t %.2f \t %.2f\n",sur[i].x,sur[i].y,sur[i].z); 
	} 
	
} 
	else{ 
		printf("\n\nParents\n"); 
	printf("\tX \t Y \t Fitness\n"); 
		for(i=0;i<10;i++) 
		{ 
			par[i].x=sur[i].x; 
			par[i].y=sur[i].y; 
			par[i].z=sur[i].z; 
			printf("%.1f \t %.1f \t %.1f\n",par[i].x,par[i].y,par[i].z); 
		} 
	} 
	 
	//Intermediate offspring index 0 static --Crossover 
	printf("\n\nIntermediate Offspring\n"); 
	printf("X \t Y \t Fitness\n"); 
	for(i=0;i<10;i=i+2){ 
		offI[i].x=par[i].x; 
		offI[i+1].x=par[i+1].x; 
		offI[i].y=par[i+1].y; 
		offI[i+1].y=par[i].y; 
		offI[i].z= (offI[i].x*offI[i].x)+(offI[i].y*offI[i].y); 
		offI[i+1].z= (offI[i+1].x*offI[i+1].x)+(offI[i+1].y*offI[i+1].y); 
		printf("%.1f \t %.1f \t %.1f\n",offI[i].x,offI[i].y,offI[i].z); 
		printf("%.1f \t %.1f \t %.1f\n",offI[i+1].x,offI[i+1].y,offI[i+1].z); 
	} 
	//Final Offspring --Mutation 
	printf("\n\nFinal Offspring\n"); 
	printf("X \t Y \t Fitness\n"); 
	for(i=0;i<10;i++){ 
		int sel = rand() % 2; //to select index 
		if(sel==0){ 
			offF[i].x=offI[i].x; 
			if(i<5){ 
				offF[i].y=offI[i].y+0.25; 
				if(offF[i].y>5||offF[i].y<=-5) 
				{ 
					offF[i].y=offI[i].y; 
				} 
			} 
			else if(i>=5){ 
				offF[i].y=offI[i].y-0.25; 
				if(offF[i].y>5||offF[i].y<=-5) 
				{ 
					offF[i].y=offI[i].y; 
				} 
			} 
		} 
		else if(sel==1){ 
			offF[i].y=offI[i].y; 
			if(i<5){ 
				offF[i].x=offI[i].x+0.25; 
				if(offF[i].x>5||offF[i].x<=-5) 
				{ 
					offF[i].x=offI[i].x; 
				} 
			} 
			else if(i>=5){ 
				offF[i].x=offI[i].x-0.25; 
				if(offF[i].x>5||offF[i].x<=-5) 
				{ 
					offF[i].x=offI[i].x; 
				} 
			}	 
		} 
		offF[i].z= (offF[i].x*offF[i].x)+(offF[i].y*offF[i].y); 
		printf("%d\n",sel); 
		printf("%.2f \t %.2f \t %.2f\n",offF[i].x,offF[i].y,offF[i].z);	 
	} 
	//Generation of 20 
	struct pop tp[20];//total final population --Generation 
	float tfit=0; //total fitness 
	printf("\n\nGeneration\n\n"); 
	for(i=0;i<10;i++){ 
		tp[i].x=par[i].x; 
		tp[i].y=par[i].y; 
		tp[i].z=par[i].z; 
		printf("%.2f \t %.2f \t %.2f\n",tp[i].x,tp[i].y,tp[i].z); 
	} 
	for(i=10;i<20;i++){ 
		tp[i].x=offF[i-10].x; 
		tp[i].y=offF[i-10].y; 
		tp[i].z=offF[i-10].z; 
		printf("%.2f \t %.2f \t %.2f\n",tp[i].x,tp[i].y,tp[i].z); 
	} 
	//truncation
	 for (i = 0; i < 20; ++i) 
        {
 
            for (j = i + 1; j < 20; ++j)
            {
 
                if (tp[i].z > tp[j].z) 
                {
 
                    a = tp[i].z;
                    tp[i].z = tp[j].z;
                    tp[j].z = a;
 
                }
 
            }
 
        }
        for(i=0;i<20;i++)
        {
        	printf("%f",tp[i].z);
		}
		
		for(i=10;i<20;i++)
		{
			sur[i].x=tp[i].x;
			sur[i].y=tp[i].y;
			sur[i].z=tp[i].z;
		}
		printf("%.2f \t %.2f \t %.2f\n",sur[i].x,sur[i].y,sur[i].z); 
	/*//FPS technique 
	struct fps{ 
		float fit; 
		float prob; 
		float r1; 
		float r2; 
	}; 
	for(i=0;i<20;i++){ 
		tfit += tp[i].z;	 
	} 
	printf("\nTotal fitness = %f",tfit); 
	 
	struct fps T[20];//fps table 
	float temp=0; 
	printf("\n\nFit\t\tProb\t\tRange\n"); 
	for(i=0;i<20;i++){ 
		T[i].fit=tp[i].z; 
		T[i].prob = T[i].fit / tfit; 
		T[i].r1 = temp; 
		T[i].r2 = temp+T[i].prob; 
		temp =T[i].r2; 
		printf("%.3f\t\t%.3f\t\t%.3f--%.3f\n",T[i].fit,T[i].prob,T[i].r1,T[i].r2); 
	} 
	//Float random 
	srand((unsigned int)time(NULL)); 
    float a = 1.0,frand[10]; 
    for (i=0;i<10;i++){ 
    	frand[i]=((float)rand()/(float)(RAND_MAX)) * a; 
    } 
    printf("\n\nSurvivor\n"); 
	printf("X \t Y \t Fitness\n"); 
     
    int j; 
    for(i=0;i<10;i++){ 
    	for(j=0;j<20;j++){ 
    		if(frand[i]>=T[j].r1&&frand[i]<T[j].r2){ 
    			sur[i].x=tp[j].x; 
    			sur[i].y=tp[j].y; 
    			sur[i].z=tp[j].z; 
			} 
		} 
		printf("frand = %f\n",frand[i]); 
		printf("%.2f \t %.2f \t %.2f\n",sur[i].x,sur[i].y,sur[i].z); 
	} */
maximum[M] = tp[0].z;	 
for (i = 0; i < 20; i++) 
  { 
    if (tp[i].z > maximum[M]) 
    { 
       maximum[M]  = tp[i].z; 
    } 
  } 
	printf("\n\n\nBFS = %f",maximum[M]); 
	avg[M] = tfit/20;	 
	printf("\n\n\nAverage = %f",avg[M]); 
	 printf("\n tfit = %.5f",tfit);
} 
 
printf("\n\nRun %d\n",N+1); 
printf("S.no \t BFS \t\t AVG\n"); 
for(i=0;i<40;i++) 
{ 
	printf("%d \t %f \t %f\n",i+1,maximum[i],avg[i]); 
} 
getche(); 
} 
getch();

return 0;
}

