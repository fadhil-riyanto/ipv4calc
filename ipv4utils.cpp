
#include <cstdlib>
#include <sys/types.h>

class binary_util
{

      public:
        u_int8_t binary_data[8];
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

        int
        to_dec (u_int8_t data[])
        {
                int literate[] = { 128, 64, 32, 16, 8, 4, 2, 1 }; // 8 bit only
                int sum = 0;
                for (int i = 0; i < 8; i++)
                        {
                                if (data[i] == 1)
                                        {
                                                sum = (sum
                                                       + (data[i]
                                                          * literate[i]));
                                        }
                        }
                return sum;
        }
};

enum IP_classtype
{
        A,
        B,
        C,
        D,
        E
};

class ipv4utils
{
        int cidr_binary[32]; // 32 bit as
        IP_classtype ipclass;

      public:
        ipv4utils (int *cidr)
        {
                int sizeall = sizeof (this->cidr_binary) / sizeof (int);
                int i;
                for (i = 0; i < *cidr; i++)
                        {
                                this->cidr_binary[i] = 1;
                        }
                // fill last with zero;
                for (; i < sizeall; i++)
                        {
                                this->cidr_binary[i] = 0;
                        }

                //this->ipclass = this->check_class(&first_bytes)
        }

      private:
        IP_classtype
        check_class (int *first_bytes)
        {
                if (*first_bytes > 0 && *first_bytes < 127)
                        {
                                return A;
                        }
                else if (*first_bytes > 128 && *first_bytes < 191)
                        {
                                return B;
                        }

                else if (*first_bytes > 192 && *first_bytes < 223)
                        {
                                return C;
                        }
                else if (*first_bytes > 224 && *first_bytes < 239)
                        {
                                return D;
                        }
                else
                        {
                                return E;
                        }
        }
};