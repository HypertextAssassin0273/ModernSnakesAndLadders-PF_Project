#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<MMsystem.h>

#define backspace 8
#define tab 9
#define load 12
#define enter 13
#define New 14
#define save 19
#define hardescape 23
#define escape 27
#define up 72
#define down 80
#define right 77
#define left 75

HANDLE handle_var; //i.e. global declaration
#define handle_var GetStdHandle(STD_OUTPUT_HANDLE) //Note: Here,GetStdHandle() function is used to input specific modes for graphical representations on console
#define FOREGROUND_WHITE 7
#define FOREGROUND_YELLOW 6
#define FOREGROUND_PURPLE 5
#define FOREGROUND_LIGHTBLUE 3
//Note: Pre-defined available colours-> FOREGROUND_BLUE, FOREGROUND_RED, FOREGROUND_GREEN

typedef struct{
    char p1_name[20],p2_name[20];
    char game_name[20];
    char pass[10];
    char new_line;
}player;
/*Global Variable Declarations*/
player p_info;
int p1_cp=0,p2_cp=0,p1_tc=0,p2_tc=0,turn_flag=0,temp_game_mode=0,limit=0,previous_game_time=0; //Note: These variables will be stored/retrieved through 'Save/Load Game' function 
int temp_dice_mode=1,temp_dice_option=1; //i.e dice-settings , Note: By default temp_dice_mode->single-dice & temp_dice_option->auto
int snake_count=0,Z=0; //Note: For modern/turn knock-down mode
int i,j,k; //i.e. loop variables
int main_menu_flag=1,sound_flag=1;//i.e. switch variables
time_t start=0; int pg_time=0; //i.e. time variables
char file_names[2][50]; //i.e. in-game file names

void main_constructor();
void __attribute__((constructor)) main_constructor();
void gotoxy(int x,int y);
void welcome_screen();
void cursor_pointer(int x,int y);
void display_boxes();
void show_main_menu();
void show_dice_menu();
int dice_settings();
int random_dice();
int manual_dice();
void display_board(int board[][10]);
void show_stats(int turn_flag,int temp_cp,int temp_tc);
void locate_pointer_on_board(int temp_cp);
void estimated_func_time(int *const extra_time,int (*func)());
void show_win_menu();
void display_standard_time(int N);
void main_game();
int locate_menu_pointer();
int new_game();
int calc_slot_capacity();
void rename_data_files();
void delete_specific_slot();
void hidden_settings();
void password(char *const pass);
void save_game();
int load_game();
void guide();

int main(){
	/*Calculating Previous Game Time*/
	time_t pgt_end;
	time(&pgt_end);
	pg_time=(pgt_end-start);
	while(1){
		fflush(stdin); //Note: To clear previous input in buffer
		int cursor_ptr=1,choice=NULL;
		char hit=NULL;
		/*Display Main-Menu Contents*/
		system("cls");
		show_main_menu();
		/*Display Cursor Pointer*/	
		do{	
			gotoxy(48,4*cursor_ptr);	
			cursor_pointer(48,4*cursor_ptr);
			hit=getch();
			if (hit==down||hit==right)
			cursor_ptr++;
			else if(hit==up||hit==left)
			cursor_ptr--;
			else if(hit==enter)
			break;
			else if(hit==New){
			cursor_ptr=2;
			break;
			}
			else if(hit==save){
			cursor_ptr=3;
			break;
			}
			else if(hit==load){
			cursor_ptr=4;
			break;
			}
			else if(hit==escape){
			cursor_ptr=6;
			break;
			}
			else if(hit==tab){ //i.e. hidden settings
			cursor_ptr=9;
			break;
			}
			if (cursor_ptr==7)
			cursor_ptr=1;
			else if(cursor_ptr==0)
			cursor_ptr=6;
		}while(1);
		system("cls");
		switch (cursor_ptr){
			case 1: /*RESUME*/
			if (main_menu_flag){ //NOTE: To prevent from resuming the game initially
	        SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
			gotoxy(35,10);
	        printf("Loading Game is Presently Not Avaliable!!!\a");
	        SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
			getch();
	        break;
	        }
	        else
	        return;	
	        case 2: /*NEW GAME*/
	       	SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
			gotoxy(48,10);
        	printf ("Start a New Game(Y/N)?? ");
   	    	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
			choice=getchar();
    		if (choice=='y'||choice=='Y'){            
   	        if(new_game())
            main_game();
			}
			break;
    	    case 3: /*SAVE GAME*/
        	if (main_menu_flag){ //NOTE: To prevent from saving the game initially
        	SetConsoleTextAttribute(handle_var,FOREGROUND_RED);	
            gotoxy(28,10);
   	        printf("Sorry,you have to start a New Game first in order to Save Game!\a");
			SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE); 
			getch();
            }
            else
			save_game();
            break;
    	    case 4: /*LOAD GAME*/
		    if(load_game())
			main_game();
       	    break;
			case 5: /*GUIDE*/
			guide();
			getch();
			break;
			case 9:
			hidden_settings();
			break;
			case 6: /*EXIT*/
			SetConsoleTextAttribute(handle_var,FOREGROUND_YELLOW);
			gotoxy(39,12);
			printf("?????????????????????????????????????????");
       	    gotoxy(39,13);
			printf("?                                       ?");
       	    gotoxy(41,13);
			SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
			printf("Are you Sure You Want To Quit(Y/N)?");
			SetConsoleTextAttribute(handle_var,FOREGROUND_YELLOW);
			gotoxy(39,14);
			printf("?????????????????????????????????????????");
			SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
       	    gotoxy(81,13);
       	    choice=getchar();
       	    if (choice=='y'||choice=='Y'){
			gotoxy(0,30); 
			exit(0);
			}
			else
			break;		
			default:
			printf("\n!!Error!!\a");	
			exit(1);
		}
	}
	return 0;
}
void main_constructor(){ //Note: Used to make sure that included functions aren't re-used whenever main is called
    welcome_screen();
    /*Initializing File Names*/
	strcpy(file_names[0],"files\\\\in_game_variables.txt"); //Note: It keeps updated your file names if you have renamed the files in application
	strcpy(file_names[1],"files\\\\in_game_strings.txt"); //i.e. here \\\\->\\ `
}
void gotoxy(int x,int y){ //Note: x->coloumn & y->row  , i.e. gotoxy(col,row)
	COORD var; //Note: COORD->pre-defined structure
	var.X=x;
	var.Y=y;
	SetConsoleCursorPosition(handle_var,var);
}
void welcome_screen(){
    char name_string[16]={"Snakes & Ladders"};
	SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
    gotoxy(46,1);
	printf("S N A K E S & L A D D E R S");
    SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
 	gotoxy(46,20);
	printf("Press any key to continue...");
	SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);                     
	gotoxy(46,26);
	printf("Contributed By: ");
	SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
	gotoxy(50,27);
	printf("SHAHZAIB ");
    SetConsoleTextAttribute(handle_var,FOREGROUND_YELLOW);
	printf("AHMED ");
    SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
	printf("(19K-0273)");
	PlaySound(TEXT("sounds\\startup.wav"),NULL,SND_SYNC); //i.e. playing sound files
	for (i=21,j=99;!kbhit();i++,j--){ //Note: kbhit() returns '1' if any key is pressed, else returns '0' (without waiting for program execution)
        for (k=15;k>=0;k--){
        	if (i==86){
            i=21;
            continue;
        	}
            SetConsoleTextAttribute(handle_var,FOREGROUND_YELLOW);
            gotoxy(i+k,9);
			printf("%c",name_string[k]);
			gotoxy(i-1,9);
            printf(" ");
            if (j==35){
            j=99;
            continue;
        	}
            SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
            gotoxy(j-k-1,5);
            printf("%c",name_string[15-k]);
        	gotoxy(j,5);
            printf(" ");
            SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
            gotoxy(j-k-1,13);        	
            printf("%c",name_string[15-k]);
            gotoxy(j,13);
            printf(" ");
            gotoxy(20,5);
            printf("                ");
            gotoxy(20,9);
            printf("                ");
            gotoxy(20,13);
            printf("                ");
            gotoxy(83,5);
            printf("                  ");
            gotoxy(83,9);
            printf("                  ");
            gotoxy(83,13);
            printf("                  ");
        }
        Sleep(15);
    }
    SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
}
void cursor_pointer(int x,int y){
	for (i=0;!kbhit();i++){
    	if (i==1)
		printf("<");
        else if(i==2)
		printf ("^");
        else if(i==3)
		printf (">");
        else
		printf("v");
		gotoxy(x,y);
		Sleep(100);
		gotoxy(x,y);
        if (i==4)
        i=0;
    }
	printf("\b  ");
}
void display_boxes(){
	int y=3,z=0;
	for (i=1;i<=6;i++){
		for (j=1;j<=3;j++){	
			gotoxy(52,y+z);	
			for (k=1;k<=13;k++){
				if (j==1||j==3||k==1||k==13)
				printf("?");
				else
				printf(" ");
				}
				printf("\n");
				y++;
		}
		z++;
	}
}
void show_main_menu(){
	SetConsoleTextAttribute(handle_var,FOREGROUND_YELLOW);
	display_boxes();
	gotoxy(50,0);
	printf("!!!           !!!");
	gotoxy(50,1);
	printf("^^^^^^^^^^^^^^^^^");
	gotoxy(54,0);
	SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
	printf("MAIN MENU");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);	
	gotoxy(53,4);
	printf("  RESUME   ");
	gotoxy(53,8);
	printf(" NEW GAME  ");
	gotoxy(53,12);
	printf(" SAVE GAME ");
	gotoxy(53,16);
	printf(" LOAD GAME ");
	gotoxy(53,20);
	printf("   GUIDE   ");
	gotoxy(53,24);
	printf("   EXIT    ");
}
void show_dice_menu(){
	gotoxy(50,0);
	SetConsoleTextAttribute(handle_var,FOREGROUND_YELLOW);
	printf("!!!           !!!");
	gotoxy(50,1);
	printf("^^^^^^^^^^^^^^^^^");
	gotoxy(54,0);
	SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
	printf("DICE MENU");
	gotoxy(37,23);
	SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
	printf("Note: Press 'backspace' to go on Dice-Settings");
	gotoxy(37,25);
	printf("Note: Press 'ESC' to go on Main-Menu");
	gotoxy(0,2);
	SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
	printf("\n!!Hit any key to roll/stop the dice/dices!!\n");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);	
}
int dice_settings(){
	fflush(stdin); //Note: To clear buffers of different data-types that are filled through same format specifier
	system("cls");
	SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
	gotoxy(37,23);
	printf("Note: Enter 'any character' to go back on previous Menu");
	gotoxy(37,25);
	printf("Note: For Fair game-play,Settings can not be changed during a turn");
	gotoxy(0,1);
	SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
	printf ("Which type of dice u want?");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	printf("\n1.Auto\n2.Manual\n=>");
	while(1){
		scanf("%d",&temp_dice_option);	
		if (temp_dice_option==1||temp_dice_option==2)
		break;
	}
	SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
	printf("\nHow many Dices u want?");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
    printf("\n1.Single Dice\n2.Double Dice\n=>");	
	while(1){
		scanf("%d",&temp_dice_mode);
		if (temp_dice_mode==1||temp_dice_mode==2)
		break;
	}
	return 0;	
}
int random_dice(){
	srand(time(NULL)); //Note: It sets seed to produce random no. from different starting points 
	if (temp_dice_mode==1)	//i.e single dice
	return (rand()%6+1); //Note: Random dice no. generator
	else{ //i.e Double Dice
	int temp_dice_holder_1=0,temp_dice_holder_2=0;
	temp_dice_holder_1=rand()%6+1; temp_dice_holder_2=rand()%6+1;
	printf("Dices: %d %d\n",temp_dice_holder_1,temp_dice_holder_2);
	return (temp_dice_holder_1+temp_dice_holder_2);
	}
}
int manual_dice(){ 
    if (temp_dice_mode==1){ //i.e single dice
	printf("=>");
	for (i=1;1;i++){
        printf ("%d\b",i);
        if (i==6) 
		i=1;
		if (kbhit()){
		getch();
		printf("\b\b");
		return i;
		}
    }
	}
    else{  //i.e double dice 
	srand(time(NULL));
    printf("Dices: ");
	while(1){		
		int temp_dice_holder_1=0,temp_dice_holder_2=0;
		temp_dice_holder_1=rand()%6+1; temp_dice_holder_2=rand()%6+1;
        printf ("%d %d\b\b\b",temp_dice_holder_1,temp_dice_holder_2);
       	if (kbhit()){
		getch();
		printf("\n");
		return (temp_dice_holder_1+temp_dice_holder_2);
		}
	}
	}
}
void display_board(int board[][10]){
	int z=0;
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	for (i=9;i>-1;i--){
		if (i%2==1&&i!=9)
		printf ("%c",186);
		else
		printf (" ");
		if (i==9&&z==0){
		printf("       %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,187);	
		z=1;
		}
		else
		printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,185);	
	 	if (i%2==0)
		printf(" %c\n      ",186);
		else
		printf("\n      ");
		if (i%2==0){
		if (i==0){
		SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);	
		printf("\b\b\b\b\bStart");
		SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
		printf("%c>",205);
		}
		else
		printf("%c>",201);	
		for (j=0;j<10;j++){
			if (board[i][j]==4||board[i][j]==9||board[i][j]==20||board[i][j]==32||board[i][j]==40||board[i][j]==51||board[i][j]==63||board[i][j]==71){
			printf ("%c",186);
			SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
			printf(" L ");
			SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
			}
			else if(board[i][j]==27||board[i][j]==41||board[i][j]==53||board[i][j]==64||board[i][j]==82||board[i][j]==87||board[i][j]==93||board[i][j]==99){
			printf ("%c",186);
			SetConsoleTextAttribute(handle_var,FOREGROUND_RED); 
			printf (" S ");
			SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
			}
			else{
			printf("%c",186);
			SetConsoleTextAttribute(handle_var,FOREGROUND_YELLOW);	
			printf("%3d",board[i][j]);
			SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);	
			}
		}
		}
		else{
		if (i==9){
		SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);	
		printf("\b\b\b\b\b\bFinish");
		SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
		printf("<%c",205);	
		}
		else	
		printf ("%c%c",200,205);
		for (k=9;k>-1;k--){
			if (board[i][k]==4||board[i][k]==9||board[i][k]==20||board[i][k]==32||board[i][k]==40||board[i][k]==51||board[i][k]==63||board[i][k]==71){
			printf ("%c",186);
			SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
			printf(" L ");
			SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
			}
			else if(board[i][k]==27||board[i][k]==41||board[i][k]==53||board[i][k]==64||board[i][k]==82||board[i][k]==87||board[i][k]==93||board[i][k]==99){
			printf ("%c",186);
			SetConsoleTextAttribute(handle_var,FOREGROUND_RED); 
			printf (" S ");
			SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
			}	
 			else{
			printf("%c",186);
			SetConsoleTextAttribute(handle_var,FOREGROUND_YELLOW);
			printf ("%3d",board[i][k]);
			SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);	
			}
		}
		}
		if (i%2==0)
		printf ("%c%c%c\n      ",186,205,188);
		else
		printf ("%c<%c\n      ",186,187);
	}
	printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,188);	
}
void show_stats(int turn_flag,int temp_cp,int temp_tc){
	SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
	gotoxy(80,2);
	printf("STATS:-");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	if (turn_flag==0){
	gotoxy(80,3);
	printf("Turn: P1");
	gotoxy(80,4);
	printf("Name: %s",p_info.p1_name);
	}
	else{
	gotoxy(80,3);
	printf("Turn: P2");
	gotoxy(80,4);
	printf("Name: %s",p_info.p2_name);
	}
	gotoxy(80,5);	
	printf("Position: %d",temp_cp);
	gotoxy(80,6);
	printf("Turn: %d",temp_tc+1);
	gotoxy(80,8);
	SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
	printf("Note:-");	
	if (temp_game_mode>=1&&temp_game_mode<=3){
	gotoxy(80,9);
	SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
	printf("Ladder(L):");
	gotoxy(80,10);
	SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
	printf("Snake (S):");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	if (temp_game_mode==1||temp_game_mode==3){
	gotoxy(90,9);
	printf(" Position increases by 15");
	gotoxy(90,10);
	printf(" Position decreases by 20");
	}
	else if(temp_game_mode==2){
	gotoxy(90,9);
	printf(" Bonus Turn");
	gotoxy(90,10);
	printf(" Skip Turn");	
	}
	}
	else{
	gotoxy(80,9);
	SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
	printf("Ladder(L):");
	gotoxy(80,10);
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	printf(" ~ Bonus Turn");
	gotoxy(80,11);
	printf(" ~ Position increases by 15");
	gotoxy(80,12);
	SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
	printf("Snake (S):");	
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	gotoxy(80,13);
	printf(" ~ Skip Turn");
	gotoxy(80,14);
	printf(" ~ Position increases by 20");
	}	
}
void locate_pointer_on_board(int temp_cp){ //Note: x->col & y->row , i.e gotoxy(col,row)
	if (((100-temp_cp)/10)%2==1)
	gotoxy((40-(4*((100-temp_cp)%10)))+6,2*((100-temp_cp)/10)+1); //Note: c=(100-temp_cp)%10 ,so formula->40-4c & r=(100-temp_cp)/10 ,so formula->2r,+1->alignment
	else
	gotoxy((4*((100-temp_cp)%10)+4)+6,2*((100-temp_cp)/10)+1); //Note: c=(100-temp_cp)%10 ,so formula->4c+4 & r=(100-temp_cp)/10 ,so formula->2r,+1->alignment
	if (!(temp_cp<101)) //i.e points on 'finish' if game ends
 	gotoxy(3,1);
 	else if(!(temp_cp>0)) //i.e points on 'start' if some error occurs in rolling the dice initially
 	gotoxy(3,19);
}
void estimated_func_time(int *extra_time,int (*func)()){ //i.e. passing func_ptr as an argument
	time_t et_start,et_end;
	time(&et_start); //i.e. initial extra_time seed
	func();
	time(&et_end); //i.e. final extra_time seed
	*extra_time+=(et_end-et_start); //Note: Value is over-written directly by accessing it's address
}
void show_win_menu(){
	SetConsoleTextAttribute(handle_var,FOREGROUND_YELLOW);	
	gotoxy(50,3);
	printf("^^^^^^^^^^^^^^^^^^^");
	SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
	gotoxy(32,5);
	printf("P1 STATS:-");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	gotoxy(32,6);
	printf("Last Position: %d",p1_cp);
	gotoxy(32,7);
	printf("Last Turn: %d",p1_tc);
	SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
	gotoxy(73,5);
	printf("P2 STATS:-\n");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	gotoxy(73,6);
	printf("Last Position: %d",p2_cp);
	gotoxy(73,7);
	printf("Last Turn: %d",p2_tc);
	gotoxy(32,9);
	SetConsoleTextAttribute(handle_var,FOREGROUND_YELLOW);
	printf("*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
}
void display_standard_time(int N){
	struct time_format{
		int secs,mins,hours;
	}t;
	t.hours=(N/3600)%24;
	t.mins=(N/60)%60;
	t.secs=N%60;
	//NOTE: Using power set formula to calc. possible outcomes: 2n->8 possibilities, 8-1=7 (neglecting null possiblity)
	if (t.hours&&t.mins&&t.secs)
	printf("%d hours %d mins %d secs",t.hours,t.mins,t.secs);
	else if(t.mins&&t.secs)
	printf("%d mins %d secs",t.mins,t.secs);
	else if(t.hours&&t.mins)
	printf("%d hours %d mins",t.hours,t.mins);
	else if(t.hours&&t.secs)
	printf("%d hours %d secs",t.hours,t.secs);
	else if(t.secs)
	printf("%d secs",t.secs);	
	else if(t.mins)
	printf("%d mins",t.mins);
	else if(t.hours)
	printf("%d hours",t.hours);
}
void main_game(){	
	int initial_count=1,temp_dice=0,temp_cp=0,prev_cp=0,temp_tc=0;
	time_t end,et_start,et_end;
	int time_taken=0,extra_time=0;
	char X;
	/*Initializing the Positions on Board*/
	int board[10][10]; 
	for (i=0;i<10;i++)
		for (j=0;j<10;j++)
			board[i][j]=initial_count++;
	/*In-Game Process*/
	time(&start); //i.e. initial total_time seed
	while(1){		
previous_stats:
		system("cls");
		/*Previous STATS*/
		SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
		gotoxy(80,3);
		printf("STATS:-");
		SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
		/*Assigning Position & Turn for Player*/
		prev_cp=temp_cp;
		if (Z==1||(Z==2&&snake_count==2)){ //Note: To assign turns w.r.t Ladders or Snakes in Modern/Turn Knock-down Mode
		if (turn_flag==0)
		turn_flag=1;
		else
		turn_flag=0;
		if (Z==1){
		gotoxy(90,4);
		printf("(Bonus Turn!)");
		}
		else if(Z==2&&snake_count==2){
		gotoxy(90,4);
		if (turn_flag==0)
		printf("(P2 turn Skipped!)");
		else
		printf("(P1 turn Skipped!)");
		}
		Z=0;
		}
		if (turn_flag==0){ //Note: flag 0->p1,flag 1->p2
		gotoxy(80,4);
		printf("Turn: P1");
		gotoxy(80,5);
		printf("Name: %s",p_info.p1_name);
		temp_cp=p1_cp;
		temp_tc=p1_tc;
		}
		else if(turn_flag==1){
		gotoxy(80,4);
		printf("Turn: P2");		
		gotoxy(80,5);	
		printf("Name: %s",p_info.p2_name);	
		temp_cp=p2_cp;
		temp_tc=p2_tc;
		}
		else{
		printf("\n!!Error!!"); //Note: To make sure that no glitch/logical error is present
		exit(1);
		}
		gotoxy(80,6);
		printf("Previous Position: %d",temp_cp);
		gotoxy(80,7);
		printf("Previous Turn: %d",temp_tc);
		/*Dice Menu*/
		show_dice_menu();
backspace_warning_loop:
		X=getch();
		if (X==backspace){
		if (turn_flag==0){ //i.e restricting users from changing settings during a turn
		estimated_func_time(&extra_time,dice_settings);
		goto previous_stats; //i.e. maintaining previous display
		}
		else{
		gotoxy(37,21);
		printf("Warning: Settings can not be changed during a turn!\a");
		Sleep(800);
		gotoxy(37,21);
		printf("                                                   ");		
		gotoxy(0,4);
		goto backspace_warning_loop;
		}
		}
		else if(X==escape){
		estimated_func_time(&extra_time,main);
		goto previous_stats;
		}
		/*Dice Options*/
		if (temp_dice_option==1)
		temp_dice=random_dice();
		else if(temp_dice_option==2)
		temp_dice=manual_dice();
		printf("Your no. on dice/dices: %d",temp_dice);
		getch();
		temp_cp+=temp_dice;
		/*Display Contents of Board (BEFORE)*/
		system("cls");
		display_board(board);
		show_stats(turn_flag,temp_cp,temp_tc);
		locate_pointer_on_board(temp_cp);
		estimated_func_time(&extra_time,getch);
		/*Check Same Positions (in Modern/Turn Knock-down Mode)*/
		if ((temp_game_mode==2||temp_game_mode==4)&&(temp_cp==prev_cp)){
		gotoxy(1,25);
		SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
		printf("NOTE: You hit the previous player position!\a"); //Note: '\a' is used for system sound
		temp_cp=1;
		estimated_func_time(&extra_time,getch);
		goto display_contents_of_board;
		}
		/*Ladder*/
		if (temp_cp==4||temp_cp==9||temp_cp==20||temp_cp==32||temp_cp==40||temp_cp==51||temp_cp==63||temp_cp==71){
		if (sound_flag)
		PlaySound(TEXT("sounds\\ladder.wav"),NULL,SND_SYNC);
		else
		printf("\a");
		if (temp_game_mode==1||temp_game_mode==3){	
		temp_cp+=15; //ladder->increases CP by 15 boxes
		goto display_contents_of_board;
		}	
		else if(temp_game_mode==2||temp_game_mode==4){
		gotoxy(1,25);
		SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
		printf("NOTE: You got another turn for approaching Ladder!");
		Z=1;
		if (temp_game_mode==4){
		temp_cp+=15;
		goto display_contents_of_board;
		}
		else{
		estimated_func_time(&extra_time,getch);
		goto modern_or_turn_knockdown_mode;
		}
		}
		}
		/*Snake*/
		else if(temp_cp==27||temp_cp==41||temp_cp==53||temp_cp==64||temp_cp==82||temp_cp==87||temp_cp==93||temp_cp==99){
		if (sound_flag)
		PlaySound(TEXT("sounds\\snake.wav"),NULL,SND_SYNC);
		else
		printf("\a");
		if (temp_game_mode==1||temp_game_mode==3)
		temp_cp-=20; //snake->decreases CP by 20 boxes
		else if(temp_game_mode==2||temp_game_mode==4){
		gotoxy(1,25);
		SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
		printf("NOTE: You lost a turn for getting bitten by Snake!");
		Z=2;
		snake_count=0;
		if (temp_game_mode==4)
		temp_cp-=20;
		else{
		estimated_func_time(&extra_time,getch);
		goto modern_or_turn_knockdown_mode;
		}
		}
		/*Display Contents of Board (AFTER)*/
display_contents_of_board:	
		system("cls");
		display_board(board);
		show_stats(turn_flag,temp_cp,temp_tc);
		locate_pointer_on_board(temp_cp);
		estimated_func_time(&extra_time,getch);
		}
modern_or_turn_knockdown_mode:		
		/*Re-assigning CPP & Player Turn*/
		if (turn_flag==0){
		p1_cp=temp_cp;
		turn_flag=1;
		p1_tc++; //i.e player turn counter
		}
		else if(turn_flag==1){
		p2_cp=temp_cp;
		turn_flag=0;
		p2_tc++;
		}
		/*Time Calculation*/
		time(&end); //i.e. final total_time seed
		time_taken=(end-start); //i.e. no need for type-casting as diff. is of already int type
		if (temp_game_mode==2||temp_game_mode==4)
		snake_count++; //Note: To skip the turn of the player who has been bitten by snake
		if ((p1_cp>=100||p2_cp>=100)||(temp_game_mode==4&&(limit==p1_tc||limit==p2_tc))||(temp_game_mode==3&&(time_taken-extra_time+previous_game_time)>=limit))
		break;
	}
	/*Win Menu*/
	system("cls");
	SetConsoleTextAttribute(handle_var,FOREGROUND_YELLOW);
	gotoxy(50,2);
	printf("!!!             !!!");
	SetConsoleTextAttribute(handle_var,FOREGROUND_PURPLE);
	gotoxy(53,2);
	if (p1_cp>=100||((temp_game_mode==3||temp_game_mode==4)&&p1_cp>p2_cp))
	printf("PLAYER 1 WINS");
	else if(p2_cp>=100||((temp_game_mode==3||temp_game_mode==4)&&p2_cp>p1_cp))
	printf("PLAYER 2 WINS");	
	else
	printf("  MATCHDRAW  ");
	show_win_menu();
	gotoxy(48,11);
	printf("Total Duration: ");
	display_standard_time(time_taken+previous_game_time);
	gotoxy(48,12);
	printf("Match Duration: ");
	display_standard_time(time_taken-extra_time+previous_game_time);
	PlaySound(TEXT("sounds\\win.wav"),NULL,SND_SYNC);
	main_menu_flag=1; //NOTE: To prevent from saving/resuming the finished game
	getch();
}
int locate_menu_pointer(){ //i.e. for new_game & hidden_settings menu
    char hit=NULL; int cursor_ptr_pos=1;
	do{
		gotoxy(3,cursor_ptr_pos+1);
		cursor_pointer(3,cursor_ptr_pos+1);
		hit=getch();
		if (hit==down||hit==right)
		cursor_ptr_pos++;
		else if(hit==up||hit==left)
		cursor_ptr_pos--;
		else if(hit>48&&hit<53) //i.e. random choice
		return (hit-48);
		else if(hit==enter)
		return cursor_ptr_pos;
		else if(hit==escape)
		return 0;
		if (cursor_ptr_pos==5)
		cursor_ptr_pos=1;
		else if(cursor_ptr_pos==0)
		cursor_ptr_pos=4;
	}while(1);
}
int new_game(){
    system("cls");	
	SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
	printf("Game Mode\n");
	SetConsoleTextAttribute(handle_var,FOREGROUND_YELLOW);
	printf("^^^^^^^^^");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	printf("\n1)    Classic\n2)    Modern\n3)    Time Knockout\n4)    Turn Knockout");
	temp_game_mode=locate_menu_pointer(); //i.e. pointing cursor
	if (!temp_game_mode)
	return 0;
	if(temp_game_mode==3||temp_game_mode==4){
	while(1){
		limit=-1;
	    system("cls");
	    fflush(stdin);
		if(temp_game_mode==3)
	    printf("Select limit for Time in seconds (i.e 10-60): ");
		else
		printf("Select limit for Turns (i.e 10-20): ");
	    scanf("%d",&limit);
		if ((temp_game_mode==3&&limit>=10&&limit<=60)||(temp_game_mode==4&&limit>=10&&limit<=20))//i.e. limit->optimal settings
		break;
		printf("\a");
	}
	}
	while(1){
		system("cls");
		SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
		printf("Note: Same 'names' will not be accepted!");
	    SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
		printf("\n\nEnter 1st player's name (limit: 19 characters): ");
	    scanf("%s",p_info.p1_name); // i.e. can't use %[^\n] , gives error in filing
	    if(strlen(p_info.p1_name)<20){
	    fflush(stdin);
	    printf("Enter 2nd player's name (limit: 19 characters): ");
	    scanf("%s",p_info.p2_name);
	 	if (strcmp(p_info.p1_name,p_info.p2_name)&&strlen(p_info.p2_name)<20) //i.e to avoid same names, Note: strcmp() returns '0' for same & '1' for varying  
		break;
		}
		printf("\a");
	}
	/*Re-Initializing/Reseting In-Game Variables*/
  	if (strcmp(p_info.p1_name,"123")==0||strcmp(p_info.p1_name,"XYZ")==0){ //Note: For cheating/testing purpose
	p1_cp=98; p2_cp=0;
	}
	else if(strcmp(p_info.p2_name,"123")==0||strcmp(p_info.p2_name,"XYZ")==0){
	p1_cp=0; p2_cp=98;
	}
	else{
	p1_cp=0; p2_cp=0;
	}
	turn_flag=0; main_menu_flag=0;
	p1_tc=0; p2_tc=0;
	snake_count=0; Z=0;
	temp_dice_mode=1; temp_dice_option=1;
	previous_game_time=0;
	return 1;
}
int calc_slot_capacity(){
	FILE *in_game_strings_ptr=fopen(file_names[1],"r");
	player temp_info;
	if (in_game_strings_ptr==NULL)
	return 0;
	for(i=0;!feof(in_game_strings_ptr);i++,fread(&temp_info,sizeof(player),1,in_game_strings_ptr));
    fclose(in_game_strings_ptr);
	return (i-1); //i.e. to restrict from re-reading/re-scanning the values in last loop
}
void rename_data_files(){
	SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
	printf("\nWarning: Data-Files will not be accessible after restart,if the file names aren't changed back manually!");
	printf("\nNote: Type '0' or 'esc' to go back on previous Menu");
	SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
	printf("\n\nEnter new name for files: ");
	char temp_name_1[20],temp_name_2[30]="files\\\\",temp_name_3[30]="files\\\\";
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	scanf("%[^\n]",temp_name_1);
	if (!strcmp(temp_name_1,"0")||!strcmp(temp_name_1,"esc")||!strcmp(temp_name_1,"ESC"))
    return;
	strcat(temp_name_2,temp_name_1);
	strcat(temp_name_3,temp_name_1);
	strcat(temp_name_2,"_1.txt");
	int x=rename(file_names[0],temp_name_2);
	strcat(temp_name_3,"_2.txt");
	int y=rename(file_names[1],temp_name_3);
	strcpy(file_names[0],temp_name_2);
	strcpy(file_names[1],temp_name_3);
	system("cls");
	if (!(x||y)){
	SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
	printf("\nNote: File Names Changed Successfully!");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	printf("\nUpdated Names: 1) %s 2) %s",file_names[0],file_names[1]);
	}
	else{
	SetConsoleTextAttribute(handle_var,FOREGROUND_RED);	
	printf("\nError: File Names could not be Changed!\a");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	}
	getch();
}
void delete_specific_slot(){
	FILE *in_game_variables_ptr=fopen(file_names[0],"r"),*in_game_strings_ptr=fopen(file_names[1],"r"),*temp_file_1_ptr,*temp_file_2_ptr;
	int delete_line,temp_game_var[8],slot_capacity=calc_slot_capacity();
	player temp_info;
	if (in_game_variables_ptr==NULL||in_game_strings_ptr==NULL||!slot_capacity){
	SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
	gotoxy(49,12);
	printf("Error: Files not found!\a");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
    return;
	}
	while(1){
		delete_line=-1;
		system("cls");
		fflush(stdin);
		SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
		printf("Note: Enter '0' to go back on previous Menu!");
		SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
		printf("\nEnter slot number to be deleted (limit: 1-%d): ",slot_capacity);
		SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
    	scanf("%d",&delete_line);
    	if (delete_line==0){
		fclose(in_game_variables_ptr);
 	 	fclose(in_game_strings_ptr);
		return;
		}
		if(delete_line>0&&delete_line<=slot_capacity)
		break;
		printf("\a");
	}
    temp_file_1_ptr=fopen("files\\temp_file_1.txt","w");
	temp_file_2_ptr=fopen("files\\temp_file_2.txt","w");
	for(i=0;i!=slot_capacity;i++){
		for(j=0;j<8;j++)
			fscanf(in_game_variables_ptr,"%d",&temp_game_var[j]);
    	fread(&temp_info,sizeof(player),1,in_game_strings_ptr);
		if (i+1!=delete_line){
		for(j=0;j<8;j++)
			fprintf(temp_file_1_ptr,"%4d ",temp_game_var[j]);
		fprintf(temp_file_1_ptr,"\n");
		fwrite(&temp_info,sizeof(player),1,temp_file_2_ptr);
		}
	}
	fclose(in_game_variables_ptr);
    fclose(in_game_strings_ptr);
	fclose(temp_file_1_ptr);
	fclose(temp_file_2_ptr);
	remove(file_names[0]);
	remove(file_names[1]);
	rename("files\\temp_file_1.txt",file_names[0]);
	rename("files\\temp_file_2.txt",file_names[1]);
	system("cls");
	gotoxy(40,12);
	SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
	printf("Note: Files are Updated Successfully!");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	gotoxy(45,14);
    system("pause");
}
void hidden_settings(){
	while(1){
		system("cls");
		fflush(stdin);
		SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
		printf("HIDDEN SETTINGS\n");
		SetConsoleTextAttribute(handle_var,FOREGROUND_YELLOW);
		printf("^^^^^^^^^^^^^^^");
		SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
		printf("\n1)    Erase All Data\n2)    Delete Specific Slot\n3)    Rename Data Files (Note: Not Recommended!)\n4)    In-Game Sounds (ON/OFF)");
		int cursor_ptr=locate_menu_pointer(); //i.e. pointing cursor
		if (!cursor_ptr)
		return;
		system("cls");
		switch(cursor_ptr){
			case 1:
			SetConsoleTextAttribute(handle_var,FOREGROUND_RED);	
			printf("\nAre you sure to permanently delete all data files (Y/N)? ");
			SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
			char choice;
			scanf("%c",&choice);
			if (!(choice=='Y'||choice=='y'))
			break;
			int x=remove(file_names[0]);
			int y=remove(file_names[1]);
			system("cls");
			if (!(x||y)){ //i.e. boolean algebra !(x||y) = !x&&!y 
			SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
			printf("\nNote: Files Deleted Successfully!");
			SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
			}
			else{
			SetConsoleTextAttribute(handle_var,FOREGROUND_RED);	
			printf("\nError: Files could not be Deleted!\a");
			}
			SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
			getch();
			break;
			case 2:
			delete_specific_slot();
			break;
			case 3:
			rename_data_files();
			break;
			case 4:
			SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
			if (!sound_flag)
			printf("\nDo you want to turn ON in-game sounds (Y/N)? ");
			else
			printf("\nDo you want to turn OFF in-game sounds (Y/N)? ");
			SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
			scanf("%c",&choice);
			if(choice=='Y'||choice=='y'){
			if (!sound_flag)
			sound_flag=1;
			else
			sound_flag=0;
			}
			break;
			default:
			printf("\nError!\a");
			break;
		}
	}
}
void password(char *const pass){
    i=0;
    char temp_pass[11];
    do{
        temp_pass[i]=getch();
        if (i>=10){ //i.e. restricts users to type more than 10 characters
        if (temp_pass[i]==backspace){
		printf("\b \b");
		i--;
		}
		continue;
		}
		if(isprint(temp_pass[i])){ //Note: isprint() returns '+ve value' for printable characters & '0' for non-printable
        printf("*");
        i++;
        }
        else if(temp_pass[i]==backspace&&i!=0){ // i.e. allow users to re-write their password
        printf("\b \b");
        i--;
        }
    }while(temp_pass[i]!=enter);
	temp_pass[i]='\0'; //i.e. neglecting the re-written characters after 'NULL'
    strcpy(pass,temp_pass);
    /*Allignment For In-Game String Files*/
    p_info.new_line='\n';
}
void save_game(){
    FILE *in_game_variables_ptr=fopen(file_names[0],"a+"),*in_game_strings_ptr=fopen(file_names[1],"a+");
	int slot_capacity=calc_slot_capacity();
	char pass[11];
	player temp_info;
	if (slot_capacity>=100){ //i.e. restricting size for slots , by default: 100 slots
	SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
	gotoxy(49,12);
	printf("Warning: Memory is Full!\a");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	gotoxy(49,25);
	printf("Press any key to go back...");
	goto escape_to_main_menu;
	}
	while(1){
		while(1){
		rewind(in_game_strings_ptr);
		system("cls");
		SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
		gotoxy(42,22);
		printf("Available Slots for Saving Game: ");
		SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
		printf("%d/100",100-slot_capacity);
		SetConsoleTextAttribute(handle_var,FOREGROUND_RED);	
		gotoxy(42,23);
		printf("Note: Type '0' or 'esc' to go back on Main-Menu");
		gotoxy(0,0);
		printf("Note: Same 'names' will not be accepted!\n");
		SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
		printf("Enter the authentication name for current game (limit: 19 characters): ");
    	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
        scanf("%s",p_info.game_name); // i.e. can't use %[^\n] , gives error in filing
    	if (!strcmp(p_info.game_name,"0")||!strcmp(p_info.game_name,"esc")||!strcmp(p_info.game_name,"ESC"))
    	return;
		if (strlen(p_info.game_name)>19)
    	goto error_in_name;
		for(i=0;i!=slot_capacity;i++){
    	fread(&temp_info,sizeof(player),1,in_game_strings_ptr);
		if (!strcmp(temp_info.game_name,p_info.game_name))
		goto error_in_name;
		}
		break;
error_in_name:
    	printf("\a");
		}
		rewind(in_game_strings_ptr);
    	SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
        printf("\nEnter the password (limit: 10 characters): ");
    	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
        password(pass);
    	SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
        printf("\nRe-enter the Password: ");
    	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
		password(p_info.pass);
        if (!strcmp(pass,p_info.pass)){
        fprintf(in_game_variables_ptr,"%4d %4d %4d %4d %4d %4d %4d %4d \n",p1_cp,p2_cp,p1_tc,p2_tc,turn_flag,temp_game_mode,limit,pg_time);
        fwrite(&p_info,sizeof(player),1,in_game_strings_ptr);
		system("cls");
		SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
        gotoxy(47,12);
		printf("Note: Game Saved Successfully!");
		SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
		gotoxy(49,14);
    	printf("Press any key to go back...");
    	getch();
		break;
        }
        else{
        gotoxy(42,24);
   		SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
		printf("Warning: Password Mismatched!\a");
		SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
		getch();
		system("cls");
		fflush(stdin);
		}
    }
escape_to_main_menu:
    fclose(in_game_variables_ptr);
    fclose(in_game_strings_ptr);
}
int load_game(){
    FILE *in_game_variables_ptr=fopen(file_names[0],"r"),*in_game_strings_ptr=fopen(file_names[1],"r");
   	int X=0,cursor_ptr=1,temp_game_var[8],slot_capacity=calc_slot_capacity(),temp_game_mode_arr[slot_capacity];
	player temp_info;
	char hit=NULL,pass[11],temp_name[20],temp_game_name_arr[slot_capacity][20],game_mode_name_arr[][20]={"Classic","Modern","Time Knockout","Turn Knockout"};
	if (in_game_variables_ptr==NULL||in_game_strings_ptr==NULL){
	SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
	gotoxy(49,12);
	printf("Error: Files not found!\a");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	getch();
	return 0;
	}
    if (!slot_capacity){
	system("cls");	
	SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
	gotoxy(44,12);	
	printf("Warning: No Save game available!\a");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	getch();
	goto escape_to_main_menu; // Note: Sometimes 'goto' can't escape declaration statements
	}
	for(i=0;i!=slot_capacity;i++){
    	fread(&temp_info,sizeof(player),1,in_game_strings_ptr);
		strcpy(temp_game_name_arr[i],temp_info.game_name);
		for(j=0;j<8;j++)
			fscanf(in_game_variables_ptr,"%d",&temp_game_var[j]);
		temp_game_mode_arr[i]=temp_game_var[5];
	}
    while(1){
    	system("cls");
		SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
		printf("LIST OF STORED GAMES\n");
		SetConsoleTextAttribute(handle_var,FOREGROUND_YELLOW);
		printf("^^^^^^^^^^^^^^^^^^^^");
		SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
		for(i=0;i!=slot_capacity;i++)
			printf("\n%2d)    %s (%s)",i+1,temp_game_name_arr[i],game_mode_name_arr[temp_game_mode_arr[i]-1]);
		SetConsoleTextAttribute(handle_var,FOREGROUND_RED);	
		gotoxy(37,23);
		printf("Note: Press 'ESC' to go on Main-Menu");
		gotoxy(37,24);
		printf("Note: Press 'Ctrl+W' to select random Slot");
		SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
		/*Pointing Cursor*/
		do{
			gotoxy(4,cursor_ptr+1);
			cursor_pointer(4,cursor_ptr+1);
			hit=getch();
			if (hit==down||hit==right)
			cursor_ptr++;
			else if(hit==up||hit==left)
			cursor_ptr--;
			else if(hit==escape){
			X=1;
			goto escape_to_main_menu;
			}
			else if(hit==hardescape){
			cursor_ptr=0;
			while(1){
			gotoxy(37,26);	
			fflush(stdin);
			printf("Enter Slot number: ");
			scanf("%d",&cursor_ptr);
			if (cursor_ptr>0&&cursor_ptr<=slot_capacity)
			break;
			gotoxy(37,26);
			printf("                                \a");
			}
			break;
			}
			else if(hit==enter)
			break;
			if (cursor_ptr==slot_capacity+1)
			cursor_ptr=1;
			else if(cursor_ptr==0)
			cursor_ptr=slot_capacity;
		}while(1);
		/*Matching Password*/
		rewind(in_game_variables_ptr); //i.e. to point the file ptr again from beginning
		rewind(in_game_strings_ptr);
   	    gotoxy(38,cursor_ptr+1);
        printf(">> ");
		SetConsoleTextAttribute(handle_var,FOREGROUND_LIGHTBLUE);
		printf("Enter the password for selected game: ");
		SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
        password(pass);
        for(i=0;i!=slot_capacity;i++){
        	for(j=0;j<8;j++)
				fscanf(in_game_variables_ptr,"%d",&temp_game_var[j]);
			fread(&temp_info,sizeof(player),1,in_game_strings_ptr);
            if (!(strcmp(temp_game_name_arr[cursor_ptr-1],temp_info.game_name)||strcmp(pass,temp_info.pass))){ //i.e. boolean algebra: !a&&!b = !(a||b)
        	/*Assigning Previous Data*/
        	p1_cp=temp_game_var[0],p2_cp=temp_game_var[1],p1_tc=temp_game_var[2],p2_tc=temp_game_var[3],turn_flag=temp_game_var[4],temp_game_mode=temp_game_var[5],limit=temp_game_var[6],previous_game_time=temp_game_var[7];
			strcpy(p_info.p1_name,temp_info.p1_name);
			strcpy(p_info.p2_name,temp_info.p2_name);
			strcpy(p_info.game_name,temp_info.game_name);
			strcpy(p_info.pass,temp_info.pass);
			/*Re-Initializing/Reseting Other In-Game Variables*/
			main_menu_flag=0;
			snake_count=0; Z=0;
			temp_dice_mode=1; temp_dice_option=1;
			system("cls");
			SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
			gotoxy(37,12);
            printf("Note: Authentication Name & Password Matched!");
        	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
		    gotoxy(43,14);
			printf("Press any key to load the game...");
			getch();
			goto escape_to_main_menu;
            }
       }
    	SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
       	gotoxy(37,25);
		printf("Warning: Invalid Authentication Name or Password!\a");
    	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
    	getch();
	}
escape_to_main_menu:
    fclose(in_game_variables_ptr);
    fclose(in_game_strings_ptr);
	if (!slot_capacity||X)
	return 0;
	else
	return 1;
}
void guide(){
	int color_flag=1;
    FILE *guide_ptr;
    guide_ptr=fopen("files\\guide.txt","r");
    if (guide_ptr==NULL){
    SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
	gotoxy(49,12);
	printf("Error: File not found!\a");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	return;
	}
    while(!feof(guide_ptr)){
    char read_char=fgetc(guide_ptr); //Note: ptr 'guide_ptr' is called once so that it does not proceed to next character present in 'file'.
	if (read_char=='~')
	color_flag=0;
	else if(read_char=='`')
	color_flag=1;
	if (color_flag){
	if (read_char=='?')
	SetConsoleTextAttribute(handle_var,FOREGROUND_PURPLE);	
	else if(read_char=='*')
	SetConsoleTextAttribute(handle_var,FOREGROUND_YELLOW);
	else
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
	}
	else
	SetConsoleTextAttribute(handle_var,FOREGROUND_GREEN);
	printf("%c",read_char);
	}
	fclose(guide_ptr);
	SetConsoleTextAttribute(handle_var,FOREGROUND_RED);
	gotoxy(0,0);
	printf("Note: Press any key to go back on Main-Menu");
	SetConsoleTextAttribute(handle_var,FOREGROUND_WHITE);
}
