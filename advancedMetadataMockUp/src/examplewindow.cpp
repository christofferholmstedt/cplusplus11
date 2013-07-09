#include "examplewindow.h"
#include <gtkmm.h>
#include <vector>
#include <iostream>

ExampleWindow::ExampleWindow()
: button_close("Close"),
    right_pane_table(18,18,false),
    temp2("button2")
{
    // only c++11 std::vector<std::string> labels{"test1", "test2", "test3"};
    std::vector<std::string> labels;
    labels.push_back("Title");
    labels.push_back("Date");
    labels.push_back("Creator");
    labels.push_back("Rights");
    labels.push_back("Publisher");
    labels.push_back("Identifier");
    labels.push_back("Source");
    labels.push_back("Relation");
    labels.push_back("Language");
    labels.push_back("Keywords");
    labels.push_back("Coverage");
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
    //right_scrolledwindow.set_border_width(10);
    main_window_hpaned.add2(right_scrolledwindow);
    right_scrolledwindow.add(right_pane_table);
    right_pane_table.set_row_spacings(5);
    right_pane_table.set_col_spacings(5);
    right_scrolledwindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    // Image

    // Entry list

    for (int i = 1; i < 12; i++)
    {
        Gtk::Label *label = manage (new Gtk::Label);
        label->set_markup(labels[i-1]);
        label->set_alignment(Gtk::ALIGN_END, Gtk::ALIGN_CENTER);
        Gtk::Entry *entry = new Gtk::Entry;

        right_pane_table.attach(*label, 0, 1, i , i + 1, Gtk::FILL, (Gtk::AttachOptions)0, 5, 0);
        right_pane_table.attach(*entry, 1, 2, i , i + 1, Gtk::FILL|Gtk::EXPAND, (Gtk::AttachOptions)0, 0, 0);
    }

    // First row
    // Gtk::HBox *space1 = manage (new Gtk::HBox);
    // space1->set_size_request(15,15);
/*
    Gtk::Label *label1 = manage (new Gtk::Label);
    label1->set_markup("Title");
    label1->set_alignment(Gtk::ALIGN_END, Gtk::ALIGN_CENTER);
    Gtk::Entry *e1 = new Gtk::Entry;

    right_pane_table.attach(*label1, 0, 1, 0, 1, Gtk::FILL, Gtk::FILL, 5, 0);
    right_pane_table.attach(*e1, 1, 2, 0, 1, Gtk::FILL, Gtk::FILL, 5, 0);

    // Second row
    Gtk::HBox *space2 = manage (new Gtk::HBox);
    // space2->set_size_request(15,15);

    Gtk::Label *label2 = manage (new Gtk::Label);
    label2->set_markup("Creator");
    label2->set_alignment(Gtk::ALIGN_END, Gtk::ALIGN_CENTER);
    Gtk::Entry *e2 = new Gtk::Entry;

    right_pane_table.attach(*label2, 0, 1, 1, 2, Gtk::FILL, Gtk::FILL, 5, 0);
    right_pane_table.attach(*e2, 1, 2, 1, 2, Gtk::FILL, Gtk::FILL, 5, 0);
*/
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

