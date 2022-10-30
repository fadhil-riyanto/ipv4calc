
#include <stdio.h>
int
main (int argv, char *argc[])
{
        int data = 74;
        int changed_dataf = data;
        int binnums[8];
        int i = 0;
        for (; changed_dataf > 0;)
                {
                        binnums[i++] = changed_dataf % 2;
                        changed_dataf = changed_dataf / 2;
                }
        
        // fill last byte with zero
        for (; i < 8;)
                {
                        binnums[i++] = 0;
                }
        for (int a = 8; a > 0; a--)
                {
                        fprintf (stdout, "%d", binnums[a - 1]);
                }
        // changed_dataf = changed_dataf / 2;
        // binnums = changed_dataf % 2;
}