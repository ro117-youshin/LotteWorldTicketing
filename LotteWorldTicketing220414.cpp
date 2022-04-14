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
   
   // Ticketing
   int inputTicketing, inputOption;
   
   printf("�̿���� �����ϼ���.\n");
   printf("1. �����̿��(�̿����: �Ե����� + �μӹڹ���)\n2. ��ũ�̿��(�̿����: ��\������)\n");
   scanf("%d", &inputTicketing);
   
   printf("\n�����Ͻ� �̿���� �ɼ��� �������ּ���.\n");
   printf("1. 1Day\n2. After4(���� 4�ú��� ���尡��)\n");
   scanf("%d", &inputOption);
   
   // �ֹι�ȣ �Է� 
   long long inputIDNumber;
   printf("\n�ֹι�ȣ�� �Է��ϼ���.\n");
   scanf("%llu", &inputIDNumber);
   
   time_t now;
   struct tm *t;
   now = time(NULL);
   t = localtime(&now);
     
   int currentYear = t->tm_year + 1900;
   int currentMonth = t->tm_mon + 1;
   int currentDay = t->tm_mday;
   
   int year = inputIDNumber / 100000000000;
   int month = (inputIDNumber % 100000000000) / 1000000000; 
   int day = (inputIDNumber % 1000000000) / 10000000;
   int bornIn = (inputIDNumber % 100000000) / 1000000;
   int age;
   
   if (bornIn == 1 || bornIn == 2) {
      if (currentMonth > month || currentMonth == month && currentDay < day) {
         age = currentYear - (1900 + year);
      } else {
         age = currentYear - (1900 + year) - 1;
      }
   } 
   if (bornIn == 3 || bornIn == 4) {
      if (currentMonth > month || currentMonth == month && currentDay < day) {
         age = currentYear - (2000 + year);
      } else {
         age = currentYear - (2000 + year) - 1;
      }
   }
    
   // ���� ���� 
   // �����̿�� 1day 
   int amountOfAgeDiscount;
   
   if (inputTicketing == 1 && inputOption == 1) {
      if(age > 18 && age < 65) {
         amountOfAgeDiscount = FULL_TICKET_1DAY_ADULT;
      } else if (age >= 13 && age <= 18) {
         amountOfAgeDiscount = FULL_TICKET_1DAY_TEEN;
      } else if ((age >= 3 && age <= 12) || age >= 65) {
         amountOfAgeDiscount = FULL_TICKET_1DAY_CHILD;
      } else {
         amountOfAgeDiscount = 0;
      }
   } 
   // �����̿�� After4 
   if (inputTicketing == 1 && inputOption == 2) {
      if(age > 18 && age < 65) {
         amountOfAgeDiscount = FULL_TICKET_AFTER4_ADULT;
      } else if (age >= 13 && age <= 18) {
         amountOfAgeDiscount = FULL_TICKET_AFTER4_TEEN;
      } else if ((age >= 3 && age <= 12) || age >= 65) {
         amountOfAgeDiscount = FULL_TICKET_AFTER4_CHILD;
      } else {
         amountOfAgeDiscount = 0;
      }
   } 
   // ��ũ�̿�� 1day 
   if (inputTicketing == 2 && inputOption == 1) {
      if(age > 18 && age < 65) {
         amountOfAgeDiscount = PARK_TICKET_1DAY_ADULT;
      } else if (age >= 13 && age <= 18) {
         amountOfAgeDiscount = PARK_TICKET_1DAY_TEEN;
      } else if ((age >= 3 && age <= 12) || age >= 65) {
         amountOfAgeDiscount = PARK_TICKET_1DAY_CHILD;
      } else {
         amountOfAgeDiscount = 0;
      }
   } 
   // �����̿�� After4 
   if (inputTicketing == 2 && inputOption == 2) {
      if(age > 18 && age < 65) {
         amountOfAgeDiscount = PARK_TICKET_AFTER4_ADULT;
      } else if (age >= 13 && age <= 18) {
         amountOfAgeDiscount = PARK_TICKET_AFTER4_TEEN;
      } else if ((age >= 3 && age <= 12) || age >= 65) {
         amountOfAgeDiscount = PARK_TICKET_AFTER4_CHILD;
      } else {
         amountOfAgeDiscount = 0;
      }
   } 
   
//   printf("%d", amountOfAgeDiscount);
   
   int numberOfTicket;
   printf("\n������ �ֹ��Ͻðڽ��ϱ�?\n");
   scanf("%d", &numberOfTicket);
   
   // ������ ����(��� ��� ����)  
   printf("\n�������� �����ϼ���.\n���ɿ� ���� ��������� �ڵ� ����˴ϴ�.\n");
   printf("0. ������� ����\n1. ����� ���\n2. ���������� ���\n3. �ް��庴 ���\n4. �ӻ�� ���\n5. �ٵ��� �ູī�� ���\n");
   
   int specialDiscount;
   int totalfee;
   int discountNum;
   int countNum;
   scanf("%d", &specialDiscount);
   
   // 0. ������� ���� 
   if (specialDiscount == 0) {
      totalfee = amountOfAgeDiscount * numberOfTicket;
   }
   // 1.����� ��� 
   if (specialDiscount == 1) {
      if (numberOfTicket == 1) {
         totalfee =  amountOfAgeDiscount * DISCOUNT_RATE_DISABLED;
      } else if (numberOfTicket == 2) {
         totalfee = amountOfAgeDiscount * DISCOUNT_RATE_DISABLED * 2;
      } else {
         totalfee = (amountOfAgeDiscount * DISCOUNT_RATE_DISABLED * 2) + amountOfAgeDiscount * (numberOfTicket - 2);
      }
   }
   // 2. ���������� ��� 
   if (specialDiscount == 2) {
      if (numberOfTicket == 1) {
         totalfee = amountOfAgeDiscount * DISCOUNT_RATE_MAN_OF_MERIT;
      } else if (numberOfTicket == 2) {
         totalfee = amountOfAgeDiscount * DISCOUNT_RATE_MAN_OF_MERIT * 2;
      } else {
         totalfee = (amountOfAgeDiscount * DISCOUNT_RATE_MAN_OF_MERIT * 2) + amountOfAgeDiscount * (numberOfTicket - 2);
      }
   } 
   // 3. �ް��庴 ��� 
   if (specialDiscount == 3) {
      if(numberOfTicket == 1) {
         totalfee = amountOfAgeDiscount * DISCOUNT_RATE_SOLDIER;
      } else if(numberOfTicket == 2) {
         totalfee = amountOfAgeDiscount * DISCOUNT_RATE_SOLDIER * 2;
      } else{
         totalfee = (amountOfAgeDiscount * DISCOUNT_RATE_SOLDIER * 2) + amountOfAgeDiscount * (numberOfTicket - 2);
      }
   }
   // 4. �ӻ�� ��� 
   if (bornIn == 2 || bornIn == 4) {
      if(specialDiscount == 4) {
         if(numberOfTicket == 1) {
            totalfee = amountOfAgeDiscount * DISCOUNT_RATE_PREGNANT;
         } else {
            totalfee = (amountOfAgeDiscount * DISCOUNT_RATE_PREGNANT) + amountOfAgeDiscount * (numberOfTicket - 1);
         }
      }
   }   

   // 5. �ٵ��� ��� 
   if(specialDiscount == 5) {
      if(numberOfTicket == 1) {
         totalfee = amountOfAgeDiscount * DISCOUNT_RATE_CHILDREN_CARD;
      } else {
         totalfee = (amountOfAgeDiscount * DISCOUNT_RATE_CHILDREN_CARD) + amountOfAgeDiscount * (numberOfTicket - 1);
      }
   }  
   
   printf("\n������ %d�� �Դϴ�.", totalfee);
   
   printf("\n��� �߱��Ͻðڽ��ϱ�?\n1. Ƽ�� �߱�\n2. ����");
   
}
