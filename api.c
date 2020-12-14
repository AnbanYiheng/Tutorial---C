#include <stdio.h>
#include "api.h" 
 
int check(const char *data, int len) 
{ 
  if(len >= 1024)return 0;
  printf("run\n"); 
  
  //异常的业务逻辑
  if (len > 0 && data[0] == 'a')
    if (len > 1 && data[1] == 'n')
        if (len > 2 && data[2] == 'b')
            if(len > 3 && data[3] == 'a')
                if(len > 4 && data[4] == 'n')
                    if(len > 5 && data[5] == '6')
                        if(len > 6 && data[6] == '6')
                            if(len > 7 && data[7] == '6')
                            {
                                printf("bug here\n");
                                int* p = NULL;  // bug
                                *p = 23;
                            }                                  
  return 0; 
}
