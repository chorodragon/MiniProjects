package com.example.antonio.destiniapp;

public class stateHistory {
    private int storyText;
    private int firstChoice;
    private int secondChoice;
    private int nextFirstChoice;
    private int nextSecondChoice;

    public stateHistory(int storyText, int firstChoice, int secondChoice, int nextFirstChoice, int nextSecondChoice) {
        this.storyText = storyText;
        this.firstChoice = firstChoice;
        this.secondChoice = secondChoice;
        this.nextFirstChoice = nextFirstChoice;
        this.nextSecondChoice = nextSecondChoice;
    }

    public int getStoryText() {
        return storyText;
    }

    public int getFirstChoice() {
        return firstChoice;
    }

    public int getSecondChoice() {
        return secondChoice;
    }

    public int getNextFirstChoice() {
        return nextFirstChoice;
    }

    public int getNextSecondChoice() {
        return nextSecondChoice;
    }
}
