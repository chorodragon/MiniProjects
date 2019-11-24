package com.example.antonio.weatherapp;

import android.Manifest;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.support.annotation.NonNull;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.loopj.android.http.AsyncHttpClient;
import com.loopj.android.http.JsonHttpResponseHandler;
import com.loopj.android.http.RequestParams;

import org.json.JSONObject;

import cz.msebera.android.httpclient.Header;

public class MainActivity extends AppCompatActivity {

    //Constants
    final String WEATHER_URL = "http://api.openweathermap.org/data/2.5/weather";
    final String APP_ID = "e72ca729af228beabd5d20e3b7749713";
    final int REQUEST_CODE = 890;
    final long MIN_TIME = 5000;
    final String LOGCAT_TAG = "Clima";
    final float MIN_DISTANCE = 1000;

    String LOCATION_PROVIDER = LocationManager.GPS_PROVIDER;

    //Variables
    TextView mCityLabel;
    TextView mTemperatureLabel;
    ImageView mWeatherImage;
    ImageButton mChangeCityButton;

    LocationManager mLocationManager;
    LocationListener mLocationListener;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mCityLabel = (TextView) findViewById(R.id.locationTV);
        mTemperatureLabel = (TextView) findViewById(R.id.tempTV);
        mWeatherImage = (ImageView) findViewById(R.id.weatherSymbol);
        mChangeCityButton = (ImageButton) findViewById(R.id.changeCityButton);

        mChangeCityButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent myIntent = new Intent(MainActivity.this, ChangeCityController.class);

                startActivity(myIntent);
            }
        });
    }

    @Override
    protected void onResume() {
        super.onResume();
        Intent myIntent = getIntent();
        String city = myIntent.getStringExtra("City");

        if (city != null) {
            getWeatherForCity(city);
        } else {
            getWeatherForCurrentLocation();
        }
    }

    private void getWeatherForCity(String city){
        RequestParams params = new RequestParams();
        params.put("q", city);
        params.put("appid", APP_ID);

        getWeatherWebInfo(params);
    }

    private void getWeatherForCurrentLocation() {
        mLocationManager = (LocationManager) getSystemService(Context.LOCATION_SERVICE);
        mLocationListener = new LocationListener() {
            @Override
            public void onLocationChanged(Location location) {
                Log.d(LOGCAT_TAG, "Reached this place at least");
                String latitude = String.valueOf(location.getLatitude());
                String longitude = String.valueOf(location.getLongitude());

                RequestParams params = new RequestParams();
                params.put("lat", latitude);
                params.put("lon", longitude);
                params.put("appid", APP_ID);

                getWeatherWebInfo(params);
            }

            @Override
            public void onStatusChanged(String provider, int status, Bundle extras) {
                Log.d(LOGCAT_TAG, "onStatusChanged() callback received. Status: " + status);
                Log.d(LOGCAT_TAG, "2 means AVAILABLE, 1: TEMPORARILY_UNAVAILABLE, 0: OUT_OF_SERVICE");
            }

            @Override
            public void onProviderEnabled(String provider) {
                Log.d(LOGCAT_TAG, "onProviderEnabled() callback received. Provider: " + provider);
            }

            @Override
            public void onProviderDisabled(String provider) {
                Log.d(LOGCAT_TAG, "onProviderDisabled() callback received. Provider: " + provider);
            }
        };

        if (ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED && ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.ACCESS_FINE_LOCATION}, REQUEST_CODE);
            return;
        }
        mLocationManager.requestLocationUpdates(LOCATION_PROVIDER, MIN_TIME, MIN_DISTANCE, mLocationListener);
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);

        if (requestCode == REQUEST_CODE){
            if(grantResults.length > 0&& grantResults[0] == PackageManager.PERMISSION_GRANTED){
                Log.d("Request Location", "Result granted");
                getWeatherForCurrentLocation();
            }
            else{
                Log.d("Request Location", "Denied");
            }
        }
    }

    private void getWeatherWebInfo(RequestParams params){
        AsyncHttpClient client = new AsyncHttpClient();

        client.get(WEATHER_URL, params, new JsonHttpResponseHandler(){
            @Override
            public void onSuccess(int statusCode, Header[] headers, JSONObject response){
                Log.d("Clima2", "Success: " + response.toString());
                WeatherDataModel model = WeatherDataModel.fromJson(response);

                updateUI(model);
            }

            @Override
            public void onFailure(int statusCode, Header[] headers, Throwable e, JSONObject response){
                Toast.makeText(MainActivity.this, "Request Failed", Toast.LENGTH_SHORT).show();
            }
        });
    }

    private void updateUI(WeatherDataModel weather){
        mCityLabel.setText(weather.getmCity());
        mTemperatureLabel.setText(weather.getmTemperature());

        int resourceId = getResources().getIdentifier(weather.getmIconName(), "drawable", getPackageName());

        mWeatherImage.setImageResource(resourceId);
    }

    @Override
    public void onPause(){
        super.onPause();

        if (mLocationManager != null)
            mLocationManager.removeUpdates(mLocationListener);

    }
}
