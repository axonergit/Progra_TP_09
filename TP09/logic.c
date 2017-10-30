int is_Between_0_And_7 (unsigned char input){

	int flagNotError;
	if( (input >= '0') && (input <= '7') )				//Chequeo si se ha ingresado un numero entre 0 y 7
		flagNotError = 1;								//Dee ser asi prendo mi flag de no error
	else
		flagNotError = 0;							//Sino hubo error

	return flagNotError;					//Devuelvo si hay error
}
