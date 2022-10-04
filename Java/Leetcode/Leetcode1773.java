package com.company;

import java.util.ArrayList;
import java.util.List;

public class Leetcode1773 {
    public static void main(String[] args) {
        List<List<String>> items=new ArrayList<>();

        int M = 3;
//        for (int i = 0; i < M; i++)  {
//            items.add(new ArrayList<>());
//        }
//        items.add({"phone","blue","pixel"});
//        items= {{"phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"}};
//        String ruleKey = "color", ruleValue = "silver";
    }

    public static int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int a=0,c=0;
        if(ruleKey.equals("type")){
            a=0;
        } else if (ruleKey.equals("color")){
            a=1;
        } else if (ruleKey.equals("name")){
            a=2;
        }

        for (int i = 0; i < items.size(); i++) {
            if ((items.get(i)).get(a).equals(ruleValue)){
                c++;
            }
        }
        return c;
    }
}