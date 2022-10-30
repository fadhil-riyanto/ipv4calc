
#include <stdio.h>
int
main (int argv, char *argc[])
{
        int data = 8;
        int changed_dataf = data;
        int binnums;

        for (; changed_dataf > 0;)
                {

                        // binnums = changed_dataf % (float)2;
                        binnums = changed_dataf % 2;
                        changed_dataf = changed_dataf / 2;
                        
                        fprintf (stdout, "%d", binnums);
                }
       
        // changed_dataf = changed_dataf / 2;
        // binnums = changed_dataf % 2;
        
}