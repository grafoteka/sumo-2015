/* PROGRAMA PARA ENCENDER Y APAGAR UN LED MEDIANTE BLUETOOTH */


// Configuracion BT
char ssid[10]		= "Arduino1";	// Nombre para el modulo Bluetooth.
char baudios		 = '4';		   // 1=>1200 baudios, 2=>2400, 3=>4800, 4=>9600 (por defecto), 5=>19200, 6=>38400, 7=>57600, 8=>115200
char password[10]	= "0000";		// Contraseña para el emparejamiento del modulo.

// Variables
String dato;
int led = 13;


void setup()
{
  Serial.begin(9600);     // Iniciamos el monitor Serial 
  
  Serial3.begin(9600);    // Iniciamos el puerto de comunicacion del BT
  
  pinMode(led, OUTPUT);   // Configuramos el LED como salida

  // Tiempo de espera:
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  delay(10000);
  digitalWrite(13,LOW);

  // Ahora se procede a la configuración del modulo:

  // Se inicia la configuración:
  Serial3.print("AT"); 
  delay(1000);

  // Se ajusta el nombre del Bluetooth:
  Serial3.print("AT+NAME"); 
  Serial3.print(ssid); 
  delay(1000);

  // Se ajustan los baudios:
  Serial3.print("AT+BAUD"); 
  Serial3.print(baudios); 
  delay(1000);

  // Se ajusta la contraseña:
  Serial3.print("AT+PIN"); 
  Serial3.print(password); 
  delay(1000);
  
  // Mensaje de inicio del programa
  Serial.println("Configuracion terminada");	
}

void loop()
{
  // Al parpadear el led se habrá terminado la configuración:
//  digitalWrite(13, !digitalRead(13));
//  delay(500);
//  Serial3.print(millis()); Serial3.print("\r\n");
//  delay(1000);

  while(Serial3.available()){
    delay(10);
    if(Serial3.available() > 0){
      char c = Serial3.read();
      dato += c;
    }
  }
  
  if(dato.length() > 0){
    if(dato == "1"){
      Serial.println("Encender LED");
      digitalWrite(led, HIGH);
    }
     if(dato == "0"){
      Serial.println("Apagar LED");
      digitalWrite(led, LOW);
    }   
    
  }

}

