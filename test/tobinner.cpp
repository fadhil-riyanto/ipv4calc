#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sys/types.h>

class tobinner
{
      public:
        std::string *
        to_bin (u_int8_t data)
        {
                std::string *listofbinner;
                listofbinner = (std::string*)malloc (sizeof (std::string) *
                8);

                return listofbinner;
        }
        void
        freeup (std::string *memory_addr)
        {
                free (memory_addr);
        }
};

int
main (int argc, char *argv[])
{
        tobinner tobinner;
        tobinner.freeup (tobinner.to_bin (3));
}