#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int speedX=1,speedY=0;
int condition=0; 
int level = 700; 
int option=1; int option2=1; int option3=1;int option4=1;
int a=50,b=20; // Game size: a is width, b is height
int snake[1000]; // Maximum length: 1000 units
int length; int prey = 11814; 
int score = 0; int highest;

void gotoxy(int x,int y); void box(); void set_color(const char *color); void gameguide(); void gameguidetv();
int random(int a,int b); int random_prey(); int getX(int a); int getY(int a); 
int w_highscore(); int r_highscore(); int w_language(); int r_language(); int w_level(); int r_level();

void menu(); void slevel(); void ingame(); void gameover(); void info(); void initgame(); void setting(); void language();
//void menutv(); void sleveltv(); void ingametv(); void gameovertv(); void infotv(); void settingtv(); 


enum state {MENU=0,INGAME,SLEVEL,GAMEOVER,INFO,SETTING,LANGUAGE} state;

/* Main */

int main(){
	set_color("01;32");
	while(1){
		r_language();
		switch(state){
			case MENU:
			menu();
			break;
			case SETTING:
			setting();
			break;
			case INGAME:
			ingame();
			break;
			case GAMEOVER:
			gameover();
			break;
			case INFO:
			info();
			break;
			case SLEVEL:
			slevel();
			break;
			case LANGUAGE:
			language();
			break;
		}
		w_language();
	} 
	return 0;
}

/* Functions */
	
	// gotoxy function
	void gotoxy(int x,int y){
  	static HANDLE h = NULL;  
  	if(!h)
    	h = GetStdHandle(STD_OUTPUT_HANDLE);
  		COORD c = { x, y };  
  		SetConsoleCursorPosition(h,c);
	}
	
	// Draw game area
	void box(){
		int i,j; 
		for(i=0;i<=a;i++){
			printf("#");
		}
		printf("\n");
		for(j=0;j<=b;j++){
			printf("#");
			for(i=0;i<=a-2;i++){
				printf(" ");
			}
			printf("#");
			printf("\n");
		}
		for(i=0;i<=a;i++){
			printf("#");
		}
		
	}
	
	int getX(int a){
		return (a-10000)/100;
	}
	
	int getY(int a){
		return a%100;
	}
	
	void menu(){
		system("cls");
		box();
		gotoxy(a/2-5,b/2);
		if(option4==1){
			printf("1. New game");
		}
		if(option4==2){
			printf("1. Game moi");
		}
		gotoxy(a/2-5,b/2+1);
		if(option4==1){
			printf("2. Setting");
		}
		if(option4==2){
			printf("2. Cai dat");
		}
		gotoxy(a/2-5,b/2+2);
		if(option4==1){
			printf("3. Info");
		}
		if(option4==2){
			printf("3. Gioi thieu");
		}
		gotoxy(a/2-11,b/2+4);
		if(option4==1){
			printf("Your choice: ");
		}
		if(option4==2){
			printf("Lua chon cua ban: ");
		}
		gotoxy(a/2-30,b/2+4);
		set_color("01;31");
		if(option==1){
			if(option4==1){
				printf("New game");
			}
			if(option4==2){
				printf("Game moi");
			}
			gotoxy(a/2-7,b/2);
			printf(">");
		}
		else if(option==2){
			if(option4==1){
				printf("Setting");
			}
			if(option4==2){
				printf("Cai dat");
			}
			gotoxy(a/2-7,b/2+1);
			printf(">");
		}
		else{
			if(option4==1){
				printf("Info");
			}
			if(option4==2){
				printf("Gioi thieu");
			}
			gotoxy(a/2-7,b/2+2);
			printf(">");
		}
		set_color("01;32");
			if(option4==1){
				gameguide();
			}
			if(option4==2){
				gameguidetv();
			}
		
		int t = getch();
		if(t==27){
			gotoxy(a+3,b+2);
			exit(0);
		}
    	if(t == 13){
        switch(option){
            case 1:
                state = INGAME;
                break;
            case 2:
                state = SETTING;
                break;
            case 3:
                state = INFO;
                break;
        }
    }

		else if (t==80){
	        option++; 
	    }
		else if (t==72){
	        option--; 
	    }
	if (option > 3){
		option = 1;
	}
	else if (option<1){
		option = 3;
	}
}


	void info(){
		system("cls");
		box();
		gotoxy(a/2-14,b/2);
			if(option4==1){
				printf("Author: Nguyen Luong Khang");
			}
			if(option4==2){
				printf("Tac gia: Nguyen Luong Khang");
			}
		gotoxy(a/2-11,b/2+2);
			if(option4==1){
				printf("My 13h effort  <3");
			}
			if(option4==2){
				printf("No luc 13h cua toi  <3");
			}
		gotoxy(a/2-12,b/2+6);
			if(option4==1){
				set_color("01;31"); printf("Menu (press Enter)\n"); set_color("01;32");
			}
			if(option4==2){
				set_color("01;31"); printf("Menu (nhan Enter)\n"); set_color("01;32");
			}
		if(option4==1){
			gameguide();
		}
		if(option4==2){
			gameguidetv();
		}
		int check;
		char a = getch();
		check =a;
		if(check==27){
			gotoxy(a+3,b+2);
			exit(0);
			}
		if(check==13){
			state = MENU;
		}
	}
		

	
	void slevel(){
		system("cls");
		box();
		gotoxy(a/2-4,b/2);
			if(option4==1){
				printf("1. Easy");
			}
			if(option4==2){
				printf("1. De");
			}
		gotoxy(a/2-4,b/2+1);
			if(option4==1){
				printf("2. Medium");
			}
			if(option4==2){
				printf("2. Binh thuong");
			}
		gotoxy(a/2-4,b/2+2);
			if(option4==1){
				printf("3. Hard");
			}
			if(option4==2){
				printf("3. Kho");
			}
		gotoxy(a/2-4,b/2+3);
			if(option4==1){
				printf("4. Go to setting");
			}
			if(option4==2){
				printf("4. Tro ve cai dat");
			}
		
		gotoxy(a/2-10,b/2+4);
			if(option4==1){
				printf("Your choice: ");
			}
			if(option4==2){
				printf("Lua chon cua ban: ");
			}
		r_level();
		gotoxy(a/2-30,b/2+4);
		set_color("01;31");
		if(option2==1){
			if(option4==1){
				printf("Easy");
			}
			if(option4==2){
				printf("De");
			}
			gotoxy(a/2-7,b/2);
			printf(">");
		}
		else if(option2==2){
			if(option4==1){
				printf("Medium");
			}
			if(option4==2){
				printf("Binh thuong");
			}
			gotoxy(a/2-7,b/2+1);
			printf(">");
		}
		else if(option2==3){
			if(option4==1){
				printf("Hard");
			}
			if(option4==2){
				printf("Kho");
			}
			gotoxy(a/2-7,b/2+2);
			printf(">");
		}
		else{
			if(option4==1){
				printf("Go to setting");
			}
			if(option4==2){
				printf("Tro ve cai dat");
			}
			gotoxy(a/2-6,b/2+3);
			printf(">");
		}
		set_color("01;32");
			if(option4==1){
				gameguide();
			}
			if(option4==2){
				gameguidetv();
			}
		int t2 = getch();
    	if(t2 == 13){
        switch(option2){
            case 1:
            	level = 700;
                state = INGAME;
                break;
            case 2:
            	level = 550;
                state = INGAME;
                break;
            case 3:
            	level = 200;
                state = INGAME;
                break;
            case 4:
                state = SETTING;
                break;
        }
    }

		else if (t2==80){
	        option2++; 
	    }
		else if (t2==72){
	        option2--; 
	    }
	    if(t2==27){
			gotoxy(a+3,b+2);
			exit(0);
		}
	if (option2 > 4) 
	        option2=1;
	else if (option2<1)
	        option2 = 4;
	w_level();
}

void language(){
	system("cls");
	box();
		gotoxy(a/2-4,b/2);
		printf("1. English");
		gotoxy(a/2-4,b/2+1);
		printf("2. Tieng Viet");
		gotoxy(a/2-10,b/2+4);
		printf("Your choice: ");
		gotoxy(a/2-30,b/2+4);
		set_color("01;31");
		if(option4==1){
			printf("English");
			gotoxy(a/2-6,b/2);
			printf(">");
		}
		else{
			printf("Tieng Viet");
			gotoxy(a/2-6,b/2+1);
			printf(">");
		}
		set_color("01;32");
		gameguide();
		int t3 = getch();
    	if(t3 == 13){
        switch(option4){
            case 1:
                state = MENU;
                break;
            case 2:
                state = MENU;
                break;
        }
    }

		else if (t3==80){
	        option4++; 
	    }
		else if (t3==72){
	        option4--; 
	    }
	    if(t3==27){
			gotoxy(a+3,b+2);
			exit(0);
		}
	if (option4 > 2) 
	        option4=1;
	else if (option4<1)
	        option4= 2;
}

void setting(){
	system("cls");
	box();
		gotoxy(a/2-4,b/2);
			if(option4==1){
				printf("1. Level");
			}
			if(option4==2){
				printf("1. Cap do");
			}
		gotoxy(a/2-4,b/2+1);
			if(option4==1){
				printf("2. Language");
			}
			if(option4==2){
				printf("2. Ngon ngu");
			}
		gotoxy(a/2-10,b/2+4);
			if(option4==1){
				printf("Your choice: ");
			}
			if(option4==2){
				printf("Lua chon cua ban: ");
			}
		gotoxy(a/2-30,b/2+4);
		set_color("01;31");
		if(option3==1){
			if(option4==1){
				printf("Level");
			}
			if(option4==2){
				printf("Cap do");
			}
			gotoxy(a/2-6,b/2);
			printf(">");
		}
		else{
			if(option4==1){
				printf("Language");
			}
			if(option4==2){
				printf("Ngon ngu");
			}
			
			gotoxy(a/2-6,b/2+1);
			printf(">");
		}
		set_color("01;32");
		if(option4==1){
				gameguide();
			}
			if(option4==2){
				gameguidetv();
			}
		int t3 = getch();
    	if(t3 == 13){
        switch(option3){
            case 1:
                state = SLEVEL;
                slevel();
                break;
            case 2:
                state = LANGUAGE;
                language();
                break;
        }
    }

		else if (t3==80){
	        option3++; 
	    }
		else if (t3==72){
	        option3--; 
	    }
	    if(t3==27){
			gotoxy(a+3,b+2);
			exit(0);
		}
	if (option3 > 2) 
	        option3=1;
	else if (option3<1)
	        option3= 2;
}
	
	void ingame(){
		system("cls");
		initgame();
		int key = 0;
		box();
		while(state==INGAME){
			if(kbhit()){
			/*
				if input from the keyboard,
				the kbhit function will return true otherwise it will return false
			*/
			key = getch();
				switch(key){
					
					/* Control by Arrow key */
					
					case 72: //up
						if(speedX!=0){
							speedY=-1; speedX=0;
						}
					break;
					case 80 : // down
						if(speedX!=0){
							speedY=1; speedX=0;
						}
					break;
					case 75: //  left
						if(speedY!=0){
							speedY=0; speedX=-1;
						}
					break;
					case 77: // right
						if(speedY!=0){
							speedY=0; speedX=1;
						}
					break;
					
					case 27: // esc
						state = GAMEOVER;
					break;
					
					/* Control by A,S,D,W */
					
					case 'w': // up
						if(speedX!=0){
							speedY=-1; speedX=0;
						}
					break;
					case 's' : // down
						if(speedX!=0){
							speedY=1; speedX=0;
						}
					break;
					case 'a': //  left
						if(speedY!=0){
							speedY=0; speedX=-1;
						}
					break;
					case 'd': // right
						if(speedY!=0){
							speedY=0; speedX=1;
						}
					break;
				}	
			}
			
			if((condition%level)==0){
				gotoxy(getX(snake[length-1]),getY(snake[length-1]));
				printf(" ");
				int i;
				for(i=length-1;i>0;i--){
					snake[i]=snake[i-1];
				}
				snake[0] += speedY;
				snake[0] += speedX*100;
				// move y
					if(getY(snake[0])==0){ snake[0] += (b+1); }
					if(getY(snake[0])==(b+2)){ snake[0] -= (b+1); }
				// move x
					if(getX(snake[0])==0){ snake[0] += (a-1)*100; }
					if(getX(snake[0])==a){ snake[0] += -(a-1)*100; }
				if(snake[0]==prey){
					gotoxy(getX(prey),getY(prey));
					printf("o");
					length++;
					random_prey();
					score +=5;
				}
				gotoxy(getX(snake[0]),getY(snake[0]));
				printf("X");
				gotoxy(getX(snake[1]),getY(snake[1]));
				printf("o");
				gotoxy(getX(prey),getY(prey));
				printf("*");
				for(i=1;i<length;i++){
					if(snake[0]==snake[i]){
						state = GAMEOVER;
					}
				}
			}
			condition++;
			gotoxy(a+3,b/2-5);
			printf(" Score = %d",score);
			gotoxy(a+3,b/2-4);
			r_highscore();
			if(option4==1){
				printf(" High Score = %d",highest);
			}
			if(option4==2){
				printf(" Diem cao nhat = %d",highest);
			}
			if(option4==1){
				gameguide();
			}
			if(option4==2){
				gameguidetv();
			}
		}
		w_highscore();
	}
	
	void initgame(){
		length = 5;
		// original length : 5 unit
		snake[0] = 11010;
	}
	
	int random(int a,int b){
		return a + rand()%(b-a+1);
	}
	
	int random_prey(){
		int x=0,y=0;
		int i;
		for(i=0;i<length;i++){
			prey=10000+random(1,a-3)*100;
			prey+=random(1,b-3);
			for(y;y<length;y++){
				if(prey==snake[i]){
					x=1;
				}
				if(!x){
					break;
				}
			}
		}
	}
	
	void gameover(){
		system("cls");
		box();
		gotoxy(a/2-5,b/2);
		printf("GAME OVER\n\n");
		gotoxy(a/2-5,b/2+1);
		if(option4==1){
			if(score >= highest){
				printf("Score = %d",highest);
			}
			else
			printf("Score = %d",score);
		}
		if(option4==2){
			if(score >= highest){
				printf("Diem = %d",highest);
			}
			else
			printf("Diem = %d",score);
		}
		score = 0;
		gotoxy(a/2-10,b/2+4);
		set_color("01;31");
			if(option4==1){
				printf("Menu (press Enter)\n");
			}
			if(option4==2){
				printf("Menu (nhan Enter)\n");
			}
		set_color("01;32");
			if(option4==1){
				gameguide();
			}
			if(option4==2){
				gameguidetv();
			}
		int check;
		char a = getch();
		check =a;
		if(check==27){
			gotoxy(a+3,b+2);
			exit(0);
			}
		if(check==13){
			state = MENU;
			option=1;
		}
	}
	
	
	void set_color(const char *color) {
    	char cmd[512];
    	sprintf(cmd, "echo|set /p=\"\e[%sm\"", color);
    	system(cmd);
	}
	
	int w_highscore(){
		FILE *h;
		h = fopen("highest.txt","w");
		if(h==NULL){
			printf("\nCan't Open or Create cache file");
			exit(1);
		}
		if(score>=highest){
			highest = score;
			fprintf(h, "%d", highest);
		}
		fclose(h);
		
	}
	
	int r_highscore(){
		FILE *h;
		h = fopen("highest.txt","r");
		if(h==NULL){
			printf("\nCan't Open or Create cache file");
			exit(1);
		}
		fscanf(h, "%d", &highest);
		fclose(h);	
	}
	
	int w_language(){
		FILE *l;
		l = fopen("language.txt","w");
		if(l==NULL){
			printf("\nCan't Open or Create cache file");
			exit(1);
		}
			fprintf(l, "%d", option4);
		fclose(l);	
	}
	
	int r_language(){
		FILE *l;
		l = fopen("language.txt","r");
		if(l==NULL){
			printf("\nCan't Open or Create cache file");
			exit(1);
		}
		fscanf(l, "%d", &option4);
		fclose(l);	
	}
	
	int w_level(){
		FILE *sl;
		sl = fopen("level.txt","w");
		if(sl==NULL){
			printf("\nCan't Open or Create cache file");
			exit(1);
		}
			fprintf(sl, "%d", option2);
		fclose(sl);	
	}
	
	int r_level(){
		FILE *sl;
		sl = fopen("level.txt","r");
		if(sl==NULL){
			printf("\nCan't Open or Create cache file");
			exit(1);
		}
		fscanf(sl, "%d", &option2);
		fclose(sl);	
	}
	
	void gameguide(){
		gotoxy(a+3,b/2+1);
		printf(" Use arrow keys: up, down, left and right to control");
		gotoxy(a+3,b/2+2);
		printf(" You can also use: A,S,D,W");
		gotoxy(a+3,b/2+6);
		printf(" EXIT: press Esc");
	}
	void gameguidetv(){
		gotoxy(a+3,b/2+1);
		printf(" Su dung phim mui ten de di chuyen");
		gotoxy(a+3,b/2+2);
		printf(" Ban cung co the dung: A,S,D,W");
		gotoxy(a+3,b/2+6);
		printf(" Thoat: nhan Esc");
	}
	
	
	
	
	
	
	
	

