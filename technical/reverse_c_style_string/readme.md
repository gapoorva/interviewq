# Reverse a C-Style string

String in C are implemented as an fixed-size array of bytes. Because strings are mutable in C and stored in arrays that are unaware of their size, C-strings make use of a sentinel to mark the end of a string, the null terminating character - `\0`. This means any string of N length is really implemented as an array of N+1 bytes, the N+1 th byte being `\0`.

Write a function to reverse an array of ASCII characters (or bytes) that is terminated by a sentinel. 

Example:

`"my c-string\0"` should be reversed to `"gnirts-c ym\0"` 

## Solutions

| Language | Time   | Space | Authors  |
|----------|--------|-------|----------|
| golang   | N      | 1     | gapoorva |
