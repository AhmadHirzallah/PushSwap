#include "all_headers.h"

void turk_set_flag(t_turk_algo_data *tad, t_stack_flags flag)
/*
|= is a bitwise operation that specifically sets bits in the bitmask.

If you do +=, you might add the same value multiple times
and end up with a number that does not simply represent “set that bit.”
 For instance, if flags already has the bit set,
  adding again will increase the numeric value incorrectly.
   Bitwise OR ensures that once a bit is set, it stays set, without messing up other bits.
*/
{
    tad->flags |= flag;
}

void turk_unset_flag(t_turk_algo_data *tad, t_stack_flags flag)
/*
&= is the bitwise AND assignment operator.

~flag is the bitwise NOT of flag. The bitwise NOT inverts all bits in flag.
Means:
1. Take ~flag (which has all bits flipped relative to flag),
2. (AND &) that with the current tad->flags.
If flag = 0b0010 (2 in decimal, in a small 4‐bit world), then ~flag = 0b1101.

This effectively clears (unsets) the bits that flag represents.

-= is arithmetic subtraction.
If you subtract the numeric value of flag from tad->flags,
you might accidentally affect bits that shouldn’t be touched;
;;or even produce negative numbers (depending on the initial value of flags).
It does not reliably turn off specific bits.
In a typical 32‐bit integer,
 flag = 2 is actually 00000000 00000000 00000000 00000010 in binary,
	 so ~flag becomes 11111111 11111111 11111111 11111101.
*/
{
    tad->flags &= ~flag;
}

short turk_has_flag(const t_turk_algo_data *tad, t_stack_flags flag)
/*
& is the bitwise AND operator.
(tad->flags & flag) != 0 checks if at least one of the bits in flag is also set in tad->flags.
If that result is nonzero, it means the bit(s) you care about are set.
*/
{
    return ((tad->flags & flag) != 0);
}