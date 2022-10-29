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
        Gtk::Box entry_and_submit;
        Gtk::Entry gtkmm_entry;

        Gtk::Button gtkmm_button;

        void make_entry ();
        void make_button ();
        void on_button_clicked ();
        void on_submit();
};

#endif