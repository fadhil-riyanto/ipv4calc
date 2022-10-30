
#include <stdio.h>
int
main (int argv, char *argc[])
{
        int data = 212;
        int changed_dataf = data;
        int binnums;
        for (int i = 0; i < 8; i++)
                {
                        fprintf (stdout, "%d\n", binnums);
                        // binnums = changed_dataf % (float)2;
                        changed_dataf = changed_dataf / 2;
                        binnums = changed_dataf % 2;
                        
                        
                }


        
}