#include "main.h"

int main(void)
{
  
    char s[] = "this is the way.azuka.amadi";
    char delm[] = " .";

    char *portion = strtok(s, delm);

    while (portion != NULL)
    {
	    printf("%s\n", portion);
	    portion = strtok(NULL, delm);
    }

}
