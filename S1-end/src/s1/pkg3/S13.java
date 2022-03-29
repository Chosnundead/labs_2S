package s1.pkg3;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class S13 {

    public static void _loadData(String pathToDir, LinkedList arr) throws Exception {
        for (int step = 0; true; step++) {
            try (FileReader read = new FileReader(pathToDir + "Data\\id" + step + ".Advertisement")) {
                Scanner scan = new Scanner(read);

                String day = null;
                int duration = 0;
                String reqName = null;
                String reqNumber = null;
                String reqBank = null;
                File file = new File(pathToDir + "Data\\id" + step + ".Advertisement");

                int counter = 0;

                while (scan.hasNextLine()) {
                    switch (counter) {
                        case 0 ->
                            day = scan.nextLine();
                        case 1 ->
                            duration = Integer.valueOf(scan.nextLine());
                        case 2 ->
                            reqName = scan.nextLine();
                        case 3 ->
                            reqNumber = scan.nextLine();
                        case 4 ->
                            reqBank = scan.nextLine();
                    }
                    counter++;
                }

                arr.add(new Advertisement(day, duration, reqName, reqNumber, reqBank, file));
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
            try (FileWriter writer = new FileWriter(pathToDir + "Data\\test.Advertisement", false)) {
                writer.write("test");
                writer.close();
            }

            String check;
            try (FileReader reader = new FileReader(pathToDir + "Data\\test.Advertisement")) {
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
            Advertisement advertisement = (Advertisement) arr.get(step);
            System.out.println("id: " + step);
            System.out.println("day: " + advertisement.day + "\t" + "duration: " + advertisement.duration);
            System.out.println("reqName: " + advertisement.reqName + "\t" + "reqNumber: " + advertisement.reqNumber + "\t" + "reqBank: " + advertisement.reqBank);
            System.out.println("\t======666======");
        }
    }

    public static void _cls() throws Exception {
        new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
    }

    public static void _addAdvertisement(String pathToDir, LinkedList arr) throws Exception {
        Scanner input = new Scanner(System.in);

        int id = arr.size();
        System.out.print("day: ");
        String day = input.nextLine();
        System.out.print("duration(int): ");
        int duration = Integer.valueOf(input.nextLine());
        System.out.print("reqName: ");
        String reqName = input.nextLine();
        System.out.print("reqNumber: ");
        String reqNumber = input.nextLine();
        System.out.print("reqBank: ");
        String reqBank = input.nextLine();
        File file = new File(pathToDir + "Data\\id" + id + ".Advertisement");
        file.createNewFile();

        arr.add(new Advertisement(day, duration, reqName, reqNumber, reqBank, file, true));
    }

    public static void _removeLastAdvertisement(LinkedList<Advertisement> arr) throws Exception {
        arr.getLast()._deleteFile();
        arr.removeLast();
    }

    public static void _removeAdvertisementByIndex(int id, LinkedList<Advertisement> arr) throws Exception {
        if ((arr.size() - 1) == id) {
            _removeLastAdvertisement(arr);
        } else if (id >= 0 && id < arr.size()) {
            arr.set(id, arr.getLast());
            _removeLastAdvertisement(arr);
        } else {
            System.out.println("Файл не удален!");
        }
    }

    public static void _sort(String pathToDir, LinkedList<Advertisement> arr) throws Exception {
        boolean typeOfSort = _typeOfSort();
        if (typeOfSort) {
            for (int stepByBubble = 0; stepByBubble < arr.size(); stepByBubble++) {
                for (int step = 0; step < (arr.size() - 1); step++) {
                    if (arr.get(step).duration > arr.get(step + 1).duration) {
                        Advertisement tempAdvertisement = arr.get(step);
                        arr.set(step, arr.get(step + 1));
                        arr.set(step + 1, tempAdvertisement);
                        _recreateFile(pathToDir, step, arr);
                        _recreateFile(pathToDir, (step + 1), arr);
                    }
                }
            }
        } else {
            for (int stepByBubble = 0; stepByBubble < arr.size(); stepByBubble++) {
                for (int step = 0; step < (arr.size() - 1); step++) {
                    if (arr.get(step).duration < arr.get(step + 1).duration) {
                        Advertisement tempAdvertisement = arr.get(step);
                        arr.set(step, arr.get(step + 1));
                        arr.set(step + 1, tempAdvertisement);
                        _recreateFile(pathToDir, step, arr);
                        _recreateFile(pathToDir, (step + 1), arr);
                    }
                }
            }
        }
    }

    public static boolean _typeOfSort() {
        boolean typeOfSort = false;
        Scanner input = new Scanner(System.in);
        boolean isContinue = false;

        do {
            System.out.println("1: Сортировать по возрастанию.");
            System.out.println("2: Сортировать по убыванию.");

            switch (input.nextInt()) {
                case 1 ->
                    typeOfSort = true;
                case 2 ->
                    typeOfSort = false;
                default ->
                    isContinue = true;
            }

        } while (isContinue);

        return typeOfSort;
    }

    public static void _showDataOfOneAdvertisement(int id, LinkedList<Advertisement> arr) {
        System.out.println("id: " + id);
        System.out.println("day: " + arr.get(id).day + "\t" + "duration: " + arr.get(id).duration);
        System.out.println("reqName: " + arr.get(id).reqName + "\t" + "reqNumber: " + arr.get(id).reqNumber + "\t" + "reqBank: " + arr.get(id).reqBank);
        System.out.println("======666======");
    }

    public static void _showDataByFilter(int numberOfFilter, LinkedList<Advertisement> arr) {
        //numberOfFilters при 1 - по подразделению, при 2 - по имени владельца
        Scanner input = new Scanner(System.in);
        String checkFor;

        switch (numberOfFilter) {
            case 1 -> {
                System.out.print("Введите день: ");
                checkFor = input.nextLine();
                for (int step = 0; step < arr.size(); step++) {
                    if (checkFor.equals(arr.get(step).day)) {
                        _showDataOfOneAdvertisement(step, arr);
                    }
                }
            }
            case 2 -> {
                System.out.print("Введите имя заказщика: ");
                checkFor = input.nextLine();
                for (int step = 0; step < arr.size(); step++) {
                    if (checkFor.equals(arr.get(step).reqName)) {
                        _showDataOfOneAdvertisement(step, arr);
                    }
                }
            }
        }
    }

    public static void _recreateFile(String pathToDir, int id, LinkedList<Advertisement> arr) throws Exception {
        arr.get(id)._replaceFile(new File(pathToDir + "Data\\id" + id + ".Advertisement"));
        arr.get(id)._writeAdvertisementToFile();
    }

    public static boolean _menu(String pathToDir, LinkedList arr) throws Exception {
        Scanner input = new Scanner(System.in);
        System.out.println("1: Отобразить базу.");
        System.out.println("2: Добавить рекламу.");
        System.out.println("3: Удалить рекламу.");
        System.out.println("4: Сортировка реклам.");
        System.out.println("5: Фильтрация реклам.");
        System.out.println("6: Поиск рекламы по индентификатору.");
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
                _addAdvertisement(pathToDir, arr);
                return true;
            }
            case 3 -> {
                _cls();
                _showData(arr);
                System.out.println("1: Удалить последнюю рекламу.");
                System.out.println("2: Удалить рекламу по идентификатору.");
                switch (input.nextInt()) {
                    case 1 -> {
                        _removeLastAdvertisement(arr);
                    }
                    case 2 -> {
                        System.out.print("Введите идентификатор для удаления: ");
                        _removeAdvertisementByIndex(input.nextInt(), arr);
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
                System.out.println("1: Фильтр по дню.");
                System.out.println("2: Фильтр по имени заказщика.");
                int numberOfFilter = input.nextInt();
                _showDataByFilter(numberOfFilter, arr);
                return true;
            }
            case 6 -> {
                _cls();
                System.out.print("Введите индентификатор рекламы для поиска: ");
                int search = input.nextInt();
                try {
                    _showDataOfOneAdvertisement(search, arr);
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

        LinkedList<Advertisement> arr = new LinkedList<>();

        _loadData(pathToDir, arr);

        _showData(arr);

        while (_menu(pathToDir, arr));
    }
}
