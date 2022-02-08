package s1;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class S1 {

    public static void _loadData(String pathToDir, LinkedList arr) throws Exception {
        for (int step = 0; true; step++) {
            try (FileReader read = new FileReader(pathToDir + "\\Data\\id" + step + ".Car")) {
                Scanner scan = new Scanner(read);

                String type = "???";
                String numberOfTheCar = "???";
                int year = 0;
                int garage = 0;
                String subdivision = "???";
                String nameOfTheCarOwner = "???";
                ArrayList<String> permits = new ArrayList<>();
                File file = new File(pathToDir + "\\Data\\id" + step + ".Car");

                int counter = 0;
                while (scan.hasNextLine()) {
                    switch (counter) {
                        case 0 ->
                            type = scan.nextLine();
                        case 1 ->
                            numberOfTheCar = scan.nextLine();
                        case 2 ->
                            year = Integer.valueOf(scan.nextLine());
                        case 3 ->
                            garage = Integer.valueOf(scan.nextLine());
                        case 4 ->
                            subdivision = scan.nextLine();
                        case 5 ->
                            nameOfTheCarOwner = scan.nextLine();
                        default -> {
                            permits.add(scan.nextLine());
                        }
                    }
                    counter++;
                }

                arr.add(new Car(type, numberOfTheCar, year, garage, subdivision, nameOfTheCarOwner, permits, file));

                read.close();

            } catch (IOException error) {
                break;
            }
        }
    }

    public static String _testOrCreatePath() throws Exception {
        String pathToDir = "";
        boolean isTested = false;

        //create
        try (FileReader reader = new FileReader("AppData\\Local\\S1\\PATH.txt")) {
            Scanner scan = new Scanner(reader);

            while (scan.hasNextLine()) {
                pathToDir += scan.nextLine();
            }
            reader.close();
            if ("".equals(pathToDir) || " ".equals(pathToDir) || "\n".equals(pathToDir) || " \n".equals(pathToDir)) {
                pathToDir = "AppData\\Local\\S1";
                try (FileWriter writer = new FileWriter("AppData\\Local\\S1\\PATH.txt", false)) {
                    writer.write(pathToDir);
                    writer.close();
                }
            }
        } catch (IOException error) {
            System.out.println("Ошибка:\n" + error.getMessage());

            File dir = new File("AppData\\Local\\S1");
            dir.mkdirs();
            try (FileWriter writer = new FileWriter("AppData\\Local\\S1\\PATH.txt", false)) {

                System.out.print("Введите абсолютный путь до папки с программой: ");
                Scanner input = new Scanner(System.in);
                pathToDir = input.nextLine();

                if ("".equals(pathToDir) || " ".equals(pathToDir) || "\n".equals(pathToDir) || " \n".equals(pathToDir)) {
                    pathToDir = "AppData\\Local\\S1";
                }
                writer.write(pathToDir);
                writer.close();
            }
        }

        //test
        try {
            File dir = new File(pathToDir + "\\Data");
            dir.mkdirs();
            try (FileWriter writer = new FileWriter(pathToDir + "\\Data\\test.Car", false)) {
                writer.write("test");
                writer.close();
            }

            String check;
            try (FileReader reader = new FileReader(pathToDir + "\\Data\\test.Car")) {
                Scanner scan = new Scanner(reader);
                check = "";
                while (scan.hasNextLine()) {
                    check += scan.nextLine();
                }
                reader.close();
            }
            if ("test".equals(check)) {
                isTested = true;
            }
        } catch (IOException error) {
            System.out.println("Ошибка:\n" + error.getMessage());
            return _testOrCreatePath();
        }

        if (isTested) {
            return pathToDir;
        } else {
            return _testOrCreatePath();

        }
    }

    public static void _showData(LinkedList arr) {
        for (int step = 0; step < arr.size(); step++) {
            Car car = (Car) arr.get(step);
            System.out.println("id: " + step);
            System.out.println("type: " + car.type + "\t" + "numberOfTheCar: " + car.numberOfTheCar);
            System.out.println("year: " + car.year + "\t" + "garage: " + car.garage);
            System.out.println("subdivision: " + car.subdivision + "\t" + "nameOfTheCarOwner: " + car.nameOfTheCarOwner);
            System.out.println("permits:");
            for (int permitsStep = 0; permitsStep < car.permits.size(); permitsStep++) {
                System.out.println(car.permits.get(permitsStep));
            }
            System.out.println("\t======666======");
        }
    }

    public static void _cls() throws Exception {
        new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
    }

    public static void _addCar(LinkedList arr) throws Exception {
        Scanner input = new Scanner(System.in);

        int id = arr.size();
        System.out.print("type(String): ");
        String type = input.nextLine();
        System.out.print("numberOfTheCar(String): ");
        String numberOfTheCar = input.nextLine();
        System.out.print("year: ");
        int year = input.nextInt();
        System.out.print("garage: ");
        int garage = input.nextInt();
        System.out.print("subdivision: ");
        String subdivision = input.nextLine();
        System.out.print("nameOfTheCarOwner: ");
        String nameOfTheCarOwner = input.nextLine();
        ArrayList<String> permits = new ArrayList<>();
        boolean isFirstTry = true;
        for (String oneOfPermits = "start"; !("".equals(oneOfPermits) || " ".equals(oneOfPermits) || "\n".equals(oneOfPermits) || " \n".equals(oneOfPermits));) {
            if (!(isFirstTry)) {
                permits.add(oneOfPermits);
            }
            oneOfPermits = input.nextLine();
            isFirstTry = false;
        }

    }

    public static boolean _menu(LinkedList arr) throws Exception {
        Scanner input = new Scanner(System.in);
        System.out.println("1: Отобразить базу.");
        System.out.println("2: Добавить машину.");
        System.out.println("0: Выход из программы.");
        int choice = input.nextInt();
        switch (choice) {
            case 0 -> {
                return false;
            }
            case 1 -> {
                _cls();
                _showData(arr);
                return true;
            }
            case 2 -> {
                _cls();
                _addCar(arr);
                return true;
            }
            default -> {
                _cls();
                return true;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        String pathToDir = _testOrCreatePath();

        LinkedList<Car> arr = new LinkedList<>();

        _loadData(pathToDir, arr);

        _showData(arr);

        while (_menu(arr));
    }
}
