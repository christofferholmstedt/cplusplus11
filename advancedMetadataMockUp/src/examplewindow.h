#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>
#include <vector>

class ExampleWindow : public Gtk::Window
{
public:
    ExampleWindow();
    virtual ~ExampleWindow();

protected:
    //Signal handlers:
    void on_button_close();

    // ListStore (left part of pane)
    class ModelColumns : public Gtk::TreeModel::ColumnRecord
    {
        public:
            ModelColumns()
            { add(id); add(title); add(creator);}

            Gtk::TreeModelColumn<unsigned int> id;
            Gtk::TreeModelColumn<Glib::ustring> title;
            Gtk::TreeModelColumn<Glib::ustring> creator;
    };

    ModelColumns columns;
    Gtk::ScrolledWindow left_scrolledwindow;
    Gtk::ScrolledWindow right_scrolledwindow;
    Gtk::TreeView treeview;
    Glib::RefPtr<Gtk::ListStore> refTreeModel;

    //Child widgets:
    Gtk::VBox outer_vbox;
    Gtk::VBox right_pane_vbox;
    Gtk::HPaned main_window_hpaned;
    Gtk::Table right_pane_table;
    Gtk::HButtonBox bottom_hbuttonbox;
    Gtk::Button button_close;
    Gtk::Button temp2;
};

#endif //GTKMM_EXAMPLEWINDOW_H
