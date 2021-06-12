#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "header.h" 

int main(void){
	int score,k;
	score=0;
	k=1;
	start();
	random_start();
	map_print();
	printf("point=%d\n",score);
	while(k!=0){
		char direction;
		scanf("%c",&direction);
		if(direction=='W'||direction=='w'){
			score=score+up();
			k=check();
			system("cls");
			map_print();
			printf("point=%d\n",score);
		}
		else if(direction=='S'||direction=='s'){
			score=score+down();
			k=check();
			system("cls");
			map_print();
			printf("point=%d\n",score);
		}
		else if(direction=='D'||direction=='d'){
			score=score+right();
			k=check();
			system("cls");
			map_print();
			printf("point=%d\n",score);
		}
		else if(direction=='A'||direction=='a'){
			score=score+left();
			k=check();
			system("cls");
			map_print();
			printf("point=%d\n",score);
		}		
	}
	printf("game over");
	return 0;
} 

void start(void){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			map[i][j]=0;
		}
	}
}

void random_start(void){
	srand(time(NULL)); 
	int k,l,m,n;
	int a=0;
	int b=N-1;
	k=0;
	l=0;
	m=0;
	n=0;
	while(m==k&&n==l){
		k=rand()%(b-a+1)+a;
		l=rand()%(b-a+1)+a;
		m=rand()%(b-a+1)+a;
		n=rand()%(b-a+1)+a;
	}
	map[k][l]=2;
	map[m][n]=2;
}

void map_print(void){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%7d",map[i][j]);
		}
		printf("\n");
	}
}

void map_record(void){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			record[i][j]=map[i][j];
		}
	}
}

void random(void){
	srand(time(NULL)); 	
	int a=0;
	int b=N-1;
	int c,d,e,f;
	e=rand()%10;
	if(e!=0){
		f=2;
	}
	else{
		f=4;
	}
	c=rand()%(b-a+1)+a;
	d=rand()%(b-a+1)+a;
	while(map[c][d]!=0){
		c=rand()%(b-a+1)+a;
		d=rand()%(b-a+1)+a;
	}
	map[c][d]=f;
}

int up(void){	
	int i,j,k;
	int l;
	int n;
	n=0;
	map_record();
	for(j=0;j<N;j++){
		for(i=0;i<N-1;i++){
			if(map[i][j]==0){
				for(k=i+1;k<N;k++){
					if(map[k][j]!=0){
						map[i][j]=map[k][j];
						map[k][j]=0;
						break;
					}
				}
			}
			if(map[i][j]!=0){
				for(k=i+1;k<N;k++){
					if(map[k][j]!=0){
						if(map[k][j]==map[i][j]){
							n=n+map[i][j]*2;
							map[i][j]=map[i][j]*2;
							map[k][j]=0;
							break;
						}
						else{
							l=map[k][j];
							map[k][j]=0;
							map[i+1][j]=l;
							break;
						}
					}
				}
			}	
		}
	}
	if(check2()==1){
		random();
	}		
	return n;
} 

int down(void){		
	int i,j,k;
	int l;
	int n;
	n=0;
	map_record();
	for(j=0;j<N;j++){
		for(i=N-1;i>0;i--){
			if(map[i][j]==0){
				for(k=i-1;k>=0;k--){
					if(map[k][j]!=0){
						map[i][j]=map[k][j];
						map[k][j]=0;
						break;
					}
				}
			}
			if(map[i][j]!=0){
				for(k=i-1;k>=0;k--){
					if(map[k][j]!=0){
						if(map[k][j]==map[i][j]){
							n=n+map[i][j]*2;
							map[i][j]=map[i][j]*2;
							map[k][j]=0;
							break;
						}
						else{
							l=map[k][j];
							map[k][j]=0;
							map[i-1][j]=l;
							break;
						}
					}
				}
			}	
		}
	}
	if(check2()==1){
		random();
	}
	return n;
}

 

int left(void){		
	int i,j,k;
	int l;
	int n;
	n=0;
	map_record();
	for(i=0;i<N;i++){
		for(j=0;j<N-1;j++){
			if(map[i][j]==0){
				for(k=j+1;k<N;k++){
					if(map[i][k]!=0){
						map[i][j]=map[i][k];
						map[i][k]=0;
						break;
					}
				}
			}
			if(map[i][j]!=0){
				for(k=j+1;k<N;k++){
					if(map[i][k]!=0){
						if(map[i][k]==map[i][j]){
							n=n+map[i][j]*2;
							map[i][j]=map[i][j]*2;
							map[i][k]=0;
							break;
						}
						else{
							l=map[i][k];
							map[i][k]=0;
							map[i][j+1]=l;
							break;
						}
					}
				}
			}	
		}
	}
	if(check2()==1){
		random();
	}	
	return n;
}



int right(void){		
	int i,j,k;
	int l;
	int n;
	n=0;
	map_record();
	for(i=0;i<N;i++){
		for(j=N-1;j>0;j--){
			if(map[i][j]==0){
				for(k=j-1;k>=0;k--){
					if(map[i][k]!=0){
						map[i][j]=map[i][k];
						map[i][k]=0;
						break;
					}
				}
			}
			if(map[i][j]!=0){
				for(k=j-1;k>=0;k--){
					if(map[i][k]!=0){
						if(map[i][k]==map[i][j]){
							n=n+map[i][j]*2;
							map[i][j]=map[i][j]*2;
							map[i][k]=0;
							break;
						}
						else{
							l=map[i][k];
							map[i][k]=0;
							map[i][j-1]=l;
							break;
						}
					}
				}
			}	
		}
	}
	if(check2()==1){
		random();
	}		
	return n;
}

 

int check(void){
	int i,j;
	int n,m;
	n=1;
	m=0;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i==0&&j==0){
				if(map[i][j]!=0&&(map[i][j]!=map[i+1][j]&&map[i][j]!=map[i][j+1])){
					m++;
				}
			}
			else if(i==0&&j==N-1){
				if(map[i][j]!=0&&(map[i][j]!=map[i+1][j]&&map[i][j]!=map[i][j-1])){
					m++;
				}
			}
			else if(i==N-1&&j==0){
				if(map[i][j]!=0&&(map[i][j]!=map[i-1][j]&&map[i][j]!=map[i][j+1])){
					m++;
				}
			}
			else if(i==N-1&&j==N-1){
				if(map[i][j]!=0&&(map[i][j]!=map[i-1][j]&&map[i][j]!=map[i][j-1])){
					m++;
				}
			}/*¨¤¸¨*/ 
			else if(i==0&&(j!=0&&j!=N-1)){
				if(map[i][j]!=0&&(map[i][j]!=map[i][j-1]&&map[i][j]!=map[i][j+1]&&map[i][j]!=map[i+1][j])){
					m++;
				}
			}
			else if(j==0&&(i!=0&&i!=N-1)){
				if(map[i][j]!=0&&(map[i][j]!=map[i-1][j]&&map[i][j]!=map[i][j+1]&&map[i][j]!=map[i+1][j])){
					m++;
				}
			}
			else if(i==N-1&&(j!=0&&j!=N-1)){
				if(map[i][j]!=0&&(map[i][j]!=map[i-1][j]&&map[i][j]!=map[i][j-1]&&map[i][j]!=map[i][j+1])){
					m++;
				}
			}
			else if(j==N-1&&(i!=0&&i!=N-1)){
				if(map[i][j]!=0&&(map[i][j]!=map[i-1][j]&&map[i][j]!=map[i][j-1]&&map[i][j]!=map[i+1][j])){
					m++;
				}
			}/*Ãä*/ 
			else{
				if(map[i][j]!=0&&(map[i][j]!=map[i-1][j]&&map[i][j]!=map[i][j-1]&&map[i][j]!=map[i][j+1]&&map[i][j]!=map[i+1][j])){
					m++;
				}
			}
		}	
	}
	if(m==N*N){
		n=0;
	}
	return n;
}

int check2(void){
	int i,j;
	int n;
	n=0;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(map[i][j]==record[i][j]){
				n++;
			}
		}
	}
	if(n<N*N){
		return 1;
	}
	else{
		return 0;
	}
}
