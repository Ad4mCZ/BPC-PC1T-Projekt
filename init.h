GtkWidget *window;
GtkWidget *Second_window;
GtkWidget *Third_window;
GtkWidget *Fourth_window;
GtkBuilder *builder;
void Init() // inicializace prommenych pomoci builderu
{
    window = GTK_WIDGET(gtk_builder_get_object(builder, "Main_Window"));
    Family_name = GTK_ENTRY(gtk_builder_get_object(builder, "Family_Name"));
    Given_name = GTK_ENTRY(gtk_builder_get_object(builder, "Given_Name"));
    Confirm_button = GTK_WIDGET(gtk_builder_get_object(builder, "Confirm_Button"));
    Test_select = GTK_COMBO_BOX(gtk_builder_get_object(builder, "Test_Select"));
    Second_window = GTK_WIDGET(gtk_builder_get_object(builder, "Second_Window"));
    Radio1 = GTK_WIDGET(gtk_builder_get_object(builder, "radio1"));
    Radio2 = GTK_WIDGET(gtk_builder_get_object(builder, "radio2"));
    Radio3 = GTK_WIDGET(gtk_builder_get_object(builder, "radio3"));
    Radio4 = GTK_WIDGET(gtk_builder_get_object(builder, "radio4"));
    Otazka_label = GTK_WIDGET(gtk_builder_get_object(builder, "Otazka_Label"));
    Otazka_label_2 = GTK_WIDGET(gtk_builder_get_object(builder, "Otazka_Label_2"));
    Otazka_label_3 = GTK_WIDGET(gtk_builder_get_object(builder, "Otazka_Label_3"));

    Radio_label1 = GTK_WIDGET(gtk_builder_get_object(builder, "Radio_Label1"));
    Radio_label2 = GTK_WIDGET(gtk_builder_get_object(builder, "Radio_Label2"));
    Radio_label3 = GTK_WIDGET(gtk_builder_get_object(builder, "Radio_Label3"));
    Radio_label4 = GTK_WIDGET(gtk_builder_get_object(builder, "Radio_Label4"));
    age = GTK_ENTRY(gtk_builder_get_object(builder, "Age"));
    Gender_select = GTK_COMBO_BOX(gtk_builder_get_object(builder, "Gender"));
    Login_box = GTK_WIDGET(gtk_builder_get_object(builder, "Login_Box"));
    Next_button = GTK_BUTTON(gtk_builder_get_object(builder, "Next_Button"));
    Next_button_2 = GTK_BUTTON(gtk_builder_get_object(builder, "Next_Button_2"));
    Next_button_3 = GTK_BUTTON(gtk_builder_get_object(builder, "Next_Button_3"));
    Previous_button = GTK_BUTTON(gtk_builder_get_object(builder, "Previous_Button"));
    Previous_button_2 = GTK_BUTTON(gtk_builder_get_object(builder, "Previous_Button_2"));
    Previous_button_3 = GTK_BUTTON(gtk_builder_get_object(builder, "Previous_Button_3"));
    Result_window = GTK_WIDGET(gtk_builder_get_object(builder, "ResultWindow"));
    Correct_label = GTK_WIDGET(gtk_builder_get_object(builder, "Correct_Label"));
    Percent_label = GTK_WIDGET(gtk_builder_get_object(builder, "Percent_Label"));
    Correctwrong = GTK_WIDGET(gtk_builder_get_object(builder, "CorrectWrong"));
    Correct_bar = GTK_PROGRESS_BAR(gtk_builder_get_object(builder, "Correct_Bar"));
    Third_window = GTK_WIDGET(gtk_builder_get_object(builder, "Third_Window"));
    Fourth_window = GTK_WIDGET(gtk_builder_get_object(builder, "Fourth_Window"));
    odpovedi_2 = GTK_COMBO_BOX(gtk_builder_get_object(builder, "Odpovedi_2"));
    odpovedi_3 = GTK_ENTRY(gtk_builder_get_object(builder, "fourth_entry"));
    // repeat_button = GTK_BUTTON(gtk_builder_get_object(builder), "Repeat_button");
    Statistics_window = GTK_WIDGET(gtk_builder_get_object(builder, "Statistics_Window"));
}