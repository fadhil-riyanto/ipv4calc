
#include "ipv4calc.h"
#include <glibmm/ustring.h>
#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/enums.h>
#include <gtkmm/label.h>
#include <gtkmm/liststore.h>
#include <gtkmm/widget.h>
#include <gtkmm/window.h>
#include <sigc++/functors/mem_fun.h>

ipv4calc::ipv4calc ()
{
        const Glib::ustring app_title = "ipv4 calculator";
        Gtk::Window::set_title (app_title);
        Gtk::Widget::set_size_request (900, 500);
        this->v_gtkmm_box = (Gtk::Box)Gtk::Orientation::VERTICAL;
        set_child (this->v_gtkmm_box);

        this->make_ip_entry ();
        this->entry_and_submit.append (this->entry_ip);

        this->make_button ();
        this->entry_and_submit.append (this->gtkmm_button);
        v_gtkmm_box.append (this->entry_and_submit);
        this->gtkmm_button.signal_clicked ().connect (
            sigc::mem_fun (*this, &ipv4calc::on_submit));

        // tabel
        this->scrolled_window.set_child (treeview);
        v_gtkmm_box.append (this->scrolled_window);
        this->scrolled_window.set_policy (Gtk::PolicyType::AUTOMATIC,
                                          Gtk::PolicyType::AUTOMATIC);
        this->scrolled_window.set_expand ();

        // this->v_gtkmm_box.append(this->scrolled_window);
        this->ref_tree = Gtk::ListStore::create (columns);
        this->treeview.set_model (ref_tree);

        auto row = *(ref_tree->append ());
        for (int h = 0; h < 100; h++)
                {
                        row = *(ref_tree->append());
                        row[columns.subnet] = "satu";
                }

        this->treeview.append_column ("SUBNET", columns.subnet);
}

void
ipv4calc::on_submit ()
{
        printf ("%s\n", this->gtkmm_entry.get_text ().c_str ());
}

void
ipv4calc::make_ip_entry ()
{
        int max_byte_length = 3;
        int max_cidr_length = 2;

        this->ip_byte1.set_margin (10);
        this->ip_byte1.set_max_length (max_byte_length);

        this->ip_byte2.set_margin (10);
        this->ip_byte2.set_max_length (max_byte_length);

        this->ip_byte3.set_margin (10);
        this->ip_byte3.set_max_length (max_byte_length);

        this->ip_byte4.set_margin (10);
        this->ip_byte4.set_max_length (max_byte_length);

        this->ip_cidr.set_margin (10);
        this->ip_cidr.set_max_length (max_cidr_length);

        this->entry_ip.append (this->ip_byte1);
        this->entry_ip.append (this->ip_byte2);
        this->entry_ip.append (this->ip_byte3);
        this->entry_ip.append (this->ip_byte4);
        this->entry_ip.append (this->ip_cidr);
}

void
ipv4calc::make_button ()
{
        this->gtkmm_button = (Gtk::Button) "calculate!";
        this->gtkmm_button.set_margin (10);
}

void
ipv4calc::on_button_clicked ()
{
        printf ("%s\n", "clicked");
}
