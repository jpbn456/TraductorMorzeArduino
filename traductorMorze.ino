const int PULSADOR = 2;
const int LED = 3;
const int BUZZ = 5;
const int UNIT = 400;
const int DOT = 0;
const int DASH = 1;
const char DOTCHAR = '.';
const char DASHCHAR = '-';
const char SPACECHAR = ' ';

String palabraMorse;

bool espacioDisponible = false;
bool pressed = false;

String codificar;

unsigned long initialTime = 0;
unsigned long offTime = 0;
unsigned long totalTime = 0;

unsigned long lowInitialTime = 0;
unsigned long lowOffTime = 0;
unsigned long lowTotalTime = 0;

int letraLeida[4] = {-1,-1,-1,-1};
int posLetra = 0;

struct letra {
  int codigo[4];
  char letraDecodificada;
};

letra diccionario[26];

void armarDiccionario(){
  //E
  diccionario[0].codigo[0] = DOT;
  diccionario[0].codigo[1] = -1;
  diccionario[0].codigo[2] = -1;
  diccionario[0].codigo[3] = -1;
  diccionario[0].letraDecodificada = 'E';
  //T
  diccionario[1].codigo[0] = DASH;
  diccionario[1].codigo[1] = -1;
  diccionario[1].codigo[2] = -1;
  diccionario[1].codigo[3] = -1;
  diccionario[1].letraDecodificada = 'T';
  //I
  diccionario[2].codigo[0] = DOT;
  diccionario[2].codigo[1] = DOT;
  diccionario[2].codigo[2] = -1;
  diccionario[2].codigo[3] = -1;
  diccionario[2].letraDecodificada = 'I';
  //A
  diccionario[3].codigo[0] = DOT;
  diccionario[3].codigo[1] = DASH;
  diccionario[3].codigo[2] = -1;
  diccionario[3].codigo[3] = -1;
  diccionario[3].letraDecodificada = 'A';
  //N
  diccionario[4].codigo[0] = DASH;
  diccionario[4].codigo[1] = DOT;
  diccionario[4].codigo[2] = -1;
  diccionario[4].codigo[3] = -1;
  diccionario[4].letraDecodificada = 'N';
  //M
  diccionario[5].codigo[0] = DASH;
  diccionario[5].codigo[1] = DASH;
  diccionario[5].codigo[2] = -1;
  diccionario[5].codigo[3] = -1;
  diccionario[5].letraDecodificada = 'M';
  //S
  diccionario[6].codigo[0] = DOT;
  diccionario[6].codigo[1] = DOT;
  diccionario[6].codigo[2] = DOT;
  diccionario[6].codigo[3] = -1;
  diccionario[6].letraDecodificada = 'S';
  //U
  diccionario[7].codigo[0] = DOT;
  diccionario[7].codigo[1] = DOT;
  diccionario[7].codigo[2] = DASH;
  diccionario[7].codigo[3] = -1;
  diccionario[7].letraDecodificada = 'U';
  //R
  diccionario[8].codigo[0] = DOT;
  diccionario[8].codigo[1] = DASH;
  diccionario[8].codigo[2] = DOT;
  diccionario[8].codigo[3] = -1;
  diccionario[8].letraDecodificada = 'R';
  //W
  diccionario[9].codigo[0] = DOT;
  diccionario[9].codigo[1] = DASH;
  diccionario[9].codigo[2] = DASH;
  diccionario[9].codigo[3] = -1;
  diccionario[9].letraDecodificada = 'W';
  //D
  diccionario[10].codigo[0] = DASH;
  diccionario[10].codigo[1] = DOT;
  diccionario[10].codigo[2] = DOT;
  diccionario[10].codigo[3] = -1;
  diccionario[10].letraDecodificada = 'D';
  //K
  diccionario[11].codigo[0] = DASH;
  diccionario[11].codigo[1] = DOT;
  diccionario[11].codigo[2] = DASH;
  diccionario[11].codigo[3] = -1;
  diccionario[11].letraDecodificada = 'K';
  //G
  diccionario[12].codigo[0] = DASH;
  diccionario[12].codigo[1] = DASH;
  diccionario[12].codigo[2] = DOT;
  diccionario[12].codigo[3] = -1;
  diccionario[12].letraDecodificada = 'G';
  //O
  diccionario[13].codigo[0] = DASH;
  diccionario[13].codigo[1] = DASH;
  diccionario[13].codigo[2] = DASH;
  diccionario[13].codigo[3] = -1;
  diccionario[13].letraDecodificada = 'O';
  //H
  diccionario[14].codigo[0] = DOT;
  diccionario[14].codigo[1] = DOT;
  diccionario[14].codigo[2] = DOT;
  diccionario[14].codigo[3] = DOT;
  diccionario[14].letraDecodificada = 'H';
  //V
  diccionario[15].codigo[0] = DOT;
  diccionario[15].codigo[1] = DOT;
  diccionario[15].codigo[2] = DOT;
  diccionario[15].codigo[3] = DASH;
  diccionario[15].letraDecodificada = 'V';
  //F
  diccionario[16].codigo[0] = DOT;
  diccionario[16].codigo[1] = DOT;
  diccionario[16].codigo[2] = DASH;
  diccionario[16].codigo[3] = DOT;
  diccionario[16].letraDecodificada = 'F';
  //L
  diccionario[17].codigo[0] = DOT;
  diccionario[17].codigo[1] = DASH;
  diccionario[17].codigo[2] = DOT;
  diccionario[17].codigo[3] = DOT;
  diccionario[17].letraDecodificada = 'L';
  //P
  diccionario[18].codigo[0] = DOT;
  diccionario[18].codigo[1] = DASH;
  diccionario[18].codigo[2] = DASH;
  diccionario[18].codigo[3] = DOT;
  diccionario[18].letraDecodificada = 'P';
  //J
  diccionario[19].codigo[0] = DOT;
  diccionario[19].codigo[1] = DASH;
  diccionario[19].codigo[2] = DASH;
  diccionario[19].codigo[3] = DASH;
  diccionario[19].letraDecodificada = 'J';
  //B
  diccionario[20].codigo[0] = DASH;
  diccionario[20].codigo[1] = DOT;
  diccionario[20].codigo[2] = DOT;
  diccionario[20].codigo[3] = DOT;
  diccionario[20].letraDecodificada = 'B';
  //X
  diccionario[21].codigo[0] = DASH;
  diccionario[21].codigo[1] = DOT;
  diccionario[21].codigo[2] = DOT;
  diccionario[21].codigo[3] = DASH;
  diccionario[21].letraDecodificada = 'X';
  //C
  diccionario[22].codigo[0] = DASH;
  diccionario[22].codigo[1] = DOT;
  diccionario[22].codigo[2] = DASH;
  diccionario[22].codigo[3] = DOT;
  diccionario[22].letraDecodificada = 'C';
  //Y
  diccionario[23].codigo[0] = DASH;
  diccionario[23].codigo[1] = DOT;
  diccionario[23].codigo[2] = DASH;
  diccionario[23].codigo[3] = DASH;
  diccionario[23].letraDecodificada = 'Y';
  //Z
  diccionario[24].codigo[0] = DASH;
  diccionario[24].codigo[1] = DASH;
  diccionario[24].codigo[2] = DOT;
  diccionario[24].codigo[3] = DOT;
  diccionario[24].letraDecodificada = 'Z';
  //Q
  diccionario[25].codigo[0] = DASH;
  diccionario[25].codigo[1] = DASH;
  diccionario[25].codigo[2] = DOT;
  diccionario[25].codigo[3] = DASH;
  diccionario[25].letraDecodificada = 'Q';
  
}

int space(unsigned long tiempo){
  if(tiempo <= (3*UNIT)){
    return 0;//partes
  } 
  else if (tiempo > (3*UNIT) && tiempo <= (7*UNIT)){
    return 1;//letras
  } 
  else{
    return 2;//palabras
  }

}

void encode(){
  palabraMorse = "";
  int lugarLetra;
  for(int i = 0; i < codificar.length(); i++){
    lugarLetra = searchLetra(codificar.charAt(i));
    if(lugarLetra != -1) morseArray(lugarLetra);
    else palabraMorse.concat(SPACECHAR);
  }
}
                           
void morseArray(int pos){
  int i = 0;
  while(diccionario[pos].codigo[i] != -1 && i < 4){
  	if (diccionario[pos].codigo[i] == DOT) palabraMorse.concat(DOTCHAR);
    else if(diccionario[pos].codigo[i] == DASH) palabraMorse.concat(DASHCHAR);
      i++;
  }
  palabraMorse.concat(SPACECHAR);
}
                
int searchLetra(char item){
  int i = 0;
  while( i < 26){
    if(diccionario[i].letraDecodificada == item) return i;
    i++;
  }
  return (-1);
}

void morseToLed(){
  for(int i = 0; i < palabraMorse.length(); i++){
    if(palabraMorse.charAt(i) == DOTCHAR){
        delay(UNIT);
    	turnOnDevices();
      	delay(UNIT);
        turnOffDevices();
    }
    else if(palabraMorse.charAt(i) == DASHCHAR){
      	delay(UNIT);
    	turnOnDevices();
      	delay(UNIT*3);
      	turnOffDevices();
    }
    else if(palabraMorse.charAt(i) == SPACECHAR){
    	delay(UNIT*3);	
    }
  }
}

void turnOnDevices(){
	digitalWrite(LED,HIGH);
  	digitalWrite(BUZZ,HIGH);
}

void turnOffDevices(){
	digitalWrite(LED,LOW);
  	digitalWrite(BUZZ,LOW);
}

char decode(int let[],int limite){
  bool encontrado = false;
  int pos = 0;
  for(int i = 0; (i < 26) && (!encontrado); i++){
    int j = 0;
    while(j < limite){
      if(let[j] == diccionario[i].codigo[j] && j!=(limite-1) ){
        j++;
      } 
      else if(let[j] == diccionario[i].codigo[j] && j==(limite-1)){
       encontrado = true;
       j = limite;
       pos = i;
      }  
      else j = limite;
    }
  }
  if (encontrado == true){
    return (diccionario[pos].letraDecodificada) ;
  } 
  else{
    for(int i = 0;i <4;i++){
      //Serial.print(diccionario[pos].codigo[i]);
    }
    Serial.print(' ');
    for(int i = 0;i <4;i++){
      Serial.print(letraLeida[i]);
    }
    return '?';
  } 
}

int dotOrDash(unsigned long time){
  if(time < (3* UNIT) ){
    return DOT;
  } 
  else return DASH;	
}

void reiniciarLetra(){
  for(int i = 0; i < 4; i++){
    letraLeida[i] = -1;
  }
  posLetra = 0;
}

bool letraVacia(){
  bool vacia = true;
  int i = 0;
  while (i < 4 && vacia){
    if(letraLeida[i] != (-1)){
      vacia = false;
    }
    i++;
  }
  return vacia;
}

void tiempoInactivo(){
   if(lowInitialTime == 0){
     return;
    }
   lowOffTime = millis();
   lowTotalTime = lowOffTime - lowInitialTime;
   int cond = space(lowTotalTime); // condicion para space
   if(letraVacia()){
    if (cond == 2) {//Distancia entre palabras
       if(espacioDisponible == true){
         Serial.print(' ');
         espacioDisponible = false;
       }
    }
  }
  else if(cond == 1){//Distancia entre letras
      Serial.print(decode(letraLeida, posLetra));
      reiniciarLetra();
      espacioDisponible = true;
  }
}

void setup() {
  pinMode(PULSADOR, INPUT); // pin 2 entrada
  pinMode(LED, OUTPUT); // pin 3 salida
  pinMode(BUZZ,OUTPUT);
  Serial.begin(9600);
  armarDiccionario();
  
}

void loop () { 
  if(Serial.available() > 0){
    codificar = Serial.readString();
    encode();
    Serial.println(palabraMorse);
    morseToLed();
  }
  if(digitalRead(PULSADOR) == HIGH && !pressed){
    pressed = true;
    initialTime = millis();
    turnOnDevices();
    tiempoInactivo();
  } 
  else if(digitalRead(PULSADOR) == LOW && pressed){
    pressed = false;
    offTime = millis();
    turnOffDevices();
  	totalTime = offTime - initialTime;
    //Agregar dot o dash
    letraLeida[posLetra] = dotOrDash(totalTime);  
    posLetra++;
    if(posLetra == 4){
      Serial.print(decode(letraLeida, posLetra));
      reiniciarLetra();
       posLetra = 0;
    }
    //Manejar tiempo boton sin apretar
    lowInitialTime = offTime;
    
  }
 //CHEQUEAR SI YA PASARON 7 SEG
  else if(digitalRead(PULSADOR) == LOW && !pressed){
    //CHEQUEAR QUE LETRA NO ESTE VACIA
    tiempoInactivo();
  }
}
 

