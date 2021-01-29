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


#include "stddef.h"


#ifndef STDIO_H
#define STDIO_H

    int printf( char *str );
	int sprintf_i( char *s, int i );
    int getchar( void );
    char *gets( char *s );
    int setcolour( unsigned long int f, unsigned long int r, unsigned long int g, unsigned long int b );
    int cls( void );

#endif /*STDIO_H*/
