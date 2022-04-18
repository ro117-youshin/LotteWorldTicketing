#include <stdio.h>
#include <time.h>

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
// ���� 
const int MIN_ADULT_AGE = 19, MAX_ADULT_AGE = 64, MIN_TEEN_AGE = 13, MAX_TEEN_AGE = 18, MIN_CHILD_AGE = 3, MAX_CHILD_AGE = 12 , MIN_BABY_AGE = 1, MAX_BABY_AGE = 3;
// �������
const float DISCOUNT_RATE_DISABLED = 0.5, DISCOUNT_RATE_MAN_OF_MERIT = 0.5, DISCOUNT_RATE_SOLDIER = 0.51, DISCOUNT_RATE_PREGNANT = 0.5, DISCOUNT_RATE_CHILDREN_CARD = 0.7;
// 2���� �迭�� ���� �� Ÿ�� ���ȭ, 0. �̿�� 1. �ɼ� 2. ���ɿ� ���� ���ΰ��� 3. Ƽ�� �� �� 4. ���� 5. ������ 
const int SAVE_TICKETING = 0, SAVE_OPTION = 1, SAVE_BASIC_FEE_TYPE = 2, SAVE_NUMBER_OF_TICKET = 3, SAVE_TOTAL_FEE = 4, SAVE_SPECIAL_DISCOUNT = 5;

int orderList[10][10] = {0};
int orderCount;
int basicFeeType, continueButton, finalContinueButton;
int inputTicketing, inputOption, id, gender, age, century, numberOfTicket, basicFee, specialDiscount, totalFee, finalFee;
	    
void ticketing () {
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
}
// �ֹε�Ϲ�ȣ �Է� 
void inputId () {
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
		   	
	   	if (gender == 1 || gender == 2) {
	     	century = 1900;
			if (currentMonth > month || currentMonth == month && currentDay < day) {
	           	age = currentYear - (century + year);
	       	} else {
	           	age = currentYear - (century + year) - 1;
	       	}
	  	}
	   	if (gender == 3 || gender == 4) {
	       	century = 2000;
			if (currentMonth > month || currentMonth == month && currentDay < day) {
	        	age = currentYear - (century + year);
	       	} else {            
				age = currentYear - (century + year) - 1;
	        }
	   	}
}
// ������ ��� �Է� 
void inputNumberOfTicket () {
	printf("\n������ �ֹ��Ͻðڽ��ϱ�?(�ִ�10��)\n");
	scanf("%d", &numberOfTicket);
	// 10�� �̻��� ��� ���Է� 
	RE_INPUT_NUMBEROFTICKET:
	if (numberOfTicket > 10) {
		printf("10�� ���Ϸ� �Է��� �ּ���.\n");
		printf("\n������ �ֹ��Ͻðڽ��ϱ�?(�ִ�10��)\n");
		scanf("%d", &numberOfTicket);
		goto RE_INPUT_NUMBEROFTICKET;
	}
}

void inputAgeDiscount() {
	if (inputTicketing == 1 && inputOption == 1) {
	       	if(age >= MIN_ADULT_AGE && age <= MAX_ADULT_AGE) {
	           	basicFee = FULL_TICKET_1DAY_ADULT;
	           	basicFeeType = 0;
	        } else if (age >= MIN_TEEN_AGE && age <= MAX_TEEN_AGE) {
	            basicFee = FULL_TICKET_1DAY_TEEN;
	            basicFeeType = 1;
	        } else if ((age >= MIN_CHILD_AGE && age <= MAX_CHILD_AGE) || age >= MAX_ADULT_AGE) {
	           	basicFee = FULL_TICKET_1DAY_CHILD;
	           	basicFeeType = 2;
	        }
	    } 
	    // �����̿�� After4 
	    if (inputTicketing == 1 && inputOption == 2) {
	        if(age >= MIN_ADULT_AGE && age <= MAX_ADULT_AGE) {
	        	basicFee = FULL_TICKET_AFTER4_ADULT;
	            basicFeeType = 0;
	        } else if (age >= MIN_TEEN_AGE && age <= MAX_TEEN_AGE) {
	            basicFee = FULL_TICKET_AFTER4_TEEN;
	            basicFeeType = 1;
	        } else if ((age >= MIN_CHILD_AGE && age <= MAX_CHILD_AGE) || age >= MAX_ADULT_AGE) {
	            basicFee = FULL_TICKET_AFTER4_CHILD;
	            basicFeeType = 2;
	        }
	    } 
	    // ��ũ�̿�� 1day 
	    if (inputTicketing == 2 && inputOption == 1) {
	        if(age >= MIN_ADULT_AGE && age <= MAX_ADULT_AGE) {
	            basicFee = PARK_TICKET_1DAY_ADULT;
	            basicFeeType = 0;
	        } else if (age >= MIN_TEEN_AGE && age <= MAX_TEEN_AGE) {
	            basicFee = PARK_TICKET_1DAY_TEEN;
	            basicFeeType = 1;
	        } else if ((age >= MIN_CHILD_AGE && age <= MAX_CHILD_AGE) || age >= MAX_ADULT_AGE) {
	            basicFee = PARK_TICKET_1DAY_CHILD;
	            basicFeeType = 2;
	        } 
	    } 
	    // �����̿�� After4 
	    if (inputTicketing == 2 && inputOption == 2) {
	        if(age >= MIN_ADULT_AGE && age <= MAX_ADULT_AGE) {
	            basicFee = PARK_TICKET_AFTER4_ADULT;
	            basicFeeType = 0;
	        } else if (age >= MIN_TEEN_AGE && age <= MAX_TEEN_AGE) {
	            basicFee = PARK_TICKET_AFTER4_TEEN;
	            basicFeeType = 1;
	        } else if ((age >= MIN_CHILD_AGE && age <= MAX_CHILD_AGE) || age >= MAX_ADULT_AGE) {
	            basicFee = PARK_TICKET_AFTER4_CHILD;
	            basicFeeType = 2;
	        } 
	    }
	    // ���̺� 
	    if (age < MIN_BABY_AGE) {
	      	basicFee = 0;
	      	basicFeeType = 3;
		} 
		if (age >= MIN_BABY_AGE && age < MAX_BABY_AGE && numberOfTicket >= 10) {
		  	basicFee = BABY;
		  	basicFeeType = 3;
		} else if (age >= MIN_BABY_AGE && age < MAX_BABY_AGE && numberOfTicket < 10) {
		  	basicFee = 0;
		  	basicFeeType = 3;
		}
}

void inputSpecialDiscount () {
	do {
		// ������ ����(��� ��� ����)  
		printf("\n�������� �����ϼ���.\n(���ɿ� ���� ��������� �ڵ� ����˴ϴ�.)\n\n");
		printf("0. ������� ����\n");
		printf("1. ����� ���\n");
		printf("2. ���������� ���\n");
		printf("3. �ް��庴 ���\n");
		printf("4. �ӻ�� ���\n");
		printf("5. �ٵ��� �ູī�� ���\n");
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
	    if(specialDiscount == 5 ) {
	        if(numberOfTicket == 1) {
	           	totalFee = basicFee * DISCOUNT_RATE_CHILDREN_CARD;
	        } else {
	           	totalFee = (basicFee * DISCOUNT_RATE_CHILDREN_CARD) + basicFee * (numberOfTicket - 1);
	       	}
	    }
	} while (!(specialDiscount == 0 || specialDiscount == 1 || specialDiscount == 2 || specialDiscount == 3 || specialDiscount == 4 || specialDiscount == 5));
}

void printOut () {
   	printf("�̿��\t\t�ɼ�\t����\t���\t����\t������\n");
   	for (int index = 0; index < orderCount; index++) {
      	// ������ �̿�� ��� 
		if (orderList[index][SAVE_TICKETING] == 1) {
         	printf("�����̿��\t");
      	} else {
         	printf("��ũ�̿��\t");
      	}
      	// ������ �ɼ� ��� 
      	if(orderList[index][SAVE_OPTION] == 1) {
         	printf("1Day\t");
      	} else {
         	printf("After4\t");
      	}
      	// �Է��� �ֹε�Ϲ�ȣ�� ���� ���� ��� 
     	if(orderList[index][SAVE_BASIC_FEE_TYPE] == 0) {
         	printf("�\t");
      	} else if (orderList[index][SAVE_BASIC_FEE_TYPE] == 1) {
         	printf("û�ҳ�\t");
      	} else if (orderList[index][SAVE_BASIC_FEE_TYPE] == 2) {
         	printf("���\t"); 
      	} else if (orderList[index][SAVE_BASIC_FEE_TYPE] == 3) {
         	printf("���̺�\t");
      	}
      	// Ƽ�� ��� ��� 
      	printf("%d\t", orderList[index][SAVE_NUMBER_OF_TICKET]);
      	// ���� ��� 
      	printf("%d\t", orderList[index][SAVE_TOTAL_FEE]);
      	// ������  ������ ��� 
      	if (orderList[index][SAVE_SPECIAL_DISCOUNT] == 0) {
         	printf("*������ ����\t");
      	} else if (orderList[index][SAVE_SPECIAL_DISCOUNT] == 1) {
         	printf("*����� ���\t");
      	} else if (orderList[index][SAVE_SPECIAL_DISCOUNT] == 2) {
         	printf("*���������� ���\t");
      	} else if (orderList[index][SAVE_SPECIAL_DISCOUNT] == 3) {
         	printf("*�ް��庴 ���\t");
      	} else if (orderList[index][SAVE_SPECIAL_DISCOUNT] == 4) {
         	printf("*�ӻ�� ���\t");
      	} else if (orderList[index][SAVE_SPECIAL_DISCOUNT] == 5) {
         	printf("*�ٵ��� �ູī�� ���\t");
      	}
      	printf("\n");
	}
}
// 
void totalTicketFee() {
	finalFee += totalFee;
}

int main() {
   do {
	   	do {
		    // Ticketing
		   	ticketing();
		   
		    // �ֹι�ȣ �Է�
			inputId();
			
			// �� �� �Է� 
			inputNumberOfTicket();
			
		    // ���� ����  
		    inputAgeDiscount();
		    
		    // ������ ����(��� ��� ����) 
		    inputSpecialDiscount();
			
			// Ƽ�� �Ѿ� 
			totalTicketFee();
		
		    orderList [orderCount][SAVE_TICKETING] = inputTicketing; // �̿�� 
		    orderList [orderCount][SAVE_OPTION] = inputOption; // �ɼ� 
		    orderList [orderCount][SAVE_BASIC_FEE_TYPE] = basicFeeType; // ���ɿ� ���� �ݾ� 
		    orderList [orderCount][SAVE_NUMBER_OF_TICKET] = numberOfTicket; // �� �� 
			orderList [orderCount][SAVE_TOTAL_FEE] = totalFee; // �ݾ� 
		    orderList [orderCount][SAVE_SPECIAL_DISCOUNT] = specialDiscount; // ������ 
		    orderCount++;
			printf("\n��� �߱��Ͻðڽ��ϱ�?\n1. Ƽ�� �߱�\n2. ����\n");
		    scanf("%d", &continueButton);
		    printf("\n");
	   	} while (continueButton == 1);
	   	printf("=====================================================================\n"); 
	   	printOut();
	   	printf("=====================================================================\n"); 
	   	printf("�Ѿ��� %d�� �Դϴ�.\n", finalFee);
   		printf("Ƽ�� ���Ÿ� �����մϴ�. �����մϴ�.\n");
   		printf("\n");
   		printf("��� �����Ͻðڽ��ϱ�? 1. ���ο� �ֹ� 2. ���α׷� ����\n");
   		scanf("%d", &finalContinueButton);
		printf("\n");
		
		// ���ο� �ֹ� �� ���� ���� ���� �ʱ�ȭ 
		orderCount = 0;
		finalFee = 0; 	
   	} while (finalContinueButton == 1);
   	printf("Ƽ�� ���Ÿ� ������ �����մϴ�. �����մϴ�.\n");
   	return 0;
	
}
