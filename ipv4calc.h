#ifndef IPV4_CALC_H
#define IPV4_CALC_H

#include <gtkmm.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class ipv4calc : public Gtk::Window
{

      public:
        ipv4calc ();

      private:
        Gtk::Box v_gtkmm_box;
        Gtk::Box h_gtkmm_box;
        Gtk::Entry gtkmm_entry;

        void make_entry(Gtk::Entry* gtk_entry);
};

#endif