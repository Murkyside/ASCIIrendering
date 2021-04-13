#include <iostream>
#include <string>
#include <ncurses.h>
extern "C" {
    #define STB_IMAGE_IMPLEMENTATION
    #include "stb_image.h"
}
int roundUp(int numToRound, int multiple)
{
    if (multiple == 0)
        return numToRound;

    int remainder = numToRound % multiple;
    if (remainder == 0)
        return numToRound;

    return numToRound + multiple - remainder;
}

int main()
{
    int columns = 180;
    int rows = 50;
    int posx = 0;
    int posy = 0;
    int addition;
    initscr();
    start_color();
    init_pair(1,COLOR_RED,COLOR_BLACK);
    std::string filename = "Myimage.png";
    curs_set(0);
    noecho();
    cbreak();


    int x,y,n;
    unsigned char *data = stbi_load(filename.c_str(), &x, &y, &n, 0);
    //std::cout << x;
    if (data != nullptr && x > 0 && y > 0)
    {
        if (n == 3)
        {

            std::cout << "First pixel: RGB "
                      << static_cast<int>(data[0]) << " "
                      << static_cast<int>(data[1]) << " "
                      << static_cast<int>(data[2]);
        }
        else if (n == 4)
        {

          for(int xPosition = 0; xPosition<columns;xPosition++){
            for(int yPosition = 0; yPosition<rows;yPosition++){
              move(yPosition,xPosition);
              addition = static_cast<int>(data[roundUp(x*4/columns*xPosition,4)+roundUp((x*4)*y/rows*yPosition,x*4)])+static_cast<int>(data[roundUp(x*4/columns*xPosition,4)+roundUp((x*4)*y/rows*yPosition,x*4)+1])+static_cast<int>(data[roundUp(x*4/columns*xPosition,4)+roundUp((x*4)*y/rows*yPosition,x*4)+2]);
              
              if(addition<85){
                printw(" ");
              }else if(addition<85*2){
                printw(".");
              }else if(addition<85*3){
                printw(":");
              }else if(addition<85*4){
                printw("-");
              }else if(addition<85*5){
                printw("=");
              }else if(addition<85*6){
                printw("+");
              }else if(addition<85*7){
                printw("*");
              }else if(addition<85*8){
                printw("#");
              }else if(addition<85*10){
                printw("@");
              }

              //static_cast<int>(data[roundUp(x*4/180*xPosition,4)+roundUp((x*4)*y/50*yPosition,x*4)])+static_cast<int>(data[roundUp(x*4/180*xPosition,4)+roundUp((x*4)*y/50*yPosition,x*4)+1])+static_cast<int>(data[roundUp(x*4/180*xPosition,4)+roundUp((x*4)*y/50*yPosition,x*4)+2]);


              }
            //take every (x/180) rounded to the nearest 4
            //static_cast<int>(data[roundUp(x*4/180*xPosition,4)])
              //data[roundUp(x/180*xPosition,4)+roundUp(x*yPosition/50,x)]; //reds
              //data[roundUp(x/180*xPosition,4)+1+roundUp(x*yPosition/50,x)] //greens
              //data[roundUp(x/180*xPosition,4)+roundUp(x*yPosition/50,x)]+data[roundUp(x/180*xPosition,4)+1+roundUp(x*yPosition/50,x)]+data[roundUp(x/180*xPosition,4)+2+roundUp(x*yPosition/50,x)]






            }
            refresh();
          // std::cout << "First pixel: RGBA "
            //          << static_cast<int>(data[0]) << " "
            //          << static_cast<int>(data[1]) << " "
            //          << static_cast<int>(data[2]) << " "
            //          << static_cast<int>(data[3]) << '\n';

        }
    }
    else
    {
        std::cout << "Some error\n";
    }
    stbi_image_free(data);




    getch();
    endwin();




    return(0);
}
