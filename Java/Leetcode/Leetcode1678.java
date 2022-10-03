package com.company;

public class Leetcode1678 {
    public static void main(String[] args) {
        String str="G()()()()(al)";
        String answer=interpret(str);
        System.out.println(answer);
    }

    public static String interpret(String command) {
        int i=0,l=command.length();
        String updated="";
        while (i<l){
            if(command.substring(i,l).startsWith("G")){
                updated=updated+"G";
                i++;
            } else if (command.substring(i,l).startsWith("()")){
                updated=updated+"o";
                i=i+2;
            } else if (command.substring(i,l).startsWith("(al)")){
                updated=updated+"al";
                i=i+4;
            }
        }
        return updated;
    }
}
