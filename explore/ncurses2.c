/* arrow.c */ 

#include <ncurses.h>

int main()
{
    int key, x, y;
    
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    x = y = 5;

    while(key!= 'q'){
      clear();
      move(0, 0);
      printw("Press left or right arrow - exit by pressing q");

      move(y, x);
      printw("O");

      refresh();
      key = getch();
      if (key == KEY_LEFT)
      {
        x--;
        if (x < 0) x = 0;
      }

      else if (key == KEY_RIGHT)
      {
        x++;
        if (x>50) x =50;
      }
      else if(key == KEY_UP)
      {
        y--;
        if (y < 0) y = 0;
      }
      else if(key == KEY_DOWN)
      {
        y++;
        if (y>25) y = 25;
      }
  }

    endwin();
    return 0;
}
