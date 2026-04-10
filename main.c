#include <adwaita.h>

static void activate(AdwApplication *app, gpointer user_data) {
  AdwApplicationWindow *window =
      ADW_APPLICATION_WINDOW(adw_application_window_new(GTK_APPLICATION(app)));

  gtk_window_set_title(GTK_WINDOW(window), "nesnes");
  gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

  GtkWidget *label = gtk_label_new("Load a ROM");
  adw_application_window_set_content(window, label);

  gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[]) {
  AdwApplication *app =
      adw_application_new("org.nesnes.App", G_APPLICATION_DEFAULT_FLAGS);

  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  int status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);
  return status;
}
