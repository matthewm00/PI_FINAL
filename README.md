# PI-FINAL

Por consola ingrese el comando make; de esta manera se generan los dos ejecutables: arbolesADTBUE y arbolesADTVAN.

Posteriormente, escriba lo siguiente para ejecutarlos con los archivos .csv por linea de comando, y asi, generar las queries:

./arbolesADTBUE arbolesBUE.csv barriosBUE.csv
./arbolesADTVAN arbolesVAN.csv barriosVAN.csv

Por ultimo, si se desea eliminar los ejecutables se puede utilizar make clean:

Para eliminar los archivos .o: make clean

Para eliminar los ejecutables: make delexecutables

Para eliminar los query's: make delquery

IMPORTANTE: debe respetarse el orden de los archivos (primero el de arboles, luego el de barrios) para obtener el resultado esperado.
