#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sys/types.h>

class binary_util
{

      public:
        int binary_data[8];
        void
        to_bin (u_int8_t data)
        {
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
                int literateend = 0;
                for (int a = 8; a > 0; a--)
                        {
                                this->binary_data[literateend++]
                                    = binnums[a - 1];
                                // fprintf (stdout, "%d", binnums[a - 1]);
                        }
        }

        // int
        // to_dec (u_int8_t data)
        // {
        // }
};

int
main (int argc, char *argv[])
{
        binary_util binary_util;
        binary_util.to_bin (177);
        for (int i = 0; i < 8; i++)
                {
                        fprintf (stdout, "%d", binary_util.binary_data[i]);
                }
}