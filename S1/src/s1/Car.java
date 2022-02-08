package s1;

import java.io.File;
import java.util.ArrayList;

public class Car {

    public String type;
    public String numberOfTheCar;
    public int year;
    public int garage;
    public String subdivision;
    public String nameOfTheCarOwner;
    public ArrayList<String> permits;
    private File file;

    public Car(String type, String numberOfTheCar, int year, int garage, String subdivision, String nameOfTheCarOwner, ArrayList permits, File file) {
        this.type = type;
        this.numberOfTheCar = numberOfTheCar;
        this.year = year;
        this.garage = garage;
        this.subdivision = subdivision;
        this.nameOfTheCarOwner = nameOfTheCarOwner;
        this.permits = permits;
        this.file = file;
    }
}
