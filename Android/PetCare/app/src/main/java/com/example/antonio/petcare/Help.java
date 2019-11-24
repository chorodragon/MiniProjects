package com.example.antonio.petcare;

import android.content.Context;
import android.content.Intent;
import android.support.annotation.NonNull;
import android.support.design.widget.NavigationView;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;

public class Help extends AppCompatActivity {


    private DrawerLayout mDrawerLayout;
    private ActionBarDrawerToggle mToggle;
    private android.support.v7.widget.Toolbar mToolbar;
    private NavigationView mNavigationView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_calendar);

        //Define the main layout of the activity and the navigation toolbar
        mDrawerLayout = (DrawerLayout) findViewById(R.id.drawerLayoutCalendar);
        mToolbar = (android.support.v7.widget.Toolbar) findViewById(R.id.navToolbar);

        //get support for the navigation toolbar
        setSupportActionBar(mToolbar);
        getSupportActionBar().setTitle(R.string.nav_help);

        //Define new toggle button for the navigation menu
        mToggle = new ActionBarDrawerToggle(this, mDrawerLayout, R.string.openNav, R.string.closeNav);

        //Enable toggle button
        mToggle.syncState();
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);

        //Define new navigation menu
        mNavigationView = (NavigationView) findViewById(R.id.navView);

        navigationActions(Help.this);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.toolbar_menu, menu);
        return super.onCreateOptionsMenu(menu);
    }

    public void navigationActions(final Context context){
        mNavigationView.setNavigationItemSelectedListener(new NavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(@NonNull MenuItem item) {
                Intent intent = null;
                boolean changeActivity = false;

                switch (item.getItemId()){
                    case R.id.nav_homepage:
                        intent = new Intent(context, MainActivity.class);
                        changeActivity = true;
                        break;
                    case R.id.nav_calendar:
                        intent = new Intent(context, Calendar.class);
                        changeActivity = true;
                        break;
                    case R.id.nav_reminders:
                        intent = new Intent(context, Reminders.class);
                        changeActivity = true;
                        break;
                    case R.id.nav_tips:
                        intent = new Intent(context, Tips.class);
                        changeActivity = true;
                        break;
                    case R.id.nav_help:
                        changeActivity = false;
                        break;
                }

                if(changeActivity){
                    startActivity(intent);
                    finish();
                }

                mDrawerLayout.closeDrawers();
                return true;
            }
        });
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        Log.d("Pet", "ID: " + item.getItemId());
        if(mToggle.onOptionsItemSelected(item)){
            return true;
        }

        Intent intent;
        switch (item.getItemId()){
            case R.id.nav_settings:
                intent = new Intent(this, Settings.class);
                startActivity(intent);
                break;
            case R.id.nav_about:
                intent = new Intent(this, AboutUs.class);
                startActivity(intent);
                break;
        }

        return true;
    }

}
