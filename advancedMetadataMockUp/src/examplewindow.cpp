#include "examplewindow.h"
#include <gtkmm.h>
#include <vector>
#include <iostream>

ExampleWindow::ExampleWindow()
: button_close("Close"),
    button_export_metadata("Export metadata"),
    temp2("button2")
{
    // set_size_request(200, 100);
    set_title("WIP Metadata Editor MockUp for Inkscape");
    set_default_size(600,450);

    /* Overview structure */
    add(outer_vbox);
    outer_vbox.add(main_window_hpaned);
    outer_vbox.pack_start(bottom_hbuttonbox, false, 0 /* no effect */, 5);

    /* Position of pane divider */
    main_window_hpaned.set_position(250);

    /*************************************
     * Right pane
     *************************************/
    main_window_hpaned.add2(right_pane_vbox);
    // right_scrolledwindow.add(right_pane_vbox);
    // right_scrolledwindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    // Image

    // Entry list

    // First row
    Gtk::HBox *space1 = manage (new Gtk::HBox);
    space1->set_size_request(15,15);

    Gtk::Label *label1 = manage (new Gtk::Label);
    label1->set_markup("Title");
    Gtk::Entry *e1 = new Gtk::Entry;

    right_pane_vbox.pack_start(*space1, false, 0, 10);
    space1->pack_start(*label1, false, 0, 10);
    space1->pack_start(*e1, false, 0, 10);

    // Second row
    Gtk::HBox *space2 = manage (new Gtk::HBox);
    space2->set_size_request(15,15);

    Gtk::Label *label2 = manage (new Gtk::Label);
    label2->set_markup("Creator");
    Gtk::Entry *e2 = new Gtk::Entry;

    // right_pane_vbox.pack_start(*space2, false, 0, 10);
    right_pane_vbox.add(*space2);
    space1->pack_start(*label2, false, 0, 10);
    space1->pack_start(*e2, false, 0, 10);

    // License list

    /*************************************
     * Left pane
     *************************************/
    left_scrolledwindow.add(treeview);
    left_scrolledwindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    main_window_hpaned.add1(left_scrolledwindow);

    // Fill the tree view with some made up information
    refTreeModel = Gtk::ListStore::create(columns);
    treeview.set_model(refTreeModel);

    // First row
    Gtk::TreeModel::Row row = *(refTreeModel->append());
    row[columns.id] = 1;
    row[columns.title] = "Collage";
    row[columns.creator] = "Christoffer";

    // Second row
    row = *(refTreeModel->append());
    row[columns.id] = 2;
    row[columns.title] = "Circle";
    row[columns.creator] = "Christoffer";

    // Third row
    row = *(refTreeModel->append());
    row[columns.id] = 3;
    row[columns.title] = "Rectangle";
    row[columns.creator] = "Christoffer";

    // Show the different columns in the user interface
    // by adding them to the treeview.

    treeview.append_column("Title", columns.title);
    treeview.append_column("Creator", columns.creator);

    /*************************************
     * Bottom buttons
     *************************************/
    bottom_hbuttonbox.set_layout(Gtk::BUTTONBOX_END);

    // Normalise button
    bottom_hbuttonbox.pack_start(button_export_metadata, false, 0);

    // Close button
    button_close.signal_clicked().connect( sigc::mem_fun(*this,
                &ExampleWindow::on_button_close) );
    bottom_hbuttonbox.pack_start(button_close);
    button_close.set_can_default();
    button_close.grab_default();

    /*************************************
     * Show everything
     *************************************/

    show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_button_close()
{
  hide();
}

