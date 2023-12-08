#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX_M 100
#define MAX_N 100
#include<time.h>
typedef struct {
	int m, n;
	int A[MAX_M][MAX_N];
	int r, c;
} State;

void init_state(State *S,int k){
    int i,j;
    if (k==1){
    	S->m=3;
    	S->n=3;
	}
    if (k==2){
    	S->m=4;
    	S->n=4;
	}
	if (k==3){
    	S->m=5;
    	S->n=5;
	}
    for (i=0;i<S->m;i++){
        for (j=0;j<S->n;j++){
            S->A[i][j]=i*S->n+j+1;
        }   
    }
    S->r=S->m-1;
    S->c=S->n-1;
}
void print_state(State S){
    int i,j,k;
    printf("						");
    for(i=0;i<S.m;i++)
    	printf("+---");
    printf("+\n");
    for(i=0;i<S.m;i++){
    	printf("						");
        for(j=0;j<S.n;j++){
            if(i==S.r&& j==S.c) printf("|.. ");
            else printf("|%2d ",S.A[i][j]);
        }
        printf("|\n");
        printf("						");
		for(k=0;k<S.m;k++)
    		printf("+---");
    	printf("+\n");
    }
      
}
int is_finished(State S){
    int i,j,x=1;
    for(i=0;i<S.m-1;i++){
        for(j=0;j<S.n;j++){
            if(S.A[i][j]!=i*S.n + j + 1){
                x=0;
                break;
            }
        }
    }
    for(i=S.m-1;i<S.m;i++){
        for(j=0;j<S.n-1;j++){
            if(S.A[i][j]!=i*S.n + j + 1){
                x=0;
                break;
            }
        }
    }
    if(x==1) return 1;
    else return 0;
}
int up(State S,State *N){
    if(S.r>0){
        *N=S;
        int tam=N->A[N->r][N->c];
        N->A[N->r][N->c]=N->A[N->r-1][N->c];
        N->A[N->r-1][N->c]=tam;
        N->r=N->r-1;
        return 1;
    }
    else return 0;
}
int down(State S,State *N){
    if(S.r<S.m-1){
        *N=S;
        int tam=N->A[N->r][N->c];
        N->A[N->r][N->c]=N->A[N->r+1][N->c];
        N->A[N->r+1][N->c]=tam;
        N->r=N->r+1;
        return 1;
    }
    else return 0;
}
int left(State S,State *N){
    if(S.c>0){
        *N=S;
        int tam=N->A[N->r][N->c];
        N->A[N->r][N->c]=N->A[N->r][N->c-1];
        N->A[N->r][N->c-1]=tam;
        N->c=N->c-1;
        return 1;
    }
    else return 0;
}
int right(State S,State *N){
    if(S.c<S.n-1){
        *N=S;
        int tam=N->A[N->r][N->c];
        N->A[N->r][N->c]=N->A[N->r][N->c+1];
        N->A[N->r][N->c+1]=tam;
        N->c=N->c+1;
        return 1;
    }
    else return 0;
}
void ingame(){
	printf(" 	 _                                    		      			       __________________\n");
	printf("	| |                                   		      			      |    ______________|\n");
	printf("	| |                                   		      			      |   |\n");
	printf("	| |                                         		      		       \\   \\\n");
	printf("	| |                                    		 		      		 \\   \\\n");
	printf("	| |                                       		      			   \\   \\\n");
	printf("	| |                                             		   		     \\   \\\n");
	printf("	| |  _____    _      _    __________	 __________    _          ________	       \\   \\\n");
	printf("	| | |  	_ \\  | |    | |  |________  |	|________  |  | |        |  ______|		 \\   \\\n");
	printf("	| | |  |_\\ | | |    | |          / / 	        / /   | |        | |______		  |  |\n"); 
	printf("	| | |  ___/  | |    | |        / /    	     / /      | |      	 |  ______|		  |  |\n");
	printf("	| | | |       \\ \\__/ /      _/ /___	  _/ /___     | |_____   | |______	 ________/   /\n");
	printf("	|_| |_|        \\____/      |_______| 	 |_______|    |_______|  |________|	|___________/\n");
}
int main(){
    State S,N;
    int g,c;
    char fname[20];
    char cmd; 
    int q;
    ingame();
	printf("		chose level to play:		|Game Guide:			|\n");
	printf("		1. Easy				|+ Use arrow keys to move.	|\n");
	printf("		2. Normal			|+ Press Esc to exit.		|\n");    
	printf("		3. Hard				|+ Press Tab to auto play.	|\n");
	scanf("%d",&g);
    init_state(&S,g);
    srand(time(0));
    int k=0;
    if (g==1) c=11;
    if(g==2) c=61;
    if (g==3) c=101;
    int a[500];
    int n=0;
    while (k!=c){  	
    	int d = (rand()%4)+1; ;
    	if(d==1) {
    		if (up(S,&N)){
    			S=N;
    			k++;
    			a[n]=1;
    			n++;
			}   			
		}
		else if(d==2){
			if (down(S,&N)){
    			S=N;
    			k++;
    			a[n]=2;
    			n++;
			}
		}
		else if(d==3){
			if (left(S,&N)){
    			S=N;
    			k++;
    			a[n]=3;
    			n++;
			}
		}
		else {
			if (right(S,&N)){
    			S=N;
    			k++;
    			a[n]=4;
    			n++;
			}
		}
		
	}
	int kt=is_finished(S);
    while(kt!=1){
    	system("cls");
    	ingame();
        print_state(S);
        cmd=getch();
        q=cmd;
        if(q==72){
            if(up(S,&N)){
            	S=N;
            	a[n]=1;
            	n++;
			}           
        }
        else if(q==80){
            if(down(S,&N)){
            	S=N;
            	a[n]=2;
            	n++;           
			}           
        }
        else if(q==75){
            if(left(S,&N)){
            	S=N;
            	a[n]=3;
            	n++;           
			}
        }
        else if(q==77){
            if(right(S,&N)){
            	S=N;
            	a[n]=4;
            	n++;           
			}           
        }
        else if(q==9){
        	int j;
			for(j=0;j<n;j++){
				if((a[j]==1 && a[j+1]==2 && a[j+2]==1)||(a[j]==2 && a[j+1]==1 && a[j+2]==2)||(a[j]==3 && a[j+1]==4 && a[j+2]==3)||(a[j]==4 && a[j+1]==3 && a[j+2]==4)){
					int l;
					for(l=j+1;l<n-2;l++){
						a[l]=a[l+2];
					}
					n=n-2;
				}
			}
			for(j=n-1;j>=0;j--){
				system("cls");
				if(a[j]==1){
					down(S,&N);
					S=N;
				}
				else if(a[j]==2){
					up(S,&N);
					S=N;
				}
				else if(a[j]==3){
					right(S,&N);
					S=N;
				}
				else {
					left(S,&N);
					S=N;
				}
			ingame();
			print_state(S);	
	}
		}
        else if(q==27){
        	ingame();
           	printf("You lose!\n");
           	break;
        }	
        else if(q==13){
        	system("cls");
        	main();
		}
        kt=is_finished(S);
    }
    if(kt==1) {
    	system("cls");
    	ingame();
    	print_state(S); 	
		printf("		+ Press Enter to return to the menu.\n"); 		
    	printf("		+ Press ESC to exit.\n");    	
    	printf("		You win!");
		cmd=getch();
        q=cmd;
        if(q==13){
        	system("cls");
        	main();
		}		
	}	
    return 0;
}
