#include <gtkmm.h>
#include <iostream>

class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow::ExampleWindow() :
    m_Table(2, 2, false)
  {
    set_size_request(300, 100);
    set_title("Gtk::Entry");

    add(m_Table);

    m_Entry1.set_text("1");
    m_Table.attach(m_Entry1, 0, 1, 0, 1);
    m_Entry2.set_text("2");
    m_Table.attach(m_Entry2, 0, 1, 1, 2);

    m_Table.attach(m_Button1, 1, 2, 0, 1);
    m_Table.attach(m_Button2, 1, 2, 1, 2);

    // Tab
    GList* entry_list = 0;
    entry_list = g_list_append(entry_list,
m_Entry1.gobj());
    entry_list = g_list_append(entry_list,
m_Entry2.gobj());
    std::cerr << "size : " << g_list_length(entry_list)
<< std::endl;

set_focus_chain(Glib::ListHandle<Gtk::Widget*>(entry_list,
Glib::OWNERSHIP_NONE));
    g_list_free(entry_list);

    show_all_children();
  }

protected:
  Gtk::HBox m_HBox;
  Gtk::Table m_Table;
  Gtk::Entry m_Entry1;
  Gtk::Entry m_Entry2;

  Gtk::Button m_Button1;
  Gtk::Button m_Button2;
};


int main(int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);

  ExampleWindow window;
  Gtk::Main::run(window);

  return 0;
}
