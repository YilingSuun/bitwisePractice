/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2024 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
//1
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  // ~(x or y) is equals to ~x and ~y according to De Morgan Law
  int num = ~x & ~y;

  return ~num;  // reverse ~(x or y)
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  // shift 1 to the sign bit of integer like 0x10000000
  int num = 1 << 31;

  return ~num; // then reverse it.
}
//2
/* 
 * implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: implication(1,1) = 1
 *            implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y) {
  return !x | y; // Only return false when x is true and y is false
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  // make the sign bit equal to the least significant bit and other bits are 0
  int num = x << 31;

  // right shift to set all bits to least significant bit
  return num >> 31;
}
//3
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  int sum = x + y;
  // overflow case 1: x,y are positive and sum is negative
  // overflow case 2: x,y are negative and sum is positive

  // detect if the sign of both x and y equal to sum
  // num is only true when both x and y are not equal to sum
  int num = (x >> 31^sum >> 31)&(y >> 31^sum >> 31);
  return !num;
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
  //calculate the leftmost n bits of the integer
  int leftShift = x << (32 + (~n + 1));

  //calculate the right-part of the integer
  int rightShift = x >> n;

  //should set all other bits to 0 in rightshift if x is negative
  int mask = (1 << (32 + (~n + 1))) + (~1 + 1); // set rightmost n bits to 0
  rightShift &= mask;

  // combine them together
  return leftShift | rightShift;
}
//4
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  // find -x using two's complement negation
  int negX = ~x + 1;

  // if -x and x share the same sign bit 0, set sign to 0, other wise -1
  int sign = (x | negX) >> 31;
  // if -x and x sign bit = 0(x = 0), return 1, otehrwise return 0
  return sign + 1;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  int mask1, mask2, mask4, mask8, mask16;

  mask1 = 0x55 | (0x55 << 8); // 01010101
  mask1 = mask1 | (mask1 << 16);
  mask2 = 0x33 | (0x33 << 8); // 00110011
  mask2 = mask2 | (mask2 << 16);
  mask4 = 0x0F | (0x0F << 8); // 00001111
  mask4 = mask4 | (mask4 << 16);
  mask8 = 0xFF | (0xFF << 16); // 00000000 11111111
  mask16 = 0xFF | (0xFF << 8);
    
  // count bits in each pair of bits 
  x = (x & mask1) + ((x >> 1) & mask1);
    
  // count bits in each 4-bit groups
  x = (x & mask2) + ((x >> 2) & mask2);
    
  // count bits every 8-bit
  x = (x & mask4) + ((x >> 4) & mask4);
    
  // count bits every 16-bit
  x = (x & mask8) + ((x >> 8) & mask8);
  x = (x & mask16) + ((x >> 16) & mask16);
    
  return x; // Return the lower 8 bits
}
//float
/* 
 * floatScale64 - Return bit-level equivalent of expression 64*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 35
 *   Rating: 4
 */
unsigned floatScale64(unsigned uf) {
  unsigned sign = uf & 0x80000000;  // get the sign bit
  unsigned exp = (uf >> 23) & 0xFF; // get the exponent bits
  unsigned frac = uf & 0x7FFFFF;    // get the fraction bits
  int i = 1;

  if (exp == 0xFF) {
    // NaN or Infinity, return argument
    return uf;
  }

  if (exp != 0) {
    exp += 6;  // multiply by 64 (2^6)

    // if overflow
    if (exp >= 0xFF) {
      return sign | 0x7F800000;  // return infinite number
    }

    // return the normal case for float
    return sign | (exp << 23) | frac;
  }

  // Denormalized example（exp == 0）
  while (i <= 6) {
    frac <<= 1; // multiply frac by 2

    if (frac & 0x800000) { // become not denormalized
      exp = 1;
      frac &= 0x7fffff;
      exp += (6 - i); //multiply by remain number
      return sign | (exp << 23) | frac;
    }
    i++; //if still denormalized, continue the loop
  }

  return sign | (exp << 23) | frac;
}
/* 
 * floatInt2Float - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatInt2Float(int x) {
  // Variables
  unsigned sign = 0;
  unsigned exp, frac;
  unsigned abs_x = x;
  int maxPosition = 0;
  unsigned temp;
  int roundBit, followingBit;

  // zero case
  if (x == 0) {
    return 0;
  }
  // Handle the sign
  if (x < 0) {
    sign = 1;
    abs_x = -x;
  }

  // calculate the position of the highest bit
  temp = abs_x;
  while (temp != 0) {
    maxPosition++;
    temp >>= 1;
  }

  // calculate exponent = maxPosition - 1 + 127 (bias)
  exp = maxPosition + 126;

  // calculate frac
  // drop the leading 1 and take the next 23 bits
  if (maxPosition > 24) {
    // right shift the number to fit into 23 bits
    frac = (abs_x >> (maxPosition - 24)) & 0x7FFFFF;  // Take lower 23 bits

    roundBit = (abs_x >> (maxPosition - 25)) & 1; // Last bit to check
    followingBit = abs_x & ((1 << (maxPosition - 25)) - 1); // following bits

    // Round up
    if (roundBit) {
      // If following bits are non-zero, round up
      if (followingBit) {
        frac += 1; // Round up
      } else if ((frac & 1)) {
        // If frac is odd, round up to make it even
        frac += 1; 
      }
    }
    // handle rounding overflow
    if (frac == 0x800000) {
      frac = 0;
      exp += 1; 
    }
  } else {
    // left shift the number to fill the frac position
    frac = (abs_x << (24 - maxPosition)) & 0x7FFFFF;
  }

  return (sign << 31) | (exp << 23) | frac;
}
