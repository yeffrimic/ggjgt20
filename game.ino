boolean winner = false;
boolean won;
byte num1 = byte(random(0, 9));
byte num2= 0, num3= 0;
boolean p1 = true;
boolean p2 =false;
int time = 30;
int count = 0;
void setup() {
  size(800, 600);
  randomNumber();
  frameRate(60);
}
void draw() {

  if (frameCount - count >= time) {
    count = frameCount;
    if (!winner) {
      updateScreen();
    } else {
      winnerScreen(won);
    }
  }
}
void updateScreen() { 

  if (num2++ >8) num2 = 0;
  if (num3-- <1) num3 = 9;
  background(0);
  textSize(20);
  text("jugador 1: a", 0, 20);
  text("jugador 2: k", 0, 40);
  text("avanzar: espacio", 0, 60);
  text("repetir: r", 0, 80);
  textSize(50);
  text(str(num1), (width/2) - textWidth(str(num1)), 50);
  text(str(num2), (width/4) - textWidth(str(num2)), 200);
  text(str(num3), (width/4)*3 - textWidth(str(num3)), 200);
  text(str(time), (width/4)*4 - textWidth(str(time)), 50);
}

void winnerScreen(boolean who) {
  if (who == p1) { 
    background(0);
    textSize(40);
    text("Ganador jugador 1", (width/2) - textWidth("Ganador jugador 1"), height/2);
  } else {    
    background(0);
    textSize(40);
    text("Ganador jugador 2", (width/2) - textWidth("Ganador jugador 2"), height/2);
  }
}

void randomNumber() {
  num1 = byte(random(0, 9));
}

void keyPressed() {
  println(num1);
  println(num2);
  println(num3);
  if (key == 'a') {
    if (num2 == num1) {
      winner = true;
      won = p1;
      num1= -1;
    }
  } else if (key == 'k') {
    if (num3 == num1) {
      winner = true;
      won = p2;
      num1= -1;
    }
  } else if (key == ' ') {
    winner = false;
    randomNumber();
    time -=5;
    if (time <5) time = 5;
  } else if (key == 'r') {
    winner = false;
    randomNumber();
    time = 1;
  }
}
