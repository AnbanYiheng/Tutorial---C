#include "api.h" 
 
int check(const char *data, int len) 
{ 
  if(len >= 1024)return 0;
  char buf[1024]; 
  memset(buf, 0, 1024); 
  strncpy(buf, data, len);
 
  int buflen = strlen(buf); 
  
  //异常的业务逻辑
  if (size > 0 && data[0] == 'a')
    if (size > 1 && data[1] == 'n')
        if (size > 2 && data[2] == 'b')
            if(size > 3 && data[3] == 'a')
                if(size > 4 && data[4] == 'n')
                    if(size > 5 && data[5] == '6')
                        if(size > 6 && data[6] == '6')
                            if(size > 7 && data[7] == '6')
                            {
                                printf("bug here\n");
                                int* p = nullptr;  // bug
                                *p = 23;
                            }              
  return 0; 
}
