
#include "ipv4calc.h"
#include <glibmm/ustring.h>
#include <gtkmm/box.h>
#include <gtkmm/enums.h>
#include <gtkmm/widget.h>
#include <gtkmm/window.h>
#include <sigc++/functors/mem_fun.h>

ipv4calc::ipv4calc ()
{
        const Glib::ustring app_title = "ipv4 calculator";
        Gtk::Window::set_title (app_title);
        Gtk::Widget::set_size_request (800, 500);
        this->v_gtkmm_box = (Gtk::Box)Gtk::Orientation::VERTICAL;
        set_child (this->v_gtkmm_box);

        this->make_entry ();
        this->entry_and_submit.append (this->gtkmm_entry);

        this->make_button ();
        this->entry_and_submit.append (this->gtkmm_button);
        v_gtkmm_box.append (this->entry_and_submit);
        this->gtkmm_button.signal_clicked().connect(sigc::mem_fun(*this, &ipv4calc::on_submit));
}

void
ipv4calc::on_submit()
{
        printf("%s\n", this->gtkmm_entry.get_text().c_str());
}

void
ipv4calc::make_entry ()
{
        this->gtkmm_entry.set_max_length (18);
        this->gtkmm_entry.set_text ("255.255.255.0/24");
        this->gtkmm_entry.set_margin (10);
}

void
ipv4calc::make_button ()
{
        this->gtkmm_button = (Gtk::Button) "btn";
        this->gtkmm_button.set_margin (10);
        
}

void
ipv4calc::on_button_clicked ()
{
        printf ("%s\n", "clicked");
}