# Reverse a C-Style string

String in C are implemented as an fixed-size array of bytes. Because strings are mutable in C and stored in arrays that are unaware of thier size, C-strings make use of a sentinel to mark the end of a string, the null terminating character - `\0`. This means any string of N length is really implemented as an array of N+1 bytes, the N+1th byte being `\0`.

Write a function to reverse an array of ascii characters (or bytes) that is termninated by a sentinel` 
