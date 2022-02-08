package s1;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
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

    public Car(String type, String numberOfTheCar, int year, int garage, String subdivision, String nameOfTheCarOwner, ArrayList permits, File file, boolean doesCreateCarFile) throws Exception {
        this.type = type;
        this.numberOfTheCar = numberOfTheCar;
        this.year = year;
        this.garage = garage;
        this.subdivision = subdivision;
        this.nameOfTheCarOwner = nameOfTheCarOwner;
        this.permits = permits;
        this.file = file;
        if (doesCreateCarFile) {
            this._writeCarToFile();
        }
    }

    public void _writeCarToFile() throws Exception {
        try (FileWriter writer = new FileWriter(this.file, false)) {
            writer.write(this.type + "\n" + this.numberOfTheCar + "\n" + this.year + "\n" + this.garage + "\n" + this.subdivision + "\n" + this.nameOfTheCarOwner);
            for (int step = 0; step < this.permits.size(); step++) {
                writer.write("\n" + this.permits.get(step));
            }
            writer.close();
        } catch (IOException error) {
            System.out.println("Ошибка:\n" + error.getMessage());
        }
    }

    public void _deleteFile() throws Exception {
        this.file.delete();
    }

    public void _replaceFile(File file) throws Exception {
        this.file = file;
    }
}
