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
   // 베이비 
   const int BABY = 15000;
   // 우대할인
   const float DISCOUNT_RATE_DISABLED = 0.5, DISCOUNT_RATE_MAN_OF_MERIT = 0.5, DISCOUNT_RATE_SOLDIER = 0.51, DISCOUNT_RATE_PREGNANT = 0.5, DISCOUNT_RATE_CHILDREN_CARD = 0.7;
   
   int ticketingArr[] = {0}; 
   
    // Ticketing
    int inputTicketing, inputOption;
    
	printf("구매하실 이용권을 선택하세요.\n");
  	printf("1. 종합이용권(이용범위: 롯데월드 + 민속박물관)\n2. 파크이용권(이용범위: 롯데월드)\n");
   	scanf("%d", &inputTicketing);	
		RE_INPUT_TICKETING:
		if (!(inputTicketing == 1 || inputTicketing == 2)) {
			printf("\n다시 입력해 주세요.\n");
			printf("구매하실 이용권을 선택하세요.\n");
  			printf("1. 종합이용권(이용범위: 롯데월드 + 민속박물관)\n2. 파크이용권(이용범위: 롯데월드)\n");
   			scanf("%d", &inputTicketing);
			goto RE_INPUT_TICKETING;	
		}
	
	printf("\n선택하신 이용권의 옵션을 선택해주세요.\n");
   	printf("1. 1Day\n2. After4(오후 4시부터 입장가능)\n");
   	scanf("%d", &inputOption);
		RE_INPUT_OPTION:
		if (!(inputOption == 1 || inputOption == 2)) {
			printf("\n다시 입력해 주세요.\n");
			printf("\n선택하신 이용권의 옵션을 선택해주세요.\n");
	   		printf("1. 1Day\n2. After4(오후 4시부터 입장가능)\n");
	   		scanf("%d", &inputOption);
	   		goto RE_INPUT_OPTION;
		}
   
   	// 주민번호 입력
   	int id, gender;
    printf("\n주민등록번호를 입력하세요. ex) 930820-1\n");
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
    
   // 연령 할인 
   // 종합이용권 1day 
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
   // 종합이용권 After4 
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
   // 파크이용권 1day 
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
   // 종합이용권 After4 
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
   printf("\n몇장을 주문하시겠습니까?\n");
   scanf("%d", &numberOfTicket);
   
   // 우대사항 할인(상시 우대 정보)  
   printf("\n우대사항을 선택하세요.\n(연령에 따른 요금할인은 자동 적용됩니다.)\n\n");
   printf("0. 우대조건 없음\n");
   printf("1. 장애인 우대\n");
   printf("2. 국가유공자 우대\n");
   printf("3. 휴가장병 우대\n");
   printf("4. 임산부 우대\n");
   printf("5. 다둥이 행복카드 우대\n");
   
   int specialDiscount;
   int totalFee;
   int discountNum;
   int countNum;
   scanf("%d", &specialDiscount);
   
   // 0. 우대조건 없음 
   if (specialDiscount == 0) {
      totalFee = basicFee * numberOfTicket;
   }
   // 1.장애인 우대 
   if (specialDiscount == 1) {
      	if (numberOfTicket == 1) {
         	totalFee =  basicFee * DISCOUNT_RATE_DISABLED;
      	} else if (numberOfTicket == 2) {
         	totalFee = basicFee * DISCOUNT_RATE_DISABLED * 2;
      	} else {
         	totalFee = (basicFee * DISCOUNT_RATE_DISABLED * 2) + basicFee * (numberOfTicket - 2);
      	}
   }
   // 2. 국가유공자 우대 
   if (specialDiscount == 2) {
      	if (numberOfTicket == 1) {
         	totalFee = basicFee * DISCOUNT_RATE_MAN_OF_MERIT;
     	} else if (numberOfTicket == 2) {
         	totalFee = basicFee * DISCOUNT_RATE_MAN_OF_MERIT * 2;
      	} else {
         	totalFee = (basicFee * DISCOUNT_RATE_MAN_OF_MERIT * 2) + basicFee * (numberOfTicket - 2);
      	}
   } 
   // 3. 휴가장병 우대 
   if (specialDiscount == 3) {
      	if(numberOfTicket == 1) {
         	totalFee = basicFee * DISCOUNT_RATE_SOLDIER;
      	} else if(numberOfTicket == 2) {
         	totalFee = basicFee * DISCOUNT_RATE_SOLDIER * 2;
      	} else {
         	totalFee = (basicFee * DISCOUNT_RATE_SOLDIER * 2) + basicFee * (numberOfTicket - 2);
      	}
   }
   // 4. 임산부 우대 
   if (gender == 2 || gender == 4) {
      	if(specialDiscount == 4) {
         	if(numberOfTicket == 1) {
            	totalFee = basicFee * DISCOUNT_RATE_PREGNANT;
         	} else {
            	totalFee = (basicFee * DISCOUNT_RATE_PREGNANT) + basicFee * (numberOfTicket - 1);
         	}
      	}
   }   

   // 5. 다둥이 우대 
   if(specialDiscount == 5) {
      	if(numberOfTicket == 1) {
         	totalFee = basicFee * DISCOUNT_RATE_CHILDREN_CARD;
      	} else {
         	totalFee = (basicFee * DISCOUNT_RATE_CHILDREN_CARD) + basicFee * (numberOfTicket - 1);
     	}
   }  
   
   printf("\n가격은 %d원 입니다. 감사합니다.", totalFee);
   
   printf("\n계속 발권하시겠습니까?\n1. 티켓 발권\n2. 종료");
   
}
