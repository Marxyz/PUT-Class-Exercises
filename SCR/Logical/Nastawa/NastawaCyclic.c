/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: Nastawa
 * File: NastawaCyclic.c
 * Author: Arkadiusz
 * Created: April 23, 2018
 ********************************************************************
 * Implementation of program Nastawa
 ********************************************************************/

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC NastawaCyclic(void)
{
	const double mnoznik = 100.0/32768;
	wynikNastawy = (int) ( ( (double) inputAnalogowy ) * mnoznik);
	zadajnik = wynikNastawy;
	
}
