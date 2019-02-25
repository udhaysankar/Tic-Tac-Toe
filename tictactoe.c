#include <stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
/*the print function will be called after every input by the user*/
void print(char (*GRID)[7])
{
  /*length and breadth of the grid of a tic-tac-toe game is 3*3*/
  int length=7, breadth=7,i,j;
      printf("\nTic-Tac-Toe by Udhay Sankar\n\n");
  for(i=0;i<length;i++)
  {
    printf("       ");
   for(j=0;j<breadth;j++)
   {
    printf("%c",GRID[i][j]);
   }
  printf("\n");
  }
}
/*function to check the validity of user input*/
int valid(char (*GRID)[7],int TEMP1)
{
  if(((TEMP1)>0)&&((TEMP1)<10))
  {
      switch (TEMP1)
      {
        case 1:
        if (GRID[1][1]=='x'||GRID[1][1]=='o')
        {
        printf("\nPosition already occupied!!!\n");
        return 0;
        }
        else
        return 1;
        break;
        case 2:
        if (GRID[1][3]=='x'||GRID[1][3]=='o')
        {
        printf("\nPosition already occupied!!!\n");
        return 0;
        }
        else
        return 1;
        break;
        case 3:
        if (GRID[1][5]=='x'||GRID[1][5]=='o')
        {
        printf("\nPosition already occupied!!!\n");
        return 0;
        }
        else
        return 1;
        break;
        case 4:
        if (GRID[3][1]=='x'||GRID[3][1]=='o')
        {
        printf("\nPosition already occupied!!!\n");
        return 0;
        }
        else
        return 1;
        break;
        case 5:
        if (GRID[3][3]=='x'||GRID[3][3]=='o')
        {
        printf("\nPosition already occupied!!!\n");
        return 0;
        }
        else
        return 1;
        break;
        case 6:
        if (GRID[3][5]=='x'||GRID[3][5]=='o')
        {
        printf("\nPosition already occupied!!!\n");
        return 0;
        }
        else
        return 1;
        break;
        case 7:
        if (GRID[5][1]=='x'||GRID[5][1]=='o')
        {
        printf("\nPosition already occupied!!!\n");
        return 0;
        }
        else
        return 1;
        break;
        case 8:
        if (GRID[5][3]=='x'||GRID[5][3]=='o')
        {
        printf("\nPosition already occupied!!!\n");
        return 0;
        }
        else
        return 1;
        break;
        case 9:
        if (GRID[5][5]=='x'||GRID[5][5]=='o')
        {
        printf("\nPosition already occupied!!!\n");
        return 0;
        }
        else
        return 1;
        break;
      }
  }
  else
  {
    return 0;
  }
}
/*function to get input from user*/
void get_input(char (*GRID)[7])
{
  int TEMP2;
  printf("\nConsider the 3*3 grid with 9 positions\n\nIf position is row 2 column 3, Enter 6 as input\n\nEnter your position for 'x': ");
  scanf("%d",&TEMP2);
  while((valid(GRID,TEMP2))!=1)
  {
    //if position is already occupied
    printf("\nInvalid Input! Enter a valid position\n");
    printf("\nConsider the 3*3 grid with 9 positions\n\nIf position is row 2 column 3, Enter 6 as input\n\nEnter your position for 'x': ");
    scanf("%d",&TEMP2);
  }
  switch (TEMP2)
  {
    case 1:GRID[1][1]='x';
    break;
    case 2:GRID[1][3]='x';
    break;
    case 3:GRID[1][5]='x';
    break;
    case 4:GRID[3][1]='x';
    break;
    case 5:GRID[3][3]='x';
    break;
    case 6:GRID[3][5]='x';
    break;
    case 7:GRID[5][1]='x';
    break;
    case 8:GRID[5][3]='x';
    break;
    case 9:GRID[5][5]='x';
    break;
  }
}
//function to find the number of available available_spots
int available_spots(char (*GRID)[7])
{
  int spots=0;
  for(int i=1;i<6;i=i+2)
  for(int j=1;j<6;j=j+2)
  {
    if (GRID[i][j]==' ')
    spots++;
  }
  return spots;
}
//function to check for win condition after every move from user and computer
int terminal_state(char (*GRID)[7])
{
 if (((GRID[1][1]=='o')&&(GRID[1][3]=='o'))&&((GRID[1][3]=='o')&&(GRID[1][5]=='o')))
 {
   return -10;
 }
 else  if (((GRID[3][1]=='o')&&(GRID[3][3]=='o'))&&((GRID[3][3]=='o')&&(GRID[3][5]=='o')))
 {
   return -10;
 }
 else  if (((GRID[5][1]=='o')&&(GRID[5][3]=='o'))&&((GRID[5][3]=='o')&&(GRID[5][5]=='o')))
 {
   return -10;
 }
 else  if (((GRID[1][1]=='o')&&(GRID[3][1]=='o'))&&((GRID[3][1]=='o')&&(GRID[5][1]=='o')))
 {
   return -10;
 }
 else  if (((GRID[1][3]=='o')&&(GRID[3][3]=='o'))&&((GRID[3][3]=='o')&&(GRID[5][3]=='o')))
 {
   return -10;
 }
 else  if (((GRID[1][5]=='o')&&(GRID[3][5]=='o'))&&((GRID[3][5]=='o')&&(GRID[5][5]=='o')))
 {
   return -10;
 }
 else  if (((GRID[1][1]=='o')&&(GRID[3][3]=='o'))&&((GRID[3][3]=='o')&&(GRID[5][5]=='o')))
 {
   return -10;
 }
 else  if (((GRID[1][5]=='o')&&(GRID[3][3]=='o'))&&((GRID[3][3]=='o')&&(GRID[5][1]=='o')))
 {
   return -10;
 }
 if (((GRID[1][1]=='x')&&(GRID[1][3]=='x'))&&((GRID[1][3]=='x')&&(GRID[1][5]=='x')))
 {
   return 10;
 }
 else  if (((GRID[3][1]=='x')&&(GRID[3][3]=='x'))&&((GRID[3][3]=='x')&&(GRID[3][5]=='x')))
 {
   return 10;
 }
 else  if (((GRID[5][1]=='x')&&(GRID[5][3]=='x'))&&((GRID[5][3]=='x')&&(GRID[5][5]=='x')))
 {
   return 10;
 }
 else  if (((GRID[1][1]=='x')&&(GRID[3][1]=='x'))&&((GRID[3][1]=='x')&&(GRID[5][1]=='x')))
 {
   return 10;
 }
 else  if (((GRID[1][3]=='x')&&(GRID[3][3]=='x'))&&((GRID[3][3]=='x')&&(GRID[5][3]=='x')))
 {
   return 10;
 }
 else  if (((GRID[1][5]=='x')&&(GRID[3][5]=='x'))&&((GRID[3][5]=='x')&&(GRID[5][5]=='x')))
 {
   return 10;
 }
 else  if (((GRID[1][1]=='x')&&(GRID[3][3]=='x'))&&((GRID[3][3]=='x')&&(GRID[5][5]=='x')))
 {
   return 10;
 }
 else  if (((GRID[1][5]=='x')&&(GRID[3][3]=='x'))&&((GRID[3][3]=='x')&&(GRID[5][1]=='x')))
 {
   return 10;
 }
 else if(available_spots(GRID)==0)
 return 0;
}
/*function of minimax algorithm that is recursive*/
int minimax(char (*GRID)[7],int turn)
{
  //
  int best;
  if(terminal_state(GRID)==10)
  return 10;
  if(terminal_state(GRID)==-10)
  return -10;
  if(terminal_state(GRID)==0)
  return 0;
  //
  if(0==turn)
  {
    int i,j;
    int temp;
    best=1000;
    for(int i=1;i<6;i=i+2)
    {
      for(int j=1;j<6;j=j+2)
      {
        if(GRID[i][j]==' ')
        {
          GRID[i][j]='o';
          temp=minimax(GRID,1);
          best=MIN(temp,best);
          GRID[i][j]=' ';
        }
      }
    }
    return best;
   }
  else if(1==turn)
  {
    int i,j;
    int temp;
    best=-1000;
      for(i=1;i<6;i=i+2)
      {
        for(j=1;j<6;j=j+2)
        {
          if(GRID[i][j]==' ')
          {
            GRID[i][j]='x';
            temp=minimax(GRID,0);
            best=MAX(temp,best);
            GRID[i][j]=' ';
          }
        }
      }
  return best;
  }
}
//the following function returns the best move
void computer_position(char (*GRID)[7],int turn)
{
  int computer_move[3];
  int sample=1000;
  computer_move[0]=sample;
  for(int i=1;i<6;i=i+2)
  {
    for(int j=1;j<6;j=j+2)
    {
      if((GRID[i][j]==' ')&&(turn==0))
      {
        GRID[i][j]='o';
        sample=minimax(GRID,!turn);
        if(sample<computer_move[0])
        {
          computer_move[0]=sample;
          computer_move[1]=i;
          computer_move[2]=j;
        }
        GRID[i][j]=' ';
      }
    }
  }
  GRID[computer_move[1]][computer_move[2]]='o';
}
/*main function*/
int main()
{
 //int USR_INPUT,RESULT;
 char GRID[7][7]={
      {'-','-','-','-','-','-','-'},
      {'|',' ','|',' ','|',' ','|'},
      {'-','-','-','-','-','-','-'},
      {'|',' ','|',' ','|',' ','|'},
      {'-','-','-','-','-','-','-'},
      {'|',' ','|',' ','|',' ','|'},
      {'-','-','-','-','-','-','-'}
 };
 int turn=0;
 //when no spots are available or a win condition is obtained
 while(available_spots(GRID)!=0)
 {
   if(terminal_state(GRID)==10)
   {
     print(GRID);
     printf("\nYou have won\n\n");
     return 0;
   }else if (terminal_state(GRID)==-10) {
     print(GRID);
     printf("\nComputer has won\n\n");
     return 0;
   }
 print(GRID);
 get_input(GRID);
 computer_position(GRID,turn);
 }
 //if the game has progressed so far it is a draw
 print(GRID);
 printf("\nThe game is a draw\n\n");
 return 0;
}
