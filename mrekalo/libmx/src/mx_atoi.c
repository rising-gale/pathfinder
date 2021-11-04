#include "libmx.h"

int mx_atoi(const char *str);
int mx_atoi (const char *str)
{
  int i = 0;
  int sign = 0;
  int number = 0;
  while (str[i] != '\0')
    {
      if (!mx_isspace (str[i]))
	{
	  if (mx_isdigit (str[i]))
	    {
	      number = number * 10;
	      number = number + (str[i] - '0');
	    } else if (number > 0)
	        {
	            return (sign == 1 ? -number : number);
	        } else if(str[i]=='-')
	            {
	                if(mx_isdigit(str[i+1]))
	                {
	                        if(sign==0)
							{
	                            sign =1;
	                    	} 
	            
	                        
	            	}	else return NOT_INT;
	            
	            } else if(!(str[i]=='+'))
				{
					return NOT_INT;
				}
	}
      i++;
    }
  return (sign == 1 ? -number : number);
}
