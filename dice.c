#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void dices (int *);
void fcn (int, int, char *, int *);


int
main ()
{
  srand (time (NULL));
  char status;
  char ch='Y';
  int start, bet, bet_type, specific_num;
  int sum_of_dices = 0;

  printf ("Enter a start account for the game $:");
  scanf ("%d", &start);


  do
    {

      printf ("Enter your bet amount:");
      scanf ("%d", &bet);
      if (bet > start)
	{			//cheak bet amout is bigger than total amount
	  while (bet > start)
	    {
	      printf ("You have less money.\n");
	      printf ("Enter your bet amount:");
	      scanf ("%d", &bet);
	    }
	}



      start = start - bet;	//for minus bet amout from total amount


      printf
	("Enter '1' to bet on numbers between 2-6, '2' to bet on numbers 7-12, or '3' to bet on specific number:");
      scanf ("%d", &bet_type);

      if (bet_type != 1 && bet_type != 2 && bet_type != 3)
	{			//cheak bet_type input error
	  while (bet_type != 1 && bet_type != 2 && bet_type != 3)
	    {
	      printf ("Wrong input. Please try again.\n");
	      printf
		("Enter '1' to bet on numbers between 2-6, '2' to bet on numbers 7-12, or '3' to bet on specific number:");
	      scanf ("%d", &bet_type);
	    }
	}



      if (bet_type == 3)
	{
	  printf ("Enter your specific number:");
	  scanf ("%d", &specific_num);
	}
      else
	{
	  specific_num = 0;
	}


      fcn (bet_type, specific_num, &status, &sum_of_dices);	//call fcn function
     
     
     
     
      if (status == 'W' && bet_type == 1)
	{
	  bet = bet + bet;
	}

      else if (status == 'W' && bet_type == 2)
	{

	  bet = bet + bet;
	}
      else if (status == 'W' && bet_type == 3)
	{
	  bet = bet + (15 * bet);
	}
	  else if (status == 'L' && bet_type == 1)
	{
	  bet = 0;
	}

      else if (status == 'L' && bet_type == 2)
	{

	  bet = 0;
	}
      else if (status == 'L' && bet_type == 3)
	{
	  bet = bet - (15 * bet);
	}
     

      start = start + bet;
      
      printf ("Your total currency is %d.\n",start);
      
      if(start<=0){
          printf("You've lost all your money.\nThank you for playing. See you next time!\n");
      }
      else{

      printf("Do you want to continue:Y or N:");
      scanf(" %c", &ch);
          if(ch=='N'||ch=='n'){
              printf("Thank you for playing. See you next time!");
              
          }
      }

     

    }
  while ( (ch =='Y'|| ch=='y') && start > 0 );


  return 0;
}



void
dices (int *number)
{

  *number = rand () % 13;
  return;
}


void
fcn (int bet_type, int specific_num, char *status, int *sum_of_dices)
{
  int number;
  int a;

  dices (&number);
  *sum_of_dices = number;
  printf ("Dices are throw. Summation is %d.\n", *sum_of_dices);

  switch (bet_type)
    {
    case 1:
      if (*sum_of_dices >= 2 && *sum_of_dices <= 6)
	{
	  printf ("You win this round!\n");
	  *status = 'W';
	}
      else
	{
	  printf ("You lose this round!\n");
	  *status = 'L';

	}
      break;

    case 2:
      if (*sum_of_dices > 6 && *sum_of_dices < 13)
	{
	  printf ("You win this round.\n");
	  *status = 'W';
	}
      else
	{
	  printf ("You lose this round.\n");
	  *status = 'L';

	}

      break;

    case 3:

      if (*sum_of_dices == specific_num)
	{
	  printf ("You win this round.\n");
	  *status = 'W';
	}
      else
	{
	  printf ("You lose this round.\n");
	  *status = 'L';

	}

      break;

    }
}
