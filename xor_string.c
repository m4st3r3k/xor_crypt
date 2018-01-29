#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


#define MSG_ERROR "\n\nUsage: ./xor_string [-e] for encrypt  or [-d]  for decrypt + [text] + [key]\n\n Example: ./xor_string -e masterek ABCD\n\n Use -h for help\n"

#define MSG_ERROR_2 "\n\n***Note: Don't use a secret key with spaces***\n\n"

#define MSG_ERROR_3 "\n Error: Too many arguments\n\n Use -h for help\n\n"



void usage(void) {
	fprintf(stderr, "%s", MSG_ERROR);
	fprintf(stderr, "%s", MSG_ERROR_2);
	exit(1);
}

void usage_2(void){
	fprintf(stderr, "%s", MSG_ERROR_3);
	exit(1);
}


char *func_encrypt(char *message, char *key) {
	size_t messagelen = strlen(message);

	size_t keylen = strlen(key);

	char * encrypted = malloc(messagelen + 1);

 	
	for(int i = 0; i < messagelen; i++){
		
		encrypted[i] = message[i] ^ key[i % keylen];
																   
 	}
	
	encrypted[messagelen] = '\0';

													   
 	return encrypted;

}


int main(int argc, char *argv[]) {

	char 	*message = argv[2];
	char *key = argv[3];
	char message_2[1000];
	char key_2[1000];
	char *encrypted;
	char *decrypted;
	char *encdec;
 	int opt;


if ((argc == 3) ||(argc == 1)){
	
	usage();
}

if (argc > 4){

	usage_2();
}

	

	while ((opt = getopt(argc, argv, "e:d:th")) != -1){

		switch (opt){

	
			case 'e':
				
				encrypted = func_encrypt(message, key);
				printf("%s\n", encrypted);
				printf("HEX: %X\n", encrypted);
				decrypted = func_encrypt(encrypted, key);
				printf("Decrypted: %s\n", decrypted);	
				break;

			case 'd':

		    decrypted = func_encrypt(message, key);
				printf("Plain text: %s\n" , decrypted);
				break;

			case 't':

				puts("Set message:\n");
				scanf("%1000[^\n]s", &message_2);
				puts("Set secret key:\n");
				scanf("%1000s", &key_2);
				encdec = func_encrypt(message_2, key_2);
				printf("%s\n", encdec);
				break;


			case 'h':

          puts(MSG_ERROR);
					puts("\t-e encrypt message\n");
					puts("\t-d decrypt message\n");
					puts("\t-t use for encrypt or decrypt long text with spaces. This option change to text mode. Example: ./xor_string -t\n");
					break;
		}

	}
									    
	free(encrypted);

											    
	return 0;

}
