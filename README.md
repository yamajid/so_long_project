Features :

  2D game with customizable characters and settings.
  Smooth graphic management using MiniLibX.
  Map construction with walls, collectibles, and free space.
  Validity checks for maps and player movements.
  Use of arrow keys or WASD for character movement.
  Display of the current number of movements.
  
Prerequisites :

  C Compiler (gcc/clang) /
  Make /
  MiniLibX library
  
Graphic Management :

  The program displays the game image in a window, ensuring smooth window management, 
  including minimizing and closing. Pressing ESC or clicking the window's cross closes 
  the window and quits the program cleanly.
  
Map :

  The map consists of walls (1), collectibles (C), an exit (E), and free space (0). 
  The map must be rectangular, closed/surrounded by walls, and contain at least one exit,
  collectible, and starting position (P).
  For detailed map rules and examples, please refer to the Map section.
