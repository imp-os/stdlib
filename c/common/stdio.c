/**
 * Copyright 2019 AbbeyCatUK
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "stdio.h"
#include "svc.h"


int printf( char *str )
{

    unsigned long int result;

    _SVC_CALL1( OS_PrintString, str );

    return (int) result;

}


int sprintf_i( char *s, int i )
{

	// just get it working for now
	unsigned long int length, divisor, quotient;
	length = 0;

	if ( i == 0 )
	{

		*s++ = 48;
		length++;

	} else {

		divisor = 1000000000;
		while ( divisor >= 1 )
		{
			quotient = i / divisor;
			if ( quotient || length ) {
				*s++ = quotient + 48;
				length++;
				i -= (quotient * divisor);
			}
			divisor /= 10;
		}

	}

	// stick \0 at end
	*s = 0;
	length++;

	return 0;

}


int getchar( void )
{

    unsigned long int result;

    _SVC_CALL0( OS_ReadC );

    return (int) result;

}


char *gets( char *s )
{
	
    int  index, line_terminated, render;
    char next, printme[2];

    index = line_terminated = 0;
    while ( !line_terminated )
    {
		
        next   = getchar();
        render = 0;

        if ( next == 0x0a )
        {
                s[index++] = 0x00;
                line_terminated = 1;
        }
        else
        {
                if ( next == 0x7f )
                {
                    if (index > 0)
                    {
                        index--;
                        render = 1;
                    }
                }
                else
                {
                    if ( index < 255 )
                    {
                        s[index++] = next;
                        render = 1;
                    }
                }
        }

        if ( render )
        {
            printme[0] = next;
            printme[1] = 0x00;
            printf( printme );
        }
		
    }

    printf( "\n" );	
    return s;
	
}


int setcolour( unsigned long int f, unsigned long int r, unsigned long int g, unsigned long int b )
{

    unsigned long int result;

    _SVC_CALL4( OS_SetColour, f, r, g, b );

    return (int) result;

}



int cls( void )
{

    // KJS - "unsigned long int" is 32-bit in AArch32, and 64-bit in AArch64
    unsigned long int result;

    _SVC_CALL0( OS_ClearScreen );

    return (int) result;

}
