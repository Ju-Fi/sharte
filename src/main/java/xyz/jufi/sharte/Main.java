package xyz.jufi.sharte;

import java.io.StringReader;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import xyz.jufi.sharte.Reader;

public class Main
{
    public static void main(String[] args)
    {
        var input = new Scanner(System.in);
        Printer.print(Evaluator.eval(Reader.read(input)));
    }
}
