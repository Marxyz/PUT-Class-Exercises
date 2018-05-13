/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: Testowy
 * File: TestowyCyclic.c
 * Author: Arkadiusz
 * Created: April 16, 2018
 ********************************************************************
 * Implementation of program Testowy
 ********************************************************************/

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC TestowyCyclic(void)
{
	inputPerc = 50;
	inputT_Ms = 20000;
	const cycleTime = 10;
	cycleIterator = cycleIterator + 1;
	time = cycleIterator * cycleTime;
	upTime = ((double)inputPerc/100) * inputT_Ms;
	
	if (time < upTime)
	{
		out1 = 1;
	}
	else
	{
		out1 = 0;
	}

	if (time >= inputT_Ms)
	{
		time = 0;
		cycleIterator = 0;
	}
	
	
}
