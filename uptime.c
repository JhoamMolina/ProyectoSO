#include "types.h"
#include "user.h"
#include "stat.h"
#include "date.h"
//#include <stdio.h>
int
main(int argc, char *argv[])
{
  struct rtcdate r;

  if (date(&r)) {
	printf(2, "date failed\n");
	exit();
  }
  int aux = r.hour - 5;
  int h = 0;
  int m = r.minute;
  int s = r.second;
  if (aux < 0) {
   h = 24 + aux;
  }
  else {
   h = aux;
  }
  // su codigo debe imprimir el tiempo en el formato que desee...
  int ticks = uptime();
  int day = ticks / 86400;
  int hour = (ticks % 86400) / 3600;
  int minute = (ticks % 3600) / 60;
  /* Mostramos algunos valores interesantes contenidos en la estructura sysinfo. */
  printf(2,"%d:%d:%d up %d days, %d, %d:%d,",h,m,s,day,ticks,hour,minute);

  exit();
}
