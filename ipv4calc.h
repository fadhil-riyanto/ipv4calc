#ifndef IPV4_CALC_H
#define IPV4_CALC_H

#include <glibmm/refptr.h>
#include <glibmm/ustring.h>
#include <gtkmm.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include <gtkmm/liststore.h>
#include <gtkmm/treemodel.h>
#include <gtkmm/treemodelcolumn.h>
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
        Glib::ustring ip_and_cidr;

        // for 4 byte of ip and cidr value
        Gtk::Entry ip_byte1;
        Gtk::Entry ip_byte2;
        Gtk::Entry ip_byte3;
        Gtk::Entry ip_byte4;
        Gtk::Entry ip_cidr;
        Gtk::Box entry_ip;

        // table
        class coloumn : public Gtk::TreeModel::ColumnRecord
        {
              public:
                Gtk::TreeModelColumn<Glib::ustring> subnet;
                coloumn () { add (subnet); }
        };
        Gtk::ScrolledWindow scrolled_window;
        Gtk::TreeView treeview;
        coloumn columns;
        Glib::RefPtr<Gtk::ListStore> ref_tree;

        void make_ip_entry ();
        void make_button ();
        void on_button_clicked ();
        void on_submit ();
};

#endif