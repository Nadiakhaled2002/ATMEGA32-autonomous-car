/*
 * main.c
 *
 *  Created on: Jan 31, 2024
 *      Author: nadia
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "USS_interface.h"
#include"STD_TYPES.h"
#include"BIT_MATH.H"
#include <string.h>

#include "LCD_interface.h"
#include "SRVM_interface.h"
#include "GIR_interface.h"
#include "DCMOTOR_interface.h"

static u16 flag_dist=0;
static  u16 dist_str = 0;
static u16 dist_righ = 0;
static u16 dist_left = 0;
static u16 max_dist = 0;
static u16 MAX;
static u8 f1=0;
static u8 f2=0;

static u8 f4=0;
void check_180Direct(void);
void noObstecaleDirection(void);
void GoToNoObstacle(void);
int main(void)
{


//initiating the ultra sonic sensor amd the servo motor
	 SRVM_init();
	 USS_init();
	 LCD_init();

	while (1)
		{
//there are 3 sw flags to make sure that the functiion gets executed before jumping on the next function
		while(!f1)
		{
		check_180Direct();//the uss checks the 3 directions then saves them
		}
f1=0;//clearing the flags
while(!f2)
{
		noObstecaleDirection();//a function that figures the best way for the car to take
}
f2=0;
//clearing the flags
		while(!f4)
		{//this while loop makes sure that car stops if it finds an obstacle the program will start over
			GetDistance(&flag_dist);
			if(flag_dist<=10)
			{
				LCD_clear();
				LCD_writeString("STOP");
				DCMOTOR_stop();
				f4=1;
			}
			if(f4==0)
			{
		GoToNoObstacle();//if there was no obstacle found the car will continue moving
			}





}
		f4=0;//clearing the flags




		}

		}

void check_180Direct(void)
{


	 SRVM_on(55);//straight


				while(!dist_str)
				{
					GetDistance(&dist_str);
				}
				_delay_ms(1000);

					 SRVM_on(5);//right


					 while(!dist_righ)
					 			{
					 				GetDistance(&dist_righ);
					 			}
					 _delay_ms(1000);

					 SRVM_on(105);//left

									 while(!dist_left)
									 			{
									 				GetDistance(&dist_left);
									 			}
									 _delay_ms(1000);

									 SRVM_on(55);
									 f1=1;
}

void noObstecaleDirection(void)
{
//this function gets the max distance right,left and straight from the car and if the 3 directions is less than 15 cm it will make a u-turn

	  if (dist_str >=dist_righ && dist_str >= dist_left)
	  {
		  MAX='S';
		  max_dist=dist_str;
	  }
	    else if (dist_righ >= dist_str && dist_righ >= dist_left)
	    {
	    	MAX='R';
	    	max_dist=dist_righ;
	    }
	    else
	    {
	    	MAX='L';
	    	max_dist=dist_left;
	    }


	  f2=1;
}

void GoToNoObstacle(void)
{

	switch (MAX)
				{
				case 'S'://straight
				{
					//flag if uss found a distance less than 30cm if flag==1 break
					LCD_clear();
					LCD_writeString("Straight");
						 DCMOTOR_start(forward);


					break;
				}
				case 'R'://right
				{//flag if uss found a distance less than 30cm if flag==1 break
					LCD_clear();
					LCD_writeString("Right");
		                      DCMOTOR_right();

		                       DCMOTOR_start(forward);



					break;
				}
				case 'L'://left
				{//flag if uss found a distance less than 30cm if flag==1 break
					LCD_clear();
					LCD_writeString("Left");
						DCMOTOR_left();

						 DCMOTOR_start(forward);



					break;
				}



				}
MAX=0;
dist_str = 0;
dist_righ = 0;
dist_left = 0;
max_dist=0;

}

