# LFMServetVIII

## El kit del turista espacial :space_invader:

### Contexto  :notebook:
El espacio, la última frontera, o al menos eso decían… Para aquellos soñadores que se han pasado días, meses, o incluso años mirando las estrellas, os presentamos el kit del turista espacial. Poco queda para tocar las estrellas, pero cómo no, si se hace, se hace bien. Hace falta pues ir bien preparado para tal odisea. Nuestro proyecto va a oscilar alrededor del confort del turista promedio que tenga la suerte de surcar el polvo estelar. Está claro que este no es un astronauta, por lo tanto, queremos asegurarnos de que nuestro amigo el turista llegue en perfecto estado. Para ello, deberemos determinar qué necesitaría para exprimir su experiencia sideral:  si se podría marear con las fuerzas g, si necesitara asistencia respiratoria, y de qué tipo... También comprobaremos si la radiación le supondrá un problema, a qué plazo, y si esto se podría evitar con crema solar. Y por último, determinaremos si este turista podría difundir su aventura mediante su teléfono móvil o si debería protegerlo.
Un kit digno del bolsillo de cualquier astronauta y listo para la aventura.

### Problemas a estudiar :mag_right:
1.  Medida de la aceleración, radiación solar sobre todo UV en altitud y su influencia en los organismos

2.  Medida de magnitudes físicas como temperatura, presión, campo magnético; en función de la altitud

3.  Fabricación de una mini pila cobre/zinc reacción para simular una pila o batería y medida de su carga a lo largo del viaje. Comparación con la misma pila en la Tierra.….
    
4.  Caja resistente a condiciones extremas (temperatura, humedad, caída…)

### Soluciones adoptadas :key:
1.  Diversos sensores conectados a un microcontrolador Arduino Uno.
    
2.  Los sensores grabarán los datos en una tarjeta SD en un archivo de texto (.txt). Al recuperar la cápsula, un script en Python tratará el archivo .txt directamente para sacar las gráficas.
    
3.  Empleo de un kit de mutagénesis para detectar mutaciones genéticas en levaduras, las cuales serán enviadas en nuestra cápsula.
    
4.  Para que el material no se dañe debido a la humedad, la caja estará aislada; y para que el material no se dañe por las vibraciones, usaremos un material absorbente sobre el que irá colocado el dispositivo. Implementación de un modelo 3D personalizado.
    
5.  Difusión de los datos en tiempo real

### Plan de análisis de los datos obtenidos :computer:
Extracción y tratamiento de los datos obtenidos con un script Python (gráficos, estadísticas, correlaciones entre variables, etc…).
Las eventuales mutaciones en las levaduras se detectaran a simple vista (cambios de color) tras recuperar la sonda. Se realizará un análisis posterior en el laboratorio.
