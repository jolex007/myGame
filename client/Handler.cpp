#include "Handler.h"
#include <iostream>


#ifndef __linux__
#include <termios.h>
#include <stdio.h>

static struct termios old, current;

void initTermios(int echo) 
{
  tcgetattr(0, &old);
  current = old;
  current.c_lflag &= ~ICANON;
  if (echo) {
      current.c_lflag |= ECHO;
  } else {
      current.c_lflag &= ~ECHO;
  }
  tcsetattr(0, TCSANOW, &current);
}

void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

char getch(void) 
{
  return getch_(0);
}

#else
#include <conio.h>
#endif


void Handler::handle()
{
    char value;

    while (true) {
        value = getch();
        Request request;

        bool flag = false;

        switch (int(value))
        {
        case 105:
            request.key = Key::UpArrow;
            break;

        case 107:
            request.key = Key::DownArrow;
            break;

        case 108:
            request.key = Key::RightArrow;
            break;

        case 106:
            request.key = Key::LeftArrow;
            break;

        case 119:
            request.key = Key::WKey;
            break;

        case 97:
            request.key = Key::AKey;
            break;

        case 115:
            request.key = Key::SKey;
            break;

        case 100:
            request.key = Key::DKey;
            break;

        case 32:
            request.key = Key::SpaceKey; 
            break;
        
        case 10:
            request.key = Key::EnterKey;
            break;
        
        case 27:
            request.key = Key::EscKey;
            break;

        default:
            flag = true;
            break;
        }
        
        if (flag) {
            continue;
        }

        EventQueue::Push(request);
    }
}