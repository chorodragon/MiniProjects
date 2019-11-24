package com.example.antonio.quizapp;

import android.content.DialogInterface;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private Button trueButton;
    private Button falseButton;
    private TextView questionText;
    private TextView scoreText;
    private ProgressBar progressBar;

    private int indexQuestions;
    private int mScore;

    private TrueFalse[] mQuestionBank = new TrueFalse[] {
            new TrueFalse(R.string.question_1, true),
            new TrueFalse(R.string.question_2, true),
            new TrueFalse(R.string.question_3, true),
            new TrueFalse(R.string.question_4, true),
            new TrueFalse(R.string.question_5, true),
            new TrueFalse(R.string.question_6, false),
            new TrueFalse(R.string.question_7, true),
            new TrueFalse(R.string.question_8, false),
            new TrueFalse(R.string.question_9, true),
            new TrueFalse(R.string.question_10, true),
            new TrueFalse(R.string.question_11, false),
            new TrueFalse(R.string.question_12, false),
            new TrueFalse(R.string.question_13,true)
    };


    private final int PROGRESS_BAR_INCREMENT = (int) Math.ceil(100.0 / mQuestionBank.length);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        trueButton = (Button) findViewById(R.id.trueButton);
        falseButton = (Button) findViewById(R.id.falseButton);

        questionText = (TextView) findViewById(R.id.questionText);
        scoreText = (TextView) findViewById(R.id.score);

        progressBar = (ProgressBar) findViewById(R.id.progressBar);


        questionText.setText(mQuestionBank[indexQuestions].getmIdQuestion());

        if (savedInstanceState != null){
            mScore = savedInstanceState.getInt("ScoreKey");
            indexQuestions = savedInstanceState.getInt("IndexKey");
            scoreText.setText("Score: " + mScore + "/" + mQuestionBank.length);
        } else{
            indexQuestions = 0;
            mScore = 0;
        }

        trueButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                checkAnswer(true);
                updateQuestion();
            }
        });

        falseButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                checkAnswer(false);
                updateQuestion();
            }
        });
    }

    private void updateQuestion(){
        indexQuestions++;
        if (indexQuestions < mQuestionBank.length) {
            questionText.setText(mQuestionBank[indexQuestions].getmIdQuestion());
            progressBar.incrementProgressBy(PROGRESS_BAR_INCREMENT);
            scoreText.setText("Score: " + mScore + "/" + mQuestionBank.length);
        }
        else {
            progressBar.setProgress(100);
            AlertDialog.Builder alert = new AlertDialog.Builder(this);
            alert.setTitle(R.string.gameOverTitle);
            alert.setCancelable(false);
            alert.setMessage(getString(R.string.gameOverBody) + mScore);
            alert.setPositiveButton("Close Application", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    finish();
                }
            });
            alert.show();
        }
    }

    private void checkAnswer(boolean answer){
        if (indexQuestions >= mQuestionBank.length)
            return;

        if (answer == mQuestionBank[indexQuestions].ismAnswer())
            mScore++;
    }

    @Override
    public void onSaveInstanceState(Bundle outState){
        super.onSaveInstanceState(outState);
        outState.putInt("ScoreKey", mScore);
        outState.putInt("IndexKey", indexQuestions);
    }
}
