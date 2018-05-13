/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: NastawaPWM
 * File: NastawaPWMCyclic.c
 * Author: Arkadiusz
 * Created: April 23, 2018
 ********************************************************************
 * Implementation of program NastawaPWM
 ********************************************************************/

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC NastawaPWMCyclic(void)
{
	const double mnoznik = 0.027;
	wynikNastawy = inputAnalogowy * mnoznik;
	
	inputPerc = wynikNastawy;
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
