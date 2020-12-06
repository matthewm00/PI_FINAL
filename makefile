COMPILER=gcc
FLAGS=-pedantic -std=c99 -Wall -fsanitize=address
all: VAN BUE

VAN: OUTPUT_FILE=arbolesADTVAN
VAN: mainVAN.c
	$(COMPILER) -o $(OUTPUT_FILE) mainVAN.c treesADT.c NHoodADT.c queries.c readFiles.c $(FLAGS)
	@echo Compilation success!

BUE: OUTPUT_FILE=arbolesADTBUE
BUE: mainBUE.c 
	$(COMPILER) -o $(OUTPUT_FILE) mainBUE.c treesADT.c NHoodADT.c queries.c readFiles.c $(FLAGS)
	@echo Compilation success!

clean:
	rm -r arbolesADTVAN arbolesADTBUE
	@echo Clean success!
