const rockB = document.querySelector(".rockB");
const paperB = document.querySelector(".paperB");
const scissorsB = document.querySelector(".scissorsB");
const restartB = document.querySelector(".restartB");
let playerScore = 0;
let botScore = 0;
let playerSelection = "";
let turn = 1;

function executeEnd(){
  restartB.style.display = "block";
  let resultD = document.querySelector(".result");
  if (playerScore > botScore){
    resultD.textContent = "Player won this round!!!";
  }
  else if (botScore > playerScore){
    resultD.textContent = "Bot won this round!!!";
  }
  else{
    resultD.textContent = "It's a draw!!!";
  }
  resultD.style.display = "block";
}

function update(){
  let turnD = document.querySelector(".turn");
  let playerSD = document.querySelector(".playerScore>.score");
  let botSD = document.querySelector(".botScore>.score");
  if (turn <= 5){
    turnD.textContent = "Turn: " + turn;
  }
  else {
    turnD.textContent = "The End";
    executeEnd();
  }
  playerSD.textContent = playerScore;
  botSD.textContent = botScore;
}

function checkWinner(computerSelection) {
  let posibilities = ['rock', 'paper', 'scissors'];
  let resultDiff = Math.abs(playerSelection - computerSelection)
  switch(resultDiff){
    case 0:
      return 0;
      break;
    case 1:
      if (playerSelection > computerSelection){
        return 1;
      }
      else {
        return 2;
      }
      break;
    case 2:
      if (playerSelection == 0){
        return 1;
      }
      else {
        return 2;
      }
      break;
  }
  return 0;
}

function executeTurn(){
  let botSelection = Math.round(Math.random() * (2));
  let result = checkWinner(botSelection);
  // Checks if player won the round (value of 1) or the bot (value of 2)
  if (result == 1){
    playerScore++;
  }
  else if (result == 2){
    botScore++;
  }
  turn++;
  update();
}

rockB.addEventListener('click', (e)=>{
  playerSelection = 0;
  executeTurn();
});

paperB.addEventListener('click', (e)=>{
  playerSelection = 1;
  executeTurn();
});

scissorsB.addEventListener('click', (e)=>{
  playerSelection = 2;
  executeTurn();
});

restartB.addEventListener('click', (e)=>{
  restartB.style.display="none";
  document.querySelector(".result").style.display= "none";
  turn = 1;
  playerScore = 0;
  botScore = 0;
  update();
});

update();
