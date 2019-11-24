package com.example.antonio.quizapp;

public class TrueFalse {
    private int mIdQuestion;
    private boolean mAnswer;

    public TrueFalse(int mIdQuestion, boolean mAnswer) {
        this.mIdQuestion = mIdQuestion;
        this.mAnswer = mAnswer;
    }

    public int getmIdQuestion() {
        return mIdQuestion;
    }

    public boolean ismAnswer() {
        return mAnswer;
    }
}
