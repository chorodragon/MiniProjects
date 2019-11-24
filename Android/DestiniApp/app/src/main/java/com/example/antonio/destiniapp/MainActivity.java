package com.example.antonio.destiniapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private TextView pHistoryText;
    private Button pFirstButton;
    private Button pSecondButton;

    private int mActualState;
    private stateHistory[] mStatesHistory = {
            new stateHistory(R.string.T1_Story, R.string.T1_Ans1, R.string.T1_Ans2, 3, 2),
            new stateHistory(R.string.T2_Story, R.string.T2_Ans1, R.string.T2_Ans2, 3, 4),
            new stateHistory(R.string.T3_Story, R.string.T3_Ans1, R.string.T3_Ans2, 6, 5),
            new stateHistory(R.string.T4_End, 0, 0, 0, 0),
            new stateHistory(R.string.T5_End, 0, 0, 0, 0),
            new stateHistory(R.string.T6_End, 0, 0, 0, 0)
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        if(savedInstanceState != null){
            mActualState = savedInstanceState.getInt("index");
        }
        else {
            mActualState = 0;
        }

        pHistoryText = (TextView) findViewById(R.id.historyText);
        pFirstButton = (Button) findViewById(R.id.firstButton);
        pSecondButton = (Button) findViewById(R.id.secondButton);

        pHistoryText.setText(mStatesHistory[mActualState].getStoryText());
        pFirstButton.setText(mStatesHistory[mActualState].getFirstChoice());
        pSecondButton.setText(mStatesHistory[mActualState].getSecondChoice());


        pFirstButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                updateHistory(1);
            }
        });

        pSecondButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                updateHistory(2);
            }
        });
    }

    private void updateHistory(int option){
        if(option == 1){
            mActualState = mStatesHistory[mActualState].getNextFirstChoice() - 1;
        }
        else{
            mActualState = mStatesHistory[mActualState].getNextSecondChoice() - 1;
        }
        pHistoryText.setText(mStatesHistory[mActualState].getStoryText());

        if(mStatesHistory[mActualState].getFirstChoice() != 0){
            pFirstButton.setText(mStatesHistory[mActualState].getFirstChoice());
            pSecondButton.setText(mStatesHistory[mActualState].getSecondChoice());
        }
        else{
            pFirstButton.setVisibility(View.GONE);
            pSecondButton.setVisibility(View.GONE);
        }
    }

    @Override
    public void onSaveInstanceState(Bundle outState){
        if (pFirstButton.getVisibility() != View.GONE){
            super.onSaveInstanceState(outState);
            outState.putInt("index", mActualState);
        }
    }
}
