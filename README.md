# TraductorMorzeArduino
Un traductor de codigo morze hecho en arduino.
Las reglas son muy simples, se da un string como entrada en la consola y el dispositivo se encarga de traducirlo en señales sonoras y de luz correspondiente a la palabra indicada.

Un par de cosas a tener en cuenta:
- Los puntos "." se utilizan como unidad de tiempo, 1 "." = 1 unidad de tiempo.
- Las lineas "-" son equivalentes a 3 puntos, 3 "." = 1 "-".
- cada letra se separa por 1 "-" de tiempo en silencio, es decir el tiempo entre cada letra el cual el dispositivo no va emitir señales es de 3 unidades de tiempo.
- cada palabra se separa por 5 unidades de tiempo del cual el dispositivo no va a emitir señales. 
  
