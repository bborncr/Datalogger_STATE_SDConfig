void logData() {

  timestamp = getTimestamp();
  // get sensor data -- this could have some preprocessing/filtering built-in
  int sensor1 = analogRead(A0);
//  int sensor2 = analogRead(A1);
//  int sensor3 = analogRead(A2);
  // save data to file
  logfile.print(timestamp); logfile.print(",");
  logfile.println(sensor1); //logfile.print(",");
//  logfile.print(sensor2); logfile.print(",");
//  logfile.println(sensor3);
  logfile.flush();
  if (logfile.size() > 10000000) { // if filesize is more than 10M then create a new file
    logfile.close();
    stage = NEW;
  }
  digitalWrite(SD_LED, HIGH); // quick blink of the led to show activity
  delay(40);
  digitalWrite(SD_LED, LOW);
}
