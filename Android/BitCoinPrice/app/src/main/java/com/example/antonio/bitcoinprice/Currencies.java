package com.example.antonio.bitcoinprice;

import android.util.Log;

import org.json.JSONArray;
import org.json.JSONObject;

import java.util.ArrayList;


public class Currencies {

//    private String[] pCurrencies;
    private ArrayList<String> pCurrencies;
    private String url;

    public Currencies(String url){
        this.url = url;
        pCurrencies = new ArrayList<>();
    }


    public ArrayList<String> getpCurrencies(){
        return pCurrencies;
    }

    public void parseJson(JSONObject jsonObject){
        String temp;
        try{
            JSONArray jsonArray = jsonObject.getJSONArray("symbols");
            for (int i = 0; i < jsonArray.length(); i++){
                temp = jsonArray.getString(i).substring(0, 3);
                pCurrencies.add(temp);
            }
        }
        catch (Exception ex){
            Log.d("Parsing", "Error when parsing json");
        }

    }

}
