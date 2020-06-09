##WORKLOAD DISTRIBUTION (FUNCTIONAL WORKING)
Main_constructor():
Its main purpose is to make sure that the included functionalities aren't re-used whenever main function is called. Also, it initializes the file names which are used to save In-game variables & strings. Hence, keeping your file names updated even if you have to rename the files in application.
gotoxy(int x,int y):
It take coordinates (x,y) as parameters and point the cursor pointer on designated coordiantes on screen.
welcome_screen():
It shows a welcome screen, using loops & strings.
cursor_pointer(int x,int y):
It points the user-made rotating cursor on designated position on screen w.r.t coordinates (x,y) which are taken as parameters.
display_boxes():
It prints boxes using loops for main-menu.
show_main_menu():
It displays all printf commands in main-menu.

show_dice_menu():
It displays all printf commands in dice-menu.
dice_settings():
It basically allows user to modify dice settings (i.e. auto/manual, single/double dice options are available).
random_dice():
It generates random value on dice as per single/double dice settings.
manual_dice():
It generates user’s desired value on dice as per single/double dice settings.
display_board(int board[][10]):
It displays the game board for snakes & ladders, using iterative conditions.
show_stats(int turn_flag,int temp_cp,int temp_tc):
It displays current stats of a player during the match.
locate_pointer_on_board(int temp_cp):
It points the cursor pointer on designated position on game board, mainly using gotoxy function. To achieve size reduction in code, a complex mathematical equation is used to track the position of pointer.


estimated_func_time(int *const extra_time,int (*func)()):
It calculates the time taken by a function that is passed as parameter using function pointer and saves calculated time by assigning value on the address of the variable, which is taken as a parameter.
show_winning_menu():
It displays some printf commands in win-menu.
display_standard_time(int N):
It takes time in seconds as parameter and then converts it to standard time format (i.e 1 hour 20 mins 4 secs). Also, it makes sure to display in correct format sequence, means if any variable (i.e. hour/mins/sec) is 0, then it display the time without that variable.
main_game():
It is the Main function in which all In-game procedures are carried out. Like, when the game starts, the flow of program is transferred to this function. It basically controls all In-game elements (i.e. snakes, ladders, player turns & positions, cursor pointer on game board, game modes, dice settings, limits, win menu, etc). Also, it is responsible for In-game time taken calculations.
locate_menu_pointer():
It basically holds the working of Cursor pointer in New Game & Hidden File Settings Menu.


new_game():
It prompts users for user names, game modes (in the form of Menu) & specific game mode limit. Also it re-initializes/resets all In-game variables.
calc_slot_capacity():
It basically calculates the number of rows (i.e. slots) present in In-game variables & In-game strings files.
rename_data_files():
It renames In-game variables & In-game strings files.
delete_specific_slot():
Its main function is to delete the specific row (i.e. slot) in both files (using temporary file method).
hidden_settings():
It shows hidden settings in main-menu when ‘tab’ is pressed. Moreover, it contains a unique menu for the settings (i.e. erase data files, rename files, delete specific slot, sounds (ON/OFF)).
password(char *const temp_password):
It takes password character by character from user while hiding from others and then saves in array. After that, it copies to another array that is received as parameter through a pointer. 


save_game():
It saves the current game (only) while asking for password (twice for verification) and authentication game name from user. It also makes sure that the game name is not as same as the previous saved games.
load_game():
It loads the previous game saved by the users even when the application is refreshed, using filing-process. Moreover, it has a menu for the previous load games. Also, it makes sure that password and game-name do match, otherwise an error will be generated.
guide():
It reads the Guide Tex from a saved file in colorful display.
