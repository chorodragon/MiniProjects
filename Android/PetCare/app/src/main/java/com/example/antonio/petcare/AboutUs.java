package com.example.antonio.petcare;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;

public class AboutUs extends AppCompatActivity {

    //Variables
    private Toolbar mToolbar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_about_us);

        mToolbar = (Toolbar) findViewById(R.id.navigationBar);
        setSupportActionBar(mToolbar);
        getSupportActionBar().setTitle(R.string.nav_about);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.toolbar_menu, menu);
        return super.onCreateOptionsMenu(menu);
    }


    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        Intent intent;
        switch (item.getItemId()){
            case R.id.nav_settings:
                intent = new Intent(this, Settings.class);
                startActivity(intent);
                finish();
                break;
            case R.id.nav_about:
                break;
        }

        return true;
    }
}
