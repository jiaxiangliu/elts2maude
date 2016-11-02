#include <stddef.h>
#include <stdlib.h>

#define __unlikely(x) x
#define __likely(x) x


extern int nondet_int();

char *strrchr(const char *t, int c) {
  register char ch;
  register const char *l=0;

  ch = c;
  for (;;) {
    if (__unlikely(*t == ch)) l=t; if (__unlikely(!*t)) return (char*)l; ++t;
#ifndef WANT_SMALL_STRING_ROUTINES
    if (__unlikely(*t == ch)) l=t; if (__unlikely(!*t)) return (char*)l; ++t;
    if (__unlikely(*t == ch)) l=t; if (__unlikely(!*t)) return (char*)l; ++t;
    if (__unlikely(*t == ch)) l=t; if (__unlikely(!*t)) return (char*)l; ++t;
#endif
  }
  return (char*)l;
}

int main(){
  int in_len = nondet_int();
  if(in_len < 1){return 1;}
  char* in = alloca(in_len);
  in[in_len-1]=0;
  int the_int = nondet_int();
  return (int) strrchr(in, the_int);
}
