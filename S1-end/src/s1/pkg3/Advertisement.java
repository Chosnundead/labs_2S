package s1.pkg3;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Advertisement {

    public String day;
    public int duration;
    public String reqName;
    public String reqNumber;
    public String reqBank;
    private File file;

    public Advertisement(String day, int duration, String reqName, String reqNumber, String reqBank, File file) {
        this.day = day;
        this.duration = duration;
        this.reqName = reqName;
        this.reqNumber = reqNumber;
        this.reqBank = reqBank;
        this.file = file;
    }

    public Advertisement(String day, int duration, String reqName, String reqNumber, String reqBank, File file, boolean doesCreateCarFile) throws Exception {
        this.day = day;
        this.duration = duration;
        this.reqName = reqName;
        this.reqNumber = reqNumber;
        this.reqBank = reqBank;
        this.file = file;
        if (doesCreateCarFile) {
            this._writeAdvertisementToFile();
        }
    }

    public void _writeAdvertisementToFile() throws Exception {
        try (FileWriter writer = new FileWriter(this.file, false)) {
            writer.write(this.day + "\n" + this.duration + "\n" + this.reqName + "\n" + this.reqNumber + "\n" + this.reqBank);
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
        file.mkdirs();
        file.createNewFile();
    }
}
