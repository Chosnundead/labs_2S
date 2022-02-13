package s1;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class S1 {

    public static void _loadData(String pathToDir, LinkedList arr) throws Exception {
        for (int step = 0; true; step++) {
            try (FileReader read = new FileReader(pathToDir + "Data\\id" + step + ".Car")) {
                Scanner scan = new Scanner(read);

                String type = "???";
                String numberOfTheCar = "???";
                int year = 0;
                int garage = 0;
                String subdivision = "???";
                String nameOfTheCarOwner = "???";
                ArrayList<String> permits = new ArrayList<>();
                File file = new File(pathToDir + "Data\\id" + step + ".Car");

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
        try (FileReader reader = new FileReader("PATH.txt")) {
            Scanner scan = new Scanner(reader);

            while (scan.hasNextLine()) {
                pathToDir += scan.nextLine();
            }
            reader.close();
            if ("".equals(pathToDir) || " ".equals(pathToDir) || "\n".equals(pathToDir) || " \n".equals(pathToDir)) {
                pathToDir = "";
                try (FileWriter writer = new FileWriter("PATH.txt", false)) {
                    writer.write(pathToDir);
                    writer.close();
                }
            }
        } catch (IOException error) {
            System.out.println("Ошибка:\n" + error.getMessage());

            try (FileWriter writer = new FileWriter("PATH.txt", false)) {

                System.out.print("Введите абсолютный путь до папки с программой: ");
                Scanner input = new Scanner(System.in);
                pathToDir = input.nextLine();

                if ("".equals(pathToDir) || " ".equals(pathToDir) || "\n".equals(pathToDir) || " \n".equals(pathToDir)) {
                    pathToDir = "";
                }
                writer.write(pathToDir);
                writer.close();
            }
        }

        //test
        try {
            File dir = new File(pathToDir + "Data");
            dir.mkdirs();
            try (FileWriter writer = new FileWriter(pathToDir + "Data\\test.Car", false)) {
                writer.write("test");
                writer.close();
            }

            String check;
            try (FileReader reader = new FileReader(pathToDir + "Data\\test.Car")) {
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

    public static void _addCar(String pathToDir, LinkedList arr) throws Exception {
        Scanner input = new Scanner(System.in);

        int id = arr.size();
        System.out.print("type(String): ");
        String type = input.nextLine();
        System.out.print("numberOfTheCar(String): ");
        String numberOfTheCar = input.nextLine();
        System.out.print("year(Integer): ");
        int year = Integer.valueOf(input.nextLine());
        System.out.print("garage(Integer): ");
        int garage = Integer.valueOf(input.nextLine());
        System.out.print("subdivision(String): ");
        String subdivision = input.nextLine();
        System.out.print("nameOfTheCarOwner(String): ");
        String nameOfTheCarOwner = input.nextLine();

        ArrayList<String> permits = new ArrayList<>();
        boolean isFirstTry = true;
        for (String oneOfPermits = "start"; !("".equals(oneOfPermits) || " ".equals(oneOfPermits) || "\n".equals(oneOfPermits) || " \n".equals(oneOfPermits));) {
            if (!(isFirstTry)) {
                permits.add(oneOfPermits);
            } else {
                System.out.print("permits(Strings):\n");
            }
            oneOfPermits = input.nextLine();
            isFirstTry = false;
        }
        File file = new File(pathToDir + "Data\\id" + id + ".Car");
        file.createNewFile();

        arr.add(new Car(type, numberOfTheCar, year, garage, subdivision, nameOfTheCarOwner, permits, file, true));
    }

    public static void _removeLastCar(LinkedList<Car> arr) throws Exception {
        arr.getLast()._deleteFile();
        arr.removeLast();
    }

    public static void _removeCarByIndex(int id, LinkedList<Car> arr) throws Exception {
        if ((arr.size() - 1) == id) {
            _removeLastCar(arr);
        } else if (id >= 0 && id < arr.size()) {
            arr.set(id, arr.getLast());
            _removeLastCar(arr);
        } else {
            System.out.println("Файл не удален!");
        }
    }

    public static void _sort(String pathToDir, LinkedList<Car> arr) throws Exception {
        boolean[] typeOfSort = _typeOfSort();
        if (typeOfSort[0] && typeOfSort[1]) {
            for (int stepByBubble = 0; stepByBubble < arr.size(); stepByBubble++) {
                for (int step = 0; step < (arr.size() - 1); step++) {
                    if (arr.get(step).year > arr.get(step + 1).year) {
                        Car tempCar = arr.get(step);
                        arr.set(step, arr.get(step + 1));
                        arr.set(step + 1, tempCar);
                        _recreateFile(pathToDir, step, arr);
                        _recreateFile(pathToDir, (step + 1), arr);
                    }
                }
            }
        } else if (typeOfSort[0] && (!typeOfSort[1])) {
            for (int stepByBubble = 0; stepByBubble < arr.size(); stepByBubble++) {
                for (int step = 0; step < (arr.size() - 1); step++) {
                    if (arr.get(step).year < arr.get(step + 1).year) {
                        Car tempCar = arr.get(step);
                        arr.set(step, arr.get(step + 1));
                        arr.set(step + 1, tempCar);
                        _recreateFile(pathToDir, step, arr);
                        _recreateFile(pathToDir, (step + 1), arr);
                    }
                }
            }
        } else if ((!typeOfSort[0]) && typeOfSort[1]) {
            for (int stepByBubble = 0; stepByBubble < arr.size(); stepByBubble++) {
                for (int step = 0; step < (arr.size() - 1); step++) {
                    if (arr.get(step).garage > arr.get(step + 1).garage) {
                        Car tempCar = arr.get(step);
                        arr.set(step, arr.get(step + 1));
                        arr.set(step + 1, tempCar);
                        _recreateFile(pathToDir, step, arr);
                        _recreateFile(pathToDir, (step + 1), arr);
                    }
                }
            }
        } else if ((!typeOfSort[0]) && (!typeOfSort[1])) {
            for (int stepByBubble = 0; stepByBubble < arr.size(); stepByBubble++) {
                for (int step = 0; step < (arr.size() - 1); step++) {
                    if (arr.get(step).garage < arr.get(step + 1).garage) {
                        Car tempCar = arr.get(step);
                        arr.set(step, arr.get(step + 1));
                        arr.set(step + 1, tempCar);
                        _recreateFile(pathToDir, step, arr);
                        _recreateFile(pathToDir, (step + 1), arr);
                    }
                }
            }
        }
    }

    public static boolean[] _typeOfSort() {
        boolean[] typeOfSort = new boolean[2];
        Scanner input = new Scanner(System.in);
        boolean isContinue = false;

        do {
            System.out.println("1: Сортировать по году.");
            System.out.println("2: Сортировать по гаражу.");

            switch (input.nextInt()) {
                case 1 -> {
                    System.out.println("1: Сортировать по возрастанию.");
                    System.out.println("2: Сортировать по убыванию.");
                    switch (input.nextInt()) {
                        case 1 -> {
                            typeOfSort[0] = true;
                            typeOfSort[1] = true;
                            isContinue = false;
                        }
                        case 2 -> {
                            typeOfSort[0] = true;
                            typeOfSort[1] = false;
                            isContinue = false;
                        }
                        default -> {
                            isContinue = true;
                        }
                    }
                }
                case 2 -> {
                    System.out.println("1: Сортировать по возрастанию.");
                    System.out.println("2: Сортировать по убыванию.");
                    switch (input.nextInt()) {
                        case 1 -> {
                            typeOfSort[0] = false;
                            typeOfSort[1] = true;
                            isContinue = false;
                        }
                        case 2 -> {
                            typeOfSort[0] = false;
                            typeOfSort[1] = false;
                            isContinue = false;
                        }
                        default -> {
                            isContinue = true;
                        }
                    }
                }
                default ->
                    isContinue = true;
            }
        } while (isContinue);

        return typeOfSort;
    }

    public static void _showDataOfOneCar(int id, LinkedList<Car> arr) {
        System.out.println("id: " + id);
        System.out.println("type: " + arr.get(id).type + "\t" + "numberOfTheCar: " + arr.get(id).numberOfTheCar);
        System.out.println("year: " + arr.get(id).year + "\t" + "garage: " + arr.get(id).garage);
        System.out.println("subdivision: " + arr.get(id).subdivision + "\t" + "nameOfTheCarOwner: " + arr.get(id).nameOfTheCarOwner);
        System.out.println("permits:");
        for (int permitsStep = 0; permitsStep < arr.get(id).permits.size(); permitsStep++) {
            System.out.println(arr.get(id).permits.get(permitsStep));
        }
        System.out.println("======666======");
    }

    public static void _showDataByFilter(int numberOfFilter, LinkedList<Car> arr) {
        //numberOfFilters при 1 - по подразделению, при 2 - по имени владельца
        Scanner input = new Scanner(System.in);
        String checkFor;

        switch (numberOfFilter) {
            case 1 -> {
                System.out.print("Введите название подразделения: ");
                checkFor = input.nextLine();
                for (int step = 0; step < arr.size(); step++) {
                    if (checkFor.equals(arr.get(step).subdivision)) {
                        _showDataOfOneCar(step, arr);
                    }
                }
            }
            case 2 -> {
                System.out.print("Введите имя владельца машины: ");
                checkFor = input.nextLine();
                for (int step = 0; step < arr.size(); step++) {
                    if (checkFor.equals(arr.get(step).nameOfTheCarOwner)) {
                        _showDataOfOneCar(step, arr);
                    }
                }
            }
        }
    }

    public static void _recreateFile(String pathToDir, int id, LinkedList<Car> arr) throws Exception {
        arr.get(id)._replaceFile(new File(pathToDir + "Data\\id" + id + ".Car"));
        arr.get(id)._writeCarToFile();
    }

    public static boolean _menu(String pathToDir, LinkedList arr) throws Exception {
        Scanner input = new Scanner(System.in);
        System.out.println("1: Отобразить базу.");
        System.out.println("2: Добавить машину.");
        System.out.println("3: Удалить машину.");
        System.out.println("4: Сортировка машин.");
        System.out.println("5: Фильтрация машин.");
        System.out.println("6: Поиск машины по индентификатору.");
        System.out.println("0: Выход из программы.");
        switch (input.nextInt()) {
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
                _addCar(pathToDir, arr);
                return true;
            }
            case 3 -> {
                _cls();
                _showData(arr);
                System.out.println("1: Удалить последнюю машину.");
                System.out.println("2: Удалить машину по идентификатору.");
                switch (input.nextInt()) {
                    case 1 -> {
                        _removeLastCar(arr);
                    }
                    case 2 -> {
                        System.out.print("Введите идентификатор для удаления: ");
                        _removeCarByIndex(input.nextInt(), arr);
                    }
                }
                return true;
            }
            case 4 -> {
                _cls();
                _sort(pathToDir, arr);
                return true;
            }
            case 5 -> {
                _cls();
                System.out.println("1: Фильтр по подразделению.");
                System.out.println("2: Фильтр по имени владельца.");
                int numberOfFilter = input.nextInt();
                _showDataByFilter(numberOfFilter, arr);
                return true;
            }
            case 6 -> {
                _cls();
                System.out.print("Введите индентификатор машины для поиска: ");
                int search = input.nextInt();
                try {
                    _showDataOfOneCar(search, arr);
                } catch (Exception error) {
                    System.out.println("Ошибка:\n" + error.getMessage());
                }
                return true;
            }
            default -> {
                _cls();
                return true;
            }
        }
    }

    @SuppressWarnings("empty-statement")
    public static void main(String[] args) throws Exception {
        String pathToDir = _testOrCreatePath();

        LinkedList<Car> arr = new LinkedList<>();

        _loadData(pathToDir, arr);

        _showData(arr);

        while (_menu(pathToDir, arr));
    }
}
