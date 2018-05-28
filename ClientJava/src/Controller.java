import javafx.application.Platform;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.StringTokenizer;

/**
 * Sources:
 * <ul>
 *     <li>
 *         https://examples.javacodegeeks.com/desktop-java/javafx/javafx-concurrency-example/
 *     </li>
 *     <li>
 *         http://tutorials.jenkov.com/javafx/combobox.html
 *     </li>
 *     <li>
 *         https://docs.oracle.com/javafx/2/ui_controls/progress.htm
 *     </li>
 * </ul>
 *
 */
public class Controller implements Initializable
{
    @FXML
    private ComboBox<String> cmbCities;
    @FXML
    private Button btnCalculate;
    @FXML
    private Label lblStartCity, lblDistance;
    @FXML
    private ListView<String> listRoute;
    @FXML
    private ProgressIndicator prgLoading;

    private PrintWriter out;
    private Socket firstSocket;
    private BufferedReader in;
    private String routeString, routeCost;

    @Override
    public void initialize(URL location, ResourceBundle resources)
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
            String cityList = in.readLine();
            StringTokenizer cityListToken = new StringTokenizer(cityList, ";");
            ObservableList<String> cityOptions = FXCollections.observableArrayList();
            while (cityListToken.hasMoreTokens())
                cityOptions.add(cityListToken.nextToken());
            cmbCities.setItems(cityOptions);
            System.out.println("Finished to getting all the cities");

            lblStartCity.setText("");
            lblDistance.setText("");
            prgLoading.setVisible(false);


        }
        catch (Exception error)
        {
            System.err.println("Error" + error);
            System.exit(1);
        }

        btnCalculate.setOnAction(event -> calcPath());

//        btnExit.setOnAction((ActionEvent event) ->
//        {
//            try
//            {
//                in.close();
//                firstSocket.close();
//                System.exit(0);
//            } catch (Exception e)
//            {
//                System.err.println("Error " + e);
//            }
//        });


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

    private void calcPath()
    {
        // progress indicator
        prgLoading.setProgress(-1.0);
        prgLoading.setVisible(true);
        cmbCities.setDisable(true);
        btnCalculate.setDisable(true);

        // create new runnable
        Runnable task = this::runTask;

        // run the task on the background thread
        Thread thread = new Thread(task);
        thread.setDaemon(true);
        thread.start();


        try
        {
            String cityInput = cmbCities.getValue();
            out = new PrintWriter(firstSocket.getOutputStream(), true);
            out.println(cityInput);
            lblStartCity.setText(cityInput);

        }
        catch (IOException e)
        {
            System.err.println("Error calculating path" + e);
        }
    }

    private void runTask()
    {
        // wait to receive the calculated route and path cost
        try
        {
            //calculated route
            routeString = in.readLine();
            // path cost
            routeCost = in.readLine();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }


        // Update the UI on the JavaFX Application Thread
        Platform.runLater(() ->
        {
            StringTokenizer tokenizer     = new StringTokenizer(routeString, ";");
            ObservableList<String> cities = FXCollections.observableArrayList();
            while (tokenizer.hasMoreTokens())
                cities.add(tokenizer.nextToken());

            listRoute.setItems(cities);
            lblDistance.setText(routeCost);
            prgLoading.setProgress(1.0);
            cmbCities.setDisable(false);
            btnCalculate.setDisable(false);
        });
    }

}
