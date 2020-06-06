#include "types.h"
#include "user.h"
#include "stat.h"
#include "date.h"

int
main(int argc, char *argv[])
{
  //Hora actual del sistema...
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

  // Tiempo uptime...
  int ticks = uptime();
  //int second = (ticks / 75) % 60;	//Valores asumiendo que son 75 ticks por cada segundo aprox...
  int minute = (ticks / 4500) % 60;
  int hour = (ticks / 270000) % 60;
  int day = (ticks / 6480000) % 24;

  //Se imprime el formato del comando uptime...
  printf(2,"%d:%d:%d up %d days, %d:%d,",h,m,s,day,hour,minute);

  exit();
}
