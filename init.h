GtkWidget *window;
GtkWidget *Second_window;
GtkBuilder *builder;
void Init()
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
    Radio_label1 = GTK_WIDGET(gtk_builder_get_object(builder, "Radio_Label1"));
    Radio_label2 = GTK_WIDGET(gtk_builder_get_object(builder, "Radio_Label2"));
    Radio_label3 = GTK_WIDGET(gtk_builder_get_object(builder, "Radio_Label3"));
    Radio_label4 = GTK_WIDGET(gtk_builder_get_object(builder, "Radio_Label4"));
    age = GTK_ENTRY(gtk_builder_get_object(builder, "Age"));
    Gender_select = GTK_COMBO_BOX(gtk_builder_get_object(builder, "Gender"));
    Login_box = GTK_WIDGET(gtk_builder_get_object(builder, "Login_Box"));
    Next_button = GTK_BUTTON(gtk_builder_get_object(builder, "Next_Button"));
    Previous_button = GTK_BUTTON(gtk_builder_get_object(builder, "Previous_Button"));

    Result_window = GTK_WIDGET(gtk_builder_get_object(builder, "ResultWindow"));
    Correct_label = GTK_WIDGET(gtk_builder_get_object(builder, "Correct_Label"));
    Percent_label = GTK_WIDGET(gtk_builder_get_object(builder, "Percent_Label"));
    Correctwrong = GTK_WIDGET(gtk_builder_get_object(builder, "CorrectWrong"));
    Correct_bar = GTK_PROGRESS_BAR(gtk_builder_get_object(builder, "Correct_Bar"));
}