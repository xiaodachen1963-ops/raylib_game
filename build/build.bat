cd D:\abc\c\raylib
gcc -std=c11 -O2 main.c enemy.c coin.c blue_ball.c ui.c player.c green_ball.c -IC:\raylib\include -ID:\abc\c\raylib\include -LC:\raylib\lib -lraylib -lopengl32 -lgdi32 -lwinmm -o main.exe
