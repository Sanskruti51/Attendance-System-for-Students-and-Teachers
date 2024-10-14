#include <reg51.h>
#define Data P2

sbit rs = P2^4;
sbit en = P2^5;

sbit R0 = P3^0;
sbit R1 = P3^1;
sbit R2 = P3^2;
sbit R3 = P3^3;
sbit C0 = P3^4;
sbit C1 = P3^5;
sbit C2 = P3^6;
sbit C3 = P3^7;

sbit sw1=P1^0;
sbit sw2=P1^1;

sbit led1=P1^2;
sbit led2=P1^3;

void lcd_init();  // LCD initialization
void lcd_cmd(unsigned char cmd);    // for commands
void lcd_data(unsigned char d); // for printing character on LCD
void delay(unsigned int t);  // delay
void display(unsigned char a[]);   // for printing string on LCD
void printRead_rollno();   // for printing and reading roll number
void printRead_pwd();      // for printing and reading password
void int_to_str(int num, char* str, int len);   // to convert integer to string
void password();   // to calculate password
void in();     //clear lcd


int rollno = 0;
char pwd[5] = {0};     // for storing password input
unsigned int attend[4] = {0};  // for storing attendance count 
char p[5] = {0};      // for storing the calculated password after converting from integer to character
int pass[4] = {0};   // for storing calculated password in integer
int r; //for string compare result to store
void lcd_init() {
    lcd_cmd(0x28);
    lcd_cmd(0x01);
    lcd_cmd(0x0C);
    lcd_cmd(0x80);
}

void lcd_cmd(unsigned char cmd) {
    Data = (cmd >> 4);
    rs = 0;
    en = 1;
    delay(1);
    en = 0;
    delay(1);

    Data = cmd;
    rs = 0;
    en = 1;
    delay(1);
    en = 0;
    delay(1);
}

void lcd_data(unsigned char d) {
    Data = (d >> 4);
    rs = 1;
    en = 1;
    delay(1);
    en = 0;
    delay(1);

    Data = d;
    rs = 1;
    en = 1;
    delay(1);
    en = 0;
    delay(1);
}

void delay(unsigned int t) {
    int i, j;
    for (i = 0; i <= t * 10; i++) {
        for (j = 0; j < 127; j++);
    }
}

void display(unsigned char a[]) {
    int i;
    for (i = 0; a[i] != '\0'; i++) {
        lcd_data(a[i]);
    }
}

void printRead_rollno() {
    int i = 0;
    R0 = R1 = R2 = R3 = 0;
    C0 = C1 = C2 = C3 = 1;
    delay(2);

    while (i < 1) {
        R0 = 0; R1 = R2 = R3 = 1;
        if (C0 == 0) {
            lcd_data('7');
            rollno = 7;
            i++;
            while (C0 == 0);
            delay(2);
        }
        if (C1 == 0) {
            lcd_data('8');
            rollno = 8;
            i++;
            while (C1 == 0);
            delay(2);
        }
        if (C2 == 0) {
            lcd_data('9');
            rollno = 9;
            i++;
            while (C2 == 0);
            delay(2);
        }
        
        R0 = R2 = R3 = 1;
        R1 = 0;
        if (C0 == 0) {
            lcd_data('4');
            rollno = 4;
            i++;
            while (C0 == 0);
            delay(2);
        }
        if (C1 == 0) {
            lcd_data('5');
            rollno = 5;
            i++;
            while (C1 == 0);
            delay(2);
        }
        if (C2 == 0) {
            lcd_data('6');
            rollno = 6;
            i++;
            while (C2 == 0);
            delay(2);
        }
        R2 = 0;
        R0 = R1 = R3 = 1;
        if (C0 == 0) {
            lcd_data('1');
            rollno = 1;
            i++;
            while (C0 == 0);
            delay(2);
        }
        if (C1 == 0) {
            lcd_data('2');
            rollno = 2;
            i++;
            while (C1 == 0);
            delay(2);
        }
        if (C2 == 0) {
            lcd_data('3');
            rollno = 3;
            i++;
            while (C2 == 0);
            delay(2);
        }
        R3 = 0;
        R0 = R1 = R2 = 1;
        
        if (C1 == 0) {
            lcd_data('0');
            rollno = 0;
            i++;
            while (C1 == 0);
            delay(2);
        }
        
        R0 = R1 = R2 = R3 = 0;
        C0 = C1 = C2 = C3 = 1;
        delay(10);        
    }
}
void printRead_pwd() {
    int i = 0;
    R0 = R1 = R2 = R3 = 0;
    C0 = C1 = C2 = C3 = 1;
    delay(2);

    while (i < 4) {
        R0 = 0; R1 = R2 = R3 = 1;
        if (C0 == 0) {
            lcd_data('7');
            pwd[i++] = '7';
            while (C0 == 0);
            delay(2);
        }
        if (C1 == 0) {
            lcd_data('8');
            pwd[i++] = '8';
            while (C1 == 0);
            delay(2);
        }
        if (C2 == 0) {
            lcd_data('9');
            pwd[i++] = '9';
            while (C2 == 0);
            delay(2);
        }
     
        R0 = R2 = R3 = 1;
        R1 = 0;
        if (C0 == 0) {
            lcd_data('4');
            pwd[i++] = '4';
            while (C0 == 0);
            delay(2);
        }
        if (C1 == 0) {
            lcd_data('5');
            pwd[i++] = '5';
            while (C1 == 0);
            delay(2);
        }
        if (C2 == 0) {
            lcd_data('6');
            pwd[i++] = '6';
            while (C2 == 0);
            delay(2);
        }
        R2 = 0;
        R0 = R1 = R3 = 1;
        if (C0 == 0) {
            lcd_data('1');
            pwd[i++] = '1';
            while (C0 == 0);
            delay(2);
        }
        if (C1 == 0) {
            lcd_data('2');
            pwd[i++] = '2';
            while (C1 == 0);
            delay(2);
        }
        if (C2 == 0) {
            lcd_data('3');
            pwd[i++] = '3';
            while (C2 == 0);
            delay(2);
        }
        
        R3 = 0;
        R0 = R1 = R2 = 1;
        if (C1 == 0) {
            lcd_data('0');
            pwd[i++] = '0';
            while (C1 == 0);
        }
        R0 = R1 = R2 = R3 = 0;
        C0 = C1 = C2 = C3 = 1;
        delay(10);        
    }

 
}

void password() {               // calculated password
	int i;  
    for ( i = 1; i < 5; i++) {
        pass[i] = 1243 + i;
    }
}

void int_to_str(int num, char* str, int len) {
    int i = len - 1;
    str[i--] = '\0';
    do {
        str[i--] = (num % 10) + '0';
        num /= 10;
    } while (num > 0 && i >= 0);
    while (i >= 0) {
        str[i--] = '0';  // Fill remaining positions with '0'
    }
}

void in(){
					delay(5);
            lcd_cmd(0x01); 
            lcd_cmd(0x0C); 
            lcd_cmd(0x80); 
            delay(5);
}



    


