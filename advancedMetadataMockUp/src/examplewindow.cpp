#include "examplewindow.h"
#include <vector>
#include <iostream>

ExampleWindow::ExampleWindow()
: button_close("Close"),
    button_export_metadata("Export metadata"),
    temp1("button1"),
    temp2("button2")
{
    // set_size_request(200, 100);
    set_title("WIP Metadata Editor MockUp for Inkscape");
    // set_default_size(450,450);

    /* Overview structure */
    add(outer_vbox);
    outer_vbox.add(main_window_hpaned);
    outer_vbox.add(bottom_hbuttonbox);

    /* Position of pane divider */
    main_window_hpaned.set_position(150);


    /* Left view of the hpane */
    main_window_hpaned.add1(temp1);

    /* Right view of the hpane */
    main_window_hpaned.add2(temp2);
/*
    // Entry fields available from the beginning
    m_Entry.set_max_length(50);
    m_Entry.set_text("hello");
    m_Entry.set_text(m_Entry.get_text() + " world");
    m_Entry.select_region(0, m_Entry.get_text_length());
    m_VBox.pack_start(m_Entry);

    t_Entry.set_max_length(50);
    t_Entry.set_text("test");
    t_Entry.set_text(m_Entry.get_text() + " naaah");
    t_Entry.select_region(0, m_Entry.get_text_length());
    m_VBox.pack_start(t_Entry);

    // Note that add() can also be used instead of pack_xxx()
    m_VBox.add(m_HBox);

    m_HBox.pack_start(m_CheckButton_Editable);
    m_CheckButton_Editable.signal_toggled().connect( sigc::mem_fun(*this,
                &ExampleWindow::on_checkbox_editable_toggled) );
    m_CheckButton_Editable.set_active(true);

    m_HBox.pack_start(m_CheckButton_Visible);
    m_CheckButton_Visible.signal_toggled().connect( sigc::mem_fun(*this,
                &ExampleWindow::on_checkbox_visibility_toggled) );
    m_CheckButton_Visible.set_active(true);
    */

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
/*
void ExampleWindow::on_checkbox_editable_toggled()
{
  m_Entry.set_editable(m_CheckButton_Editable.get_active());
}

void ExampleWindow::on_checkbox_visibility_toggled()
{
  m_Entry.set_visibility(m_CheckButton_Visible.get_active());
}
*/
void ExampleWindow::on_button_close()
{
  hide();
}

