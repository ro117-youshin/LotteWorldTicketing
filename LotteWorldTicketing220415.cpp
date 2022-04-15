#include <stdio.h>
#include <time.h>

int main() {
   
   // 1 - 1
   const int FULL_TICKET_1DAY_ADULT = 62000, FULL_TICKET_1DAY_TEEN = 54000, FULL_TICKET_1DAY_CHILD = 47000;
   // 1 - 2   
   const int FULL_TICKET_AFTER4_ADULT = 50000, FULL_TICKET_AFTER4_TEEN = 43000, FULL_TICKET_AFTER4_CHILD = 36000;
   // 2 - 1
   const int PARK_TICKET_1DAY_ADULT = 59000, PARK_TICKET_1DAY_TEEN = 52000, PARK_TICKET_1DAY_CHILD = 46000;
   // 2 - 2
   const int PARK_TICKET_AFTER4_ADULT = 47000, PARK_TICKET_AFTER4_TEEN = 41000, PARK_TICKET_AFTER4_CHILD = 35000; 
   // ���̺� 
   const int BABY = 15000;
   // �������
   const float DISCOUNT_RATE_DISABLED = 0.5, DISCOUNT_RATE_MAN_OF_MERIT = 0.5, DISCOUNT_RATE_SOLDIER = 0.51, DISCOUNT_RATE_PREGNANT = 0.5, DISCOUNT_RATE_CHILDREN_CARD = 0.7;
   
   int ticketingArr[] = {0}; 
   
    // Ticketing
    int inputTicketing, inputOption;
    
	printf("�����Ͻ� �̿���� �����ϼ���.\n");
  	printf("1. �����̿��(�̿����: �Ե����� + �μӹڹ���)\n2. ��ũ�̿��(�̿����: �Ե�����)\n");
   	scanf("%d", &inputTicketing);	
		RE_INPUT_TICKETING:
		if (!(inputTicketing == 1 || inputTicketing == 2)) {
			printf("\n�ٽ� �Է��� �ּ���.\n");
			printf("�����Ͻ� �̿���� �����ϼ���.\n");
  			printf("1. �����̿��(�̿����: �Ե����� + �μӹڹ���)\n2. ��ũ�̿��(�̿����: �Ե�����)\n");
   			scanf("%d", &inputTicketing);
			goto RE_INPUT_TICKETING;	
		}
	
	printf("\n�����Ͻ� �̿���� �ɼ��� �������ּ���.\n");
   	printf("1. 1Day\n2. After4(���� 4�ú��� ���尡��)\n");
   	scanf("%d", &inputOption);
		RE_INPUT_OPTION:
		if (!(inputOption == 1 || inputOption == 2)) {
			printf("\n�ٽ� �Է��� �ּ���.\n");
			printf("\n�����Ͻ� �̿���� �ɼ��� �������ּ���.\n");
	   		printf("1. 1Day\n2. After4(���� 4�ú��� ���尡��)\n");
	   		scanf("%d", &inputOption);
	   		goto RE_INPUT_OPTION;
		}
   
   	// �ֹι�ȣ �Է�
   	int id, gender;
    printf("\n�ֹε�Ϲ�ȣ�� �Է��ϼ���. ex) 930820-1\n");
    scanf("%d-%d", &id, &gender);
    
   	time_t now;
   	struct tm *t;
   	now = time(NULL);
   	t = localtime(&now);
     
   	int currentYear = t->tm_year + 1900;
   	int currentMonth = t->tm_mon + 1;
   	int currentDay = t->tm_mday;
  	 
   	int year = id / 10000;
   	int month = (id % 10000) / 100; 
   	int day = id % 100;
   	int age, century;
   
	if (gender == 1 || gender == 2) {
    	if (currentMonth > month || currentMonth == month && currentDay < day) {
	    	century = 1900;
			age = currentYear - (century + year);
	    } else {
	        age = currentYear - (century + year) - 1;
	    }
	}
	if (gender == 3 || gender == 4) {
	    if (currentMonth > month || currentMonth == month && currentDay < day) {
	      	century = 2000;
	    	age = currentYear - (century + year);
	    } else {	         
			age = currentYear - (century + year) - 1;
      	}
	}
    
   // ���� ���� 
   // �����̿�� 1day 
   int basicFee;
   
   if (inputTicketing == 1 && inputOption == 1) {
    	if(age > 18 && age < 65) {
        	basicFee = FULL_TICKET_1DAY_ADULT;
      	} else if (age >= 13 && age <= 18) {
         	basicFee = FULL_TICKET_1DAY_TEEN;
      	} else if ((age >= 3 && age <= 12) || age >= 65) {
        	basicFee = FULL_TICKET_1DAY_CHILD;
      	} else {
         	basicFee = 0;
      	}
   } 
   // �����̿�� After4 
   if (inputTicketing == 1 && inputOption == 2) {
      	if(age > 18 && age < 65) {
         	basicFee = FULL_TICKET_AFTER4_ADULT;
      	} else if (age >= 13 && age <= 18) {
         	basicFee = FULL_TICKET_AFTER4_TEEN;
      	} else if ((age >= 3 && age <= 12) || age >= 65) {
         	basicFee = FULL_TICKET_AFTER4_CHILD;
      	} else {
         	basicFee = 0;
     	}
   } 
   // ��ũ�̿�� 1day 
   if (inputTicketing == 2 && inputOption == 1) {
      	if(age > 18 && age < 65) {
         	basicFee = PARK_TICKET_1DAY_ADULT;
      	} else if (age >= 13 && age <= 18) {
         	basicFee = PARK_TICKET_1DAY_TEEN;
      	} else if ((age >= 3 && age <= 12) || age >= 65) {
         	basicFee = PARK_TICKET_1DAY_CHILD;
      	} else {
         	basicFee = 0;
      	}
   } 
   // �����̿�� After4 
   if (inputTicketing == 2 && inputOption == 2) {
      	if(age > 18 && age < 65) {
         	basicFee = PARK_TICKET_AFTER4_ADULT;
      	} else if (age >= 13 && age <= 18) {
         	basicFee = PARK_TICKET_AFTER4_TEEN;
      	} else if ((age >= 3 && age <= 12) || age >= 65) {
         	basicFee = PARK_TICKET_AFTER4_CHILD;
      	} else {
         	basicFee = 0;
      	}
   } 
   
   if (age >= 1 && age < 3 && ) {
   		basicFee = BABY;
   }
   
   int numberOfTicket;
   printf("\n������ �ֹ��Ͻðڽ��ϱ�?\n");
   scanf("%d", &numberOfTicket);
   
   // ������ ����(��� ��� ����)  
   printf("\n�������� �����ϼ���.\n(���ɿ� ���� ��������� �ڵ� ����˴ϴ�.)\n\n");
   printf("0. ������� ����\n");
   printf("1. ����� ���\n");
   printf("2. ���������� ���\n");
   printf("3. �ް��庴 ���\n");
   printf("4. �ӻ�� ���\n");
   printf("5. �ٵ��� �ູī�� ���\n");
   
   int specialDiscount;
   int totalFee;
   int discountNum;
   int countNum;
   scanf("%d", &specialDiscount);
   
   // 0. ������� ���� 
   if (specialDiscount == 0) {
      totalFee = basicFee * numberOfTicket;
   }
   // 1.����� ��� 
   if (specialDiscount == 1) {
      	if (numberOfTicket == 1) {
         	totalFee =  basicFee * DISCOUNT_RATE_DISABLED;
      	} else if (numberOfTicket == 2) {
         	totalFee = basicFee * DISCOUNT_RATE_DISABLED * 2;
      	} else {
         	totalFee = (basicFee * DISCOUNT_RATE_DISABLED * 2) + basicFee * (numberOfTicket - 2);
      	}
   }
   // 2. ���������� ��� 
   if (specialDiscount == 2) {
      	if (numberOfTicket == 1) {
         	totalFee = basicFee * DISCOUNT_RATE_MAN_OF_MERIT;
     	} else if (numberOfTicket == 2) {
         	totalFee = basicFee * DISCOUNT_RATE_MAN_OF_MERIT * 2;
      	} else {
         	totalFee = (basicFee * DISCOUNT_RATE_MAN_OF_MERIT * 2) + basicFee * (numberOfTicket - 2);
      	}
   } 
   // 3. �ް��庴 ��� 
   if (specialDiscount == 3) {
      	if(numberOfTicket == 1) {
         	totalFee = basicFee * DISCOUNT_RATE_SOLDIER;
      	} else if(numberOfTicket == 2) {
         	totalFee = basicFee * DISCOUNT_RATE_SOLDIER * 2;
      	} else {
         	totalFee = (basicFee * DISCOUNT_RATE_SOLDIER * 2) + basicFee * (numberOfTicket - 2);
      	}
   }
   // 4. �ӻ�� ��� 
   if (gender == 2 || gender == 4) {
      	if(specialDiscount == 4) {
         	if(numberOfTicket == 1) {
            	totalFee = basicFee * DISCOUNT_RATE_PREGNANT;
         	} else {
            	totalFee = (basicFee * DISCOUNT_RATE_PREGNANT) + basicFee * (numberOfTicket - 1);
         	}
      	}
   }   

   // 5. �ٵ��� ��� 
   if(specialDiscount == 5) {
      	if(numberOfTicket == 1) {
         	totalFee = basicFee * DISCOUNT_RATE_CHILDREN_CARD;
      	} else {
         	totalFee = (basicFee * DISCOUNT_RATE_CHILDREN_CARD) + basicFee * (numberOfTicket - 1);
     	}
   }  
   
   printf("\n������ %d�� �Դϴ�. �����մϴ�.", totalFee);
   
   printf("\n��� �߱��Ͻðڽ��ϱ�?\n1. Ƽ�� �߱�\n2. ����");
   
}
