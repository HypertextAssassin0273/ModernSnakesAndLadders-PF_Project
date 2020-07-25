# Basic Features:
- Multiplayer game to involve two players playing simultaneously.
- Interactive Main-menu giving various options.
- User-friendly Welcome screen.
- Dice can be used manually (keeping the essence of traditional board game).
- Load Game function to load previous unfinished game.
- Save Game function to continue the same game at another time.
- Tutorial for beginners to understand the flow and control of game. 
- Authorized Access (password) for load game to provide privacy.
- Basic GUI implementation.
- Sound effects.
- Short-keys to provide fast reaction time for specific commands.
#
# What’s New? (Improvements)
- Three new & different Game Modes.\
    (i.e. Total: classic, modern, time knockdown, turn knockdown)
- Separate Dice-Menu with four different settings.\
    (i.e. auto/manual, single/double dice)
- Win-Menu will now show turns & positions of both players , along with total time taken in each match.
- To reduce the code size & improve efficiency for locating ‘Cursor-Pointer’ on board, a complex equation is used.
- Hidden Settings for Filing & some In-game functions.\
    (i.e. Delete Specific Slot, Erase All Data, Rename Files, ON/OFF Sounds)
- Flexible Menu for load game function, displaying all saved games along with their respective game modes. Also, you can select any saved Game in the Menu (without scrolling up/down) by simply typing the index number in a dialogue box.\
    (i.e. To enable the dialogue box, press Ctrl+w)
- Save Game Menu can now show the Available Slots.
- Calculated Time will now be displayed in Standard Format.
#
# Fixed In-Game Issues:
- [x] Restricted dice settings to encourage fair game-play with warning message & beep
- [x] Restricted users from resuming/saving finished game 
- [x] Restricted users from resuming/saving at start-up of application
- [x] Same user names, game names & previous saved game names will not be accepted
- [x] Functions are cleared from stack after their complete execution
- [x] Invalid inputs will no longer be accepted
- [x] Load Game Menu will not open if its respective data files are not present
- [x] Save Game Menu will not open if Available Slots are full
#
# Flow/Control of Game:
![flow_chart](https://user-images.githubusercontent.com/66676402/88355997-dbc6c900-cd7f-11ea-89f4-51bfe29051db.png)
#
# HIPO-Chart:
![HIPO_chart](https://user-images.githubusercontent.com/66676402/88356008-e08b7d00-cd7f-11ea-9814-4d16efeb91f7.png)
