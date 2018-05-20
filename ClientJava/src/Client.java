import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

import java.io.*;
import java.net.*;

public class Client extends Application
{
    public static void main(String args[])
    {

        System.out.println("main");

        try {
            Application.launch(args);
        } catch (Exception error)
        {
            System.err.println("--->" + error);
        }
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        System.out.println("Starting the GUI");
        FXMLLoader loader = new FXMLLoader(getClass().getResource("ClientUI.fxml"));
        BorderPane mainBox = loader.load();

        Scene scene = new Scene(mainBox);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Plan Route");
        primaryStage.show();
    }
}
