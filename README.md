# ZORK
### C++ Test - Simple Zork Game Assignment
UPC Advanced Programming for AAA Video Games admission test


### ABOUT ZORK:
Zork is one of the earliest interactive fiction computer games, with roots drawn from the original genre game Colossal Cave Adventure. The first version of Zork was written between 1977 and 1979 using the MDL programming language on a DEC PDP-10 computer. The authors (Tim Anderson, Marc Blank, Bruce Daniels, and Dave Lebling) were members of the MIT Dynamic Modelling Group.
When Zork was published commercially, it was split up into three games: Zork: The Great Underground Empire – Part I (later known as Zork I), Zork II: The Wizard of Frobozz, and Zork III: The Dungeon Master.
Zork distinguished itself in its genre as an especially rich game, in terms of both the quality of the storytelling and the sophistication of its text parser, which was not limited to simple verb-noun commands ("hit troll"), but recognized some prepositions and conjunctions ("hit the troll with the Elvish sword")


### ABOUT THIS PROJECT:
An [example code](https://github.com/d0n3val/zork) was provided for this Assignment.

This version uses the same Class structure as the example given, and many functionalities were taken from it.
As this project was inspired from reading, testing and understanding the code code given, most of the structures for each class are very similar, and even some functions were even taken "as is", like the ones included in Global.cpp, or the parser in World.cpp, as they were fitting the requirements for this particular project.

New features that are not implemented in the example code are:
- Movement of a creature between rooms.
- New equipment type (shields)
- New item type (potions)
- The ability to drink potions to recover HP
- New combat system
- Items contained inside other items must fit. One sould not be able to store a big sword in a tiny box. (3 sizes are considered: Small, Medium, Large)
- The containing capability of an Item. 2 Small items will fit in a medium-sized container, but the 3rd won't fit

As the time was limited while developing this project (1 week) some features were not implemented, but the story is prepared for them:
###### Lock and Unlock Doors
- The Key inside the Mailbox, in the House, was to be used to open the Basement Exit.
-  Once the player reached the Maze entrance, the door collapses and that exit had to become locked. Trapping the player inside the maze.
-  The Amulet was the Key to open the Circular Room portal
###### Unidirectional exits
- Once the player is teleported from the Circular room, if the game would not end at that point the player could go back from the Rooftop to that room. Magic teleportation does not work this way...
###### Game descriptions
- Rooms inside the maze lack a bit of... description careness.



### AVAILABLE COMMANDS:
(please note that the parser is not case sensitive: "LOOK" "look" "LoOk" ... will perform in the same way.)

- "LOOK"
   - Prints the information of what is surrounding the player.
- "LOOK ME"
   - Prints the description of the player.
- "LOOK xxx"
   - Prints the description of something in the room, be an Item or another Creature.
- "GO NORTH" / "NORTH" / "N"
   - Travel to the exit of the room, direction north. The same command applies for the 6 cardinal directions ("south"/"s", "east"/"e", "west"/"w", "up" and "down").
- "INVENTORY" / "I"
   - Prints the item name of all the objets the player is carrying.
- "TAKE xxx" / "PICK xxx"
   - Takes an item from the room and places it inside the inventory of the player.
- "TAKE xxx from yyy"
   - Takes an item from inside another item. "PICK..." also works here. (Note that the word "from" could be replaced by any other word. The parser discards this token.)
- "PUT xxx from yyy"
   - The contrary of the above. "PLACE..." will also work.
- "LOOT xxx from yyy"
   - Takes an item from a creature corpse, and places it in the player's inventory.
- "DROP xxx"
   - Drops to the room an item that the player is carrying in his inventory.
- "EQUIP xxx" / "EQ xxx"
   - The player must equip shields and weapons in order to perform when in combat.
- "UNEQUIP xxx" / "UNEQ xxx"
   - Unequip an item the player is wearing.
- "ATTACK xxx" / "ATK xxx"
   - The player attacks a creature in the room, starting the combat mode.
- "STATS" / "ST"
   - Prints the stats on the player (HP, Mana, Max Damage and Max Defense).
- "STATS xxx" / "ST xxx"
   - Prints the stats of a creature in the room.
- "STATS of xxx"
   - Same as above. (Note that the word "of" could be replaced by any other word. The parser discards this token.)
- "DRINK xxx"
   - Drinks a potion item from the player's inventory. The potion will have its effects.
   
_xxx and yyy should be replaced by the name of the Item or Creature the player is referring to_


### MAP:
```
            _______________
            \              |
             \             |
              \            |
            \------\   _---""---_   \----\   \----\
             \*Roof*\ \ Circular \---\ M4 \---\ M3 \
              \------\ "---___---"    \----\   \----\
                                         \        \
\--------\   \-------\                 \----\   \----\
 \*Forest*\---\ House \                 \ M1 \---\ M2 \
  \--------\   \-------\                 \----\   \----\
                     |                      \
                   \----------\       \-----------\
                    \ Basement \-------\ Maze Ent. \----\
                     \----------\       \-----------\    \
                                              \           \
                                               \     \---------\
                                                \-----\ Bone R. \
                                                       \---------\
```

### WALKTHROUGH:
Player starts at Forest.
- Forest: Take and Equip the sword
- House: Attack the butler, Loot his shield and Equip it
- Basement: --
- Maze Entrance: --
- Bone Room: Loot the potion from the soldier corpse and Drink it
- M1-4: A Troll will be in one of these rooms; travel around them or use "Look" to make the Troll move.
        Once you find the Troll, Attack it and Loot his Amulet
- Circular Room: --
- Roof: If you get here with the Amulet in your inventory, you completed the Demo.



### LICENSE:

MIT License

Copyright (c) 2020 Francesc Porta Solsona

Permission is hereby granted, free of charge, to any person obtaining a copy 
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

