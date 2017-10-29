int is_Between_0_And_7 (unsigned char input){

	int flagfError;
	if( (input >= '0') && (input <= '7') )
		flagError = 1;
	else
		flagError = 0;

	return flagError;
}
