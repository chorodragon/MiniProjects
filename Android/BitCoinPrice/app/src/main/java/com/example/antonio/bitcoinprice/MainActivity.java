package com.example.antonio.bitcoinprice;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import com.loopj.android.http.AsyncHttpClient;
import com.loopj.android.http.JsonHttpResponseHandler;
import com.loopj.android.http.RequestParams;
import com.loopj.android.http.SyncHttpClient;

import org.json.JSONObject;

import java.util.ArrayList;

import cz.msebera.android.httpclient.Header;

public class MainActivity extends AppCompatActivity {

    //Constants
    final String BITAV_PRICE_URL = "https://apiv2.bitcoinaverage.com/indices/global/ticker/";
    final String BITAV_CURRENCIES_URL = "https://apiv2.bitcoinaverage.com/symbols/indices/history/global";

    //Variables
    TextView mPriceLabel;
    Spinner mSpinnerCurrency;

    Currencies mCurrencies;
    ArrayAdapter<String> pDataAdapter;

    String mPrice;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mPriceLabel = (TextView) findViewById(R.id.priceLabel);
        mSpinnerCurrency = (Spinner) findViewById(R.id.spinnerCurrency);
        mCurrencies = new Currencies(BITAV_CURRENCIES_URL);
        mPrice = "";

        mSpinnerCurrency.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                updatePrice(mSpinnerCurrency.getSelectedItem().toString());
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
                Toast.makeText(getApplicationContext(), "Nothing selected", Toast.LENGTH_SHORT).show();
            }
        });

        updateCurrencyList();

    }

    private void updatePrice(String s) {
        AsyncHttpClient client = new AsyncHttpClient();
        String url = BITAV_PRICE_URL + s + "USD";

        client.get(url, new JsonHttpResponseHandler(){
            @Override
            public void onSuccess(int statusCode, Header[] headers, JSONObject response){
                PriceCurrency.getPrice(response);
                mPriceLabel.setText("$ " + PriceCurrency.price);
            }

            @Override
            public void onFailure(int statusCode, Header[] headers, Throwable throwable, JSONObject response){
                Toast.makeText(getApplicationContext(), "Error getting the currency's price", Toast.LENGTH_SHORT).show();
                Log.d("Beach", "Code: " + statusCode);
            }
        });
    }


    public void updateCurrencyList(){
        AsyncHttpClient client = new AsyncHttpClient();
        client.get(BITAV_CURRENCIES_URL, new JsonHttpResponseHandler(){
            @Override
            public void onSuccess(int statusCode, Header[] headers, JSONObject response){
                mCurrencies.parseJson(response);
                updateSpinnerUI(mCurrencies.getpCurrencies());
                updatePrice(mSpinnerCurrency.getSelectedItem().toString());
            }

            @Override
            public void onFailure(int statusCode, Header[] headers, Throwable throwable, JSONObject response){
                Toast.makeText(getApplicationContext(), "Error getting the list of currencies", Toast.LENGTH_SHORT).show();
            }
        });
    }

    private void updateSpinnerUI(ArrayList<String> strings) {
        pDataAdapter = new ArrayAdapter<>(getApplicationContext(), R.layout.spinner_item, strings);

        pDataAdapter.setDropDownViewResource(R.layout.spinner_item);
        mSpinnerCurrency.setAdapter(pDataAdapter);
    }
}
