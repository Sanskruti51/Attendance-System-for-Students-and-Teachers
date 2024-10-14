#include <reg51.h>
#include <string.h>
#include "student.h"
#include "teacher.h"

void main() {
    password();  

    while (1) {
        led1 = led2 = 1; 
        lcd_init();
        display("Attendance");
			  lcd_cmd(0xC0); 
			  display("System");
        delay(15);
        in();
        display("Teacher or");
			  lcd_cmd(0xC0); 
			  display("Student");
			 	while (sw1 && sw2);    

        // Check if the student button is pressed
        if (sw1 == 0) {
            in();
            display("Student");
					  lcd_cmd(0xC0); 
					display("Attendance");
            while (sw1 == 0); 
            led1 = 0;
            in();
            rollno = 0;
            lcd_init();
            display("Enter Roll no");
					delay(5);
            in();
            printRead_rollno();

            if (rollno < 5) {  // Valid roll numbers for students
                in();
                display("Enter Password");
							delay(5);
                in();
                printRead_pwd();
                in();
                int_to_str(pass[rollno], p, 5);
                delay(10);
                r = strcmp(pwd, p);
                if (r == 0) {
                    delay(5);
                    display("Attendance");
									  lcd_cmd(0xC0); 
									  display("Marked");
									delay(5);
                    attend[rollno]++;
                    in();
                    lcd_data('0' + rollno); 
                    lcd_data(':'); 
                    lcd_data(' ');
                    lcd_data(attend[rollno] + '0'); // Display attendance count
                    in();
                } else {
                    delay(5);
                    display("Invalid");
									lcd_cmd(0xC0);
                  display("Password");									
									 delay(5);
                    in();
                }
            } else {
                in();
                display("Invalid Roll No");
							delay(5);
            }
        }

        // Check if the teacher button is pressed
        if (sw2 == 0) {
            tpassword();
            in();
            display("Teacher");
					lcd_cmd(0xC0); 
					display("Attendance");
            delay(10);
            while (sw2 == 0); 
            led2 = 0;
            in();
            display("Enter Roll No");
					  delay(5);
            in();
            printRead_rollno();
            if (rollno < 3) {  
                in();
                display("Enter Password");
							  delay(5);
                in();
                printRead_pwd();
                int_to_str(tpass[rollno], p, 5);
                r = strcmp(pwd, p);
                if (r == 0) {
                    in();
                    display("Present");
									delay(5);
                } else {
                    in();
                    display("Invalid");
									lcd_cmd(0xC0); 
									display("Password");
									delay(5);
                }
            } else {
                in();
                display("Invalid Roll no");
							delay(5);
            }
        }
    }
}