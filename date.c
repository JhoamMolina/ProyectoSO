#include "types.h"
#include "user.h"
#include "date.h"

int main(int argc, char *argv[])
{
  struct rtcdate r;
  if(date(&r))
  {
    printf(2, "date failed\n");
  }
  if(r.minute+30>59)
	{
		r.hour += 6;
		r.minute = r.minute+30-59;
	}
	else
	{
		r.hour += 5;
		r.minute += 30;
	}
	if(r.hour>=24)
		r.hour -= 24;
	printf(1," %d:%d:%d\n",r.hour,r.minute,r.second);

  exit();
}
