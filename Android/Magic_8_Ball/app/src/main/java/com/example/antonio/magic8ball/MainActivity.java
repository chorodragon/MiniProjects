package com.example.antonio.magic8ball;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

import java.util.Random;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final Random randomGenerator = new Random();

        final ImageView ballImage = (ImageView) findViewById(R.id.ballImage);
        Button askButton = (Button) findViewById(R.id.askButton);

        final int[] balls = {R.drawable.ball1, R.drawable.ball2, R.drawable.ball3, R.drawable.ball4,
                        R.drawable.ball5, R.drawable.ball6, R.drawable.ball7, R.drawable.ball8,
                        R.drawable.ball9, R.drawable.ball10};

        askButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int randomNumber;
                randomNumber = randomGenerator.nextInt(10);
                ballImage.setImageResource(balls[randomNumber]);
            }
        });

    }
}
