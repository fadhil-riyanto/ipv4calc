
#include <cstdio>
#include <cstdlib>

class ipv4utils
{
        int cidr_binary[32];   // 32 bit as  
        // binary_util binary_util;

      public:
        ipv4utils(int *cidr)
        {
                int sizeall = sizeof(this->cidr_binary) / sizeof(int);
                int i;
                for(i = 0; i < *cidr; i++)
                {
                        this->cidr_binary[i] = 1;
                }
                // fill last with zero;
                for(;i < sizeall; i++)
                {
                        this->cidr_binary[i] = 0;
                }

                for(int a = 0; a < sizeall; a++)
                {
                        fprintf(stdout, "%d", this->cidr_binary[a]);
                }
        }
};


int main()
{
        int data = 27;
        ipv4utils ipv4(&data);

}