import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TextArea;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.StringTokenizer;

public class Controller
{
    @FXML
    public ComboBox<String> cmbCities;
    public Button btnCalcPath, btnExit;
    public TextArea txtAreaRoute;
    private String userInput;
    private PrintWriter out;
    private Socket firstSocket;
    private BufferedReader in, stdIn;

    public void initialize()
    {
        System.out.println("controller");
        String ip = "127.0.0.1";
        int port = 61234;


        try
        {
            firstSocket = new Socket(ip, port);
            System.out.println("Socket created");

            System.out.println("getting cities from server");
            in = new BufferedReader(new InputStreamReader(firstSocket.getInputStream()));
//            stdIn = new BufferedReader(new InputStreamReader(System.in));
//            String s = null;
//            while ((s = stdIn.readLine()) != null)
//                System.out.println(s);
            String cityList = in.readLine();
            StringTokenizer cityListToken = new StringTokenizer(cityList, ";");
            ObservableList<String> cityOptions = FXCollections.observableArrayList();
            while (cityListToken.hasMoreTokens())
                cityOptions.add(cityListToken.nextToken());
            cmbCities.setItems(cityOptions);

        } catch (Exception error)
        {
            System.err.println("Error" + error);
            System.exit(1);
        }

        btnCalcPath.setOnAction((ActionEvent event) ->
        {
            try
            {
                userInput = txtAreaRoute.getText();
                out = new PrintWriter(firstSocket.getOutputStream(), true);
                // in = new BufferedReader(new InputStreamReader(firstSocket.getInputStream()));
                // stdIn = new BufferedReader(new InputStreamReader(System.in));
                out.println(userInput);
            } catch (IOException e)
            {
                System.err.println("Error " + e);
            }


        });

        btnExit.setOnAction((ActionEvent event) ->
        {
            try
            {
                in.close();
                firstSocket.close();
                System.exit(0);
            } catch (Exception e)
            {
                System.err.println("Error " + e);
            }
        });


//            while ((userInput = stdIn.readLine()) != null)
//            {
//                out.println(userInput);
//                System.out.println("received: " + in.readLine());
//            }
//
//            in.close();
//            stdIn.close();
//            firstSocket.close();


    }
}
