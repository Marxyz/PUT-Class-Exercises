/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: GettingInput
 * File: GettingInputCyclic.c
 * Author: Arkadiusz
 * Created: April 25, 2018
 ********************************************************************
 * Implementation of program GettingInput
 ********************************************************************/

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC GettingInputCyclic(void)
{
	if (input1 == 1 && inputIterator == 0)
	{
		previousP1 = 1;
	}
	
	if (input1 == 0 && previousP1 == 1 )
	{
	 	subs1Value = zadajnik;
		inputIterator++;
		previousP1 = 0;
	}
	
	if (input1== 1 && inputIterator == 1)
	{
		previousP2 = 1;
	}
	
	if (input1 == 0 && previousP2 == 1 )
	{
		subs2Value = zadajnik;
		inputIterator--;
		previousP2 = 0;
	}
}
