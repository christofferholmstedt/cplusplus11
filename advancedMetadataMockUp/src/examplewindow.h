#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();
  virtual ~ExampleWindow();

protected:
  //Signal handlers:
  void on_button_close();

  //Child widgets:
  Gtk::VBox outer_vbox;
  Gtk::HPaned main_window_hpaned;
  Gtk::HButtonBox bottom_hbuttonbox;
  Gtk::Button button_close;
  Gtk::Button temp1;
  Gtk::Button temp2;
  Gtk::Button button_export_metadata;

  // Managing the focus order
};

#endif //GTKMM_EXAMPLEWINDOW_H
