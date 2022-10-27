
#include "ipv4calc.h"
#include <glibmm/ustring.h>
#include <gtkmm/box.h>
#include <gtkmm/enums.h>
#include <gtkmm/widget.h>

ipv4calc::ipv4calc ()
{
        const Glib::ustring app_title = "ipv4 calculator program";
        set_title (app_title);
        Gtk::Widget::set_size_request (800, 500);

        this->v_gtkmm_box = (Gtk::Box)Gtk::Orientation::VERTICAL;
        set_child (this->v_gtkmm_box);

        this->make_entry(&this->gtkmm_entry);
        v_gtkmm_box.append (gtkmm_entry);
}
void
ipv4calc::make_entry (Gtk::Entry *gtk_entry)
{
        gtkmm_entry.set_max_length (18);
        gtkmm_entry.set_text ("Hello world");
}