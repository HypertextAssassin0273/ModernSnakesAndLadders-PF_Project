Following are the (improved) functions included in this project:
1. [_**main_constructor()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#main_constructor)
2. [_**main()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#main)
3. [_**gotoxy(int x,int y)**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#gotoxyint-xint-y)
4. [_**welcome_screen()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#welcome_screen)
5. [_**cursor_pointer(int x,int y)**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#cursor_pointerint-xint-y)
6. [_**display_boxes()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#display_boxes)
7. [_**show_main_menu()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#show_main_menu)
8. [_**show_dice_menu()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#show_dice_menu)
9. [_**dice_settings()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#dice_settings)
10. [_**random_dice()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#random_dice)
11. [_**manual_dice()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#manual_dice)
12. [_**display_board(int board[][10])**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#display_boardint-board10)
13. [_**show_stats(int turn_flag,int temp_cp,int temp_tc)**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#show_statsint-turn_flagint-temp_cpint-temp_tc)
14. [_**locate_pointer_on_board(int temp_cp)**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#locate_pointer_on_boardint-temp_cp)
15. [_**estimated_func_time(int *const extra_time,int (*func)())**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#estimated_func_timeint-const-extra_timeint-func)
16. [_**show_winning_menu()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#show_winning_menu)
17. [_**display_standard_time(int N)**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#display_standard_timeint-n)
18. [_**main_game()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#main_game)
19. [_**locate_menu_pointer()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#locate_menu_pointer)
20. [_**new_game()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#new_game)
21. [_**calc_slot_capacity()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#calc_slot_capacity)
22. [_**rename_data_files()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#rename_data_files)
23. [_**delete_specific_slot()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#delete_specific_slot)
24. [_**hidden_settings()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#hidden_settings)
25. [_**password(char *const temp_password)**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#passwordchar-const-temp_password)
26. [_**save_game()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#save_game)
27. [_**load_game()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#load_game)
28. [_**guide()**_](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki/WORKLOAD-DISTRIBUTION-(FUNCTIONS)#guide)

---

### main_constructor():
Its main purpose is to make sure that the included functionalities aren't re-used whenever main function is called. Also, it initializes the file names which are used to save In-game variables & strings. Hence, keeping your file names updated even if you have to rename the files in application.
#
### main():
This function contains the control of the whole game. User can switch to resume, new game, load game, save game, tutorial and exit from this function by simply scrolling up/down in the menu. It calls the respective functions as user’s input. In this function user can also use pre-defined short cut keys too.
#
### gotoxy(int x,int y):
It take coordinates (x,y) as parameters and point the cursor pointer on designated coordiantes on screen.
#
### welcome_screen():
It shows a welcome screen, using loops & strings.
#
### cursor_pointer(int x,int y):
It points the user-made rotating cursor on designated position on screen w.r.t coordinates (x,y) which are taken as parameters.
#
### display_boxes():
It prints boxes using loops for main-menu.
#
### show_main_menu():
It displays all printf commands in main-menu.
#
### show_dice_menu():
It displays all printf commands in dice-menu.
#
### dice_settings():
It basically allows user to modify dice settings (i.e. auto/manual, single/double dice options are available).
#
### random_dice():
It generates random value on dice as per single/double dice settings.
#
### manual_dice():
It generates user’s desired value on dice as per single/double dice settings.
#
### display_board(int board[][10]):
It displays the game board for snakes & ladders, using iterative conditions.
#
### show_stats(int turn_flag,int temp_cp,int temp_tc):
It displays current stats of a player during the match.
#
### locate_pointer_on_board(int temp_cp):
It points the cursor pointer on designated position on game board, mainly using gotoxy function. To achieve size reduction in code, a complex mathematical equation is used to track the position of pointer.
#
### estimated_func_time(int *const extra_time,int (*func)()):
It calculates the time taken by a function that is passed as parameter using function pointer and saves calculated time by assigning value on the address of the variable, which is taken as a parameter.
#
### show_winning_menu():
It displays some printf commands in win-menu.
#
### display_standard_time(int N):
It takes time in seconds as parameter and then converts it to standard time format (i.e 1 hour 20 mins 4 secs). Also, it makes sure to display in correct format sequence, means if any variable (i.e. hour/mins/sec) is 0, then it display the time without that variable.
#
### main_game():
It is the function in which all In-game procedures are carried out. Like, when the game starts, the flow of program is transferred to this function. It basically controls all In-game elements (i.e. snakes, ladders, player turns & positions, cursor pointer on game board, game modes, dice settings, limits, win menu, etc). Also, it is responsible for In-game time taken calculations.
#
### locate_menu_pointer():
It basically holds the working of Cursor pointer in New Game & Hidden File Settings Menu.
#
### new_game():
It prompts users for user names, game modes (in the form of Menu) & specific game mode limit. Also it re-initializes/resets all In-game variables.
#
### calc_slot_capacity():
It basically calculates the number of rows (i.e. slots) present in In-game variables & In-game strings files.
#
### rename_data_files():
It renames In-game variables & In-game strings files.
#
### delete_specific_slot():
Its main function is to delete the specific row (i.e. slot) in both files (using temporary file method).
#
### hidden_settings():
It shows hidden settings in main-menu when ‘tab’ is pressed. Moreover, it contains a unique menu for the settings (i.e. erase data files, rename files, delete specific slot, sounds (ON/OFF)).
#
### password(char *const temp_password):
It takes password character by character from user while hiding from others and then saves in array. After that, it copies to another array that is received as parameter through a pointer.
#
### save_game():
It saves the current game (only) while asking for password (twice for verification) & authentication game name from user. It also makes sure that the game name is not as same as the previous saved games.
#
### load_game():
It basically loads the previous game (saved by user) even when the application is refreshed, using filing-process. Moreover, it has a flexible menu for all previous saved games. Also, it makes sure that password and game-name do match, otherwise an error will be generated.
#
### guide():
It reads the Guide Text from a previously saved data file in colorful display.

---

**_GOTO:_** [**_HOME_**](https://github.com/HypertextAssassin0273/ModernSnakesAndLadders-PF_PROJECT/wiki)
#
