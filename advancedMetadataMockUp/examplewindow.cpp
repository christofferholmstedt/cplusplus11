#include "examplewindow.h"
#include <vector>
#include <iostream>

ExampleWindow::ExampleWindow()
: m_Button_Close("Close"),
  m_CheckButton_Editable("Editable"),
  m_CheckButton_Visible("Visible"),
  m_Button_normalise("Normalise")
{
  // set_size_request(200, 100);
  set_title("WIP Advanced Metadata Editor MockUp for Inkscape");

  add(m_VBox);

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

  // Normalise button
  m_HBox.pack_start(m_Button_normalise);

  // Close button
  m_Button_Close.signal_clicked().connect( sigc::mem_fun(*this,
              &ExampleWindow::on_button_close) );
  m_HBox.pack_start(m_Button_Close);
  m_Button_Close.set_can_default();
  m_Button_Close.grab_default();

  // Testing to change focus chain for tabbing
/*
    GList* entry_list = 0;
    entry_list = g_list_append(entry_list,
        t_Entry.gobj());
    entry_list = g_list_append(entry_list,
        m_Entry.gobj());
    std::cout << "g_list_length (size): " << g_list_length(entry_list)
    << std::endl;

    m_VBox.set_focus_chain(Glib::ListHandle<Gtk::Widget*>(entry_list,
        Glib::OWNERSHIP_NONE));
    g_list_free(entry_list);
*/
    // Last step to show everything
    show_all_children();

}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_checkbox_editable_toggled()
{
  m_Entry.set_editable(m_CheckButton_Editable.get_active());
}

void ExampleWindow::on_checkbox_visibility_toggled()
{
  m_Entry.set_visibility(m_CheckButton_Visible.get_active());
}

void ExampleWindow::on_button_close()
{
  hide();
}

