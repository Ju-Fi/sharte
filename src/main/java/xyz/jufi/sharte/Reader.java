package xyz.jufi.sharte;

import java.util.Scanner;

public class Reader {
  public static String read(Scanner input) {
    return input.useDelimiter("\\Z").next();
  }
}
