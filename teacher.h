#include <reg51.h>

// Function prototypes
void tpassword();


// Global variables
 int tpass[2] = {0};   // for storing calculated password in integer

void tpassword() {  // calculated password
    int i;  
    for (i = 1; i < 3; i++) {
        tpass[i] = 1234 + i;
    }
}

