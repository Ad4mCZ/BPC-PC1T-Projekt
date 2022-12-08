GtkWidget *Statistics_window;
void on_Return_Button_clicked (GtkButton *Return_Button, GtkWidget *Main_Window){
    gtk_widget_hide(Statistics_window);
    gtk_widget_show(Main_Window);
}

