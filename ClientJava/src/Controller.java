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
 * <li>
 * https://examples.javacodegeeks.com/desktop-java/javafx/javafx-concurrency-example/
 * </li>
 * <li>
 * http://tutorials.jenkov.com/javafx/combobox.html
 * </li>
 * <li>
 * https://docs.oracle.com/javafx/2/ui_controls/progress.htm
 * </li>
 * </ul>
 */
public class Controller implements Initializable
{
    @FXML
    private ComboBox<String> cmbCities;
    @FXML
    private Button btnCalculate, btnClear;
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

            resetCalc();

        }
        catch (Exception error)
        {
            System.err.println("Error" + error);
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error");
            alert.setHeaderText("Error connecting to the server :(");
            alert.setContentText("Check if the server is online and try again...");
            alert.showAndWait();
            System.exit(1);
        }

        btnCalculate.setOnAction(event -> calcPath());
        btnClear.setOnAction(event -> resetCalc());

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
        if (cmbCities.getValue().equals(""))
            return;

        // progress indicator
        prgLoading.setProgress(-1.0);
        prgLoading.setVisible(true);
        cmbCities.setDisable(true);
        btnCalculate.setDisable(true);

        // create new runnable (listening for solution from the server)
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
        ObservableList<String> cities = FXCollections.observableArrayList();
        boolean isComplete = false;
        while (!isComplete)
        {
            // wait to receive the calculated route and path cost
            try
            {
                //calculated route
                System.out.println("waiting to receive the route");
                routeString = in.readLine();
                System.out.println("route received! " + routeString);

                if (routeString.substring(routeString.length()-3,routeString.length()).equals("END"))
                {
                    System.out.println("entrei aqui!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                    isComplete = true;
                    Platform.runLater(() ->
                            prgLoading.setProgress(1.0)
                    );
                }

                if (!isComplete)
                {
                    listRoute.getItems().clear();

                    StringTokenizer tokenizer = new StringTokenizer(routeString, ";");
                    while (tokenizer.hasMoreTokens())
                        cities.add(tokenizer.nextToken());

                    // path cost
                    System.out.println("waiting to receive the cost");
                    routeCost = in.readLine();
                    System.out.println("cost received " + routeCost);
                }


            }
            catch (IOException e)
            {
                System.out.println("Error reading string from server\n");
                e.printStackTrace();
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Connection Error");
                alert.setHeaderText("Error reading information from server");
                alert.showAndWait();
            }


            // Update the UI on the JavaFX Application Thread
            Platform.runLater(() ->
            {
                listRoute.setItems(cities);
                lblDistance.setText(routeCost);
//                prgLoading.setProgress(1.0);
//                cmbCities.setDisable(false);
//                btnCalculate.setDisable(false);
            });

        }

//        prgLoading.setProgress(1.0);
//        cmbCities.setDisable(false);
//        btnCalculate.setDisable(false);
        System.out.println("Exiting task that update the city list");

    }

    private void resetCalc()
    {
        prgLoading.setVisible(false);
        cmbCities.setDisable(false);
        cmbCities.setValue("");
        btnCalculate.setDisable(false);
        listRoute.getItems().clear();
        lblDistance.setText("");
        lblStartCity.setText("");
    }


    public String toString()
    {
        String ret = "";

        return ret;
    }

    public boolean equals(Object obj) {
        if (obj == null)
            return false;

        if (this != obj)
            return false;

        if (this.getClass() != obj.getClass())
            return false;

        // cast
        Controller c = (Controller) obj;

        for (int i = 0; i < cmbCities.getItems().size(); i++)
            if (!this.cmbCities.getItems().get(i).equals(c.cmbCities.getItems().get(i)))
                return false;

        for (int i = 0; i < listRoute.getItems().size(); i++)
            if (!this.listRoute.getItems().get(i).equals(c.listRoute.getItems().get(i)))
                return false;

        return true;
    }

    public int hashCode()
    {
        int ret = 304;

        return ret;
    }

}

