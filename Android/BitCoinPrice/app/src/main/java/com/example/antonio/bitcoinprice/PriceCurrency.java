package com.example.antonio.bitcoinprice;

import android.util.Log;

import org.json.JSONObject;

public class PriceCurrency {
    public static String price = "";
    public static void getPrice(JSONObject response){
        try {
            price = response.getString("last");
        }
        catch (Exception ex){
            Log.d("Beach", "Error while parsing");
        }
    }
}
