
#include "ipv4calc.h"
#include <glibmm/ustring.h>

ipv4calc::ipv4calc ()
{
        const Glib::ustring app_title = "ipv4 calculator program";
        set_title (app_title);
        set_default_size (600, 200);
}
