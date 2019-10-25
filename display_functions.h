void mainScreen() { //That's the function that displays the main screen according to the chosen mode.
  lcd.begin(displayWidth, displayHeight);
  lcd.setCursor(16, 0);
  lcd.print(rectangle);
  lcd.setCursor(22, 0);
  lcd.print(rectangle);
  lcd.setCursor(28, 0);
  lcd.print(rectangle);
  lcd.setCursor(34, 0);
  lcd.print(rectangle);
  lcd.setCursor(16, 1);
  lcd.print(rectangle);
  lcd.setCursor(22, 1);
  lcd.print(rectangle);
  lcd.setCursor(28, 1);
  lcd.print(rectangle);
  lcd.setCursor(34, 1);
  lcd.print(rectangle);
  showSong();
  showBlocks();
}
