// SAGAR BALWANI
//
// Try to run this program in VSCode or any other compiler if it does not work in your Existing Compiler or Software
// A Sample Input and Output is Given at the End of the Code
//
// Billing_system.c - A Program to for a billling system of an Ice-cream shop with the output as an bill.
// Input:	(1) The Bill Number
//		(2) Index number of the item followed by the quantity of the input
//		(3) If the Input is finished, enter '0 0' to end the input and print output
// Output: A computer generated Bill of the shop with GST included.
// Logic: 
// 	Step1: Take all the input and then store it in an array
// 	Step2: Calculate the prices as per the quantity and get a total amount
// 	Step3: Print the prices along with the item name and print total
// 	Step4: Calculate Discount and GST to be applied and print it in the separate slab
// 	Step5: Print the Final amount to be paid
//
//
# include <stdio.h>		// For Standard Input Type
# include <time.h>		// For Getting Current Time
# include <math.h>		// For Getting Round_off value
//
//
void menu(void);		// For printing The menu and accepting output
//
//
int price[55] = {50, 60, 50, 60, 75, 60, 75, 60, 75, 80, 75, 80, 80, 100, 120, 125, 150, 46, 94, 224, 80, 300, 20, 15, 23, 29, 10, 14, 250, 330, 250, 330, 370, 330, 360, 330, 360, 360, 360, 330, 100, 40, 103, 90, 115, 50, 20, 20, 20, 20, 20, 20, 12, 50, 20};		// All prices initialized
//	above is complete price list
//
char names[55][50] = {"Vanilla Ice Cream                         ", "Butter Scotch Ice Cream                   ", "Strawberry Ice Cream                      ", "Chocolate Ice Cream                       ", "Raj Bhog Ice Cream                        ", "Alphonso Mango Ice Cream                  ", "ChocoChips Ice Cream                      ", "Green Pista Ice Cream                     ", "Brownie Blast Ice Cream                   ", "Kesar Pista Ice Cream                     ", "Cookies and Cream Ice Cream               ", "Amul Dark Chocolate Bars                  ", "Amul Milk Chocolate Bars                  ", "Amul Fruit and Nut Chocolate Bars         ", "Amul Chocominis Truffles                  ", "Amul Sugar Free Dark Chocolate Bars       ", "Amul Fruit N Nut Chocolate Bars 150g      ", "Amul Pasteurised Salted Butter 100g       ", "Amul Pasteurised Salted Butter 200g       ", "Amul Pasteurised Salted Butter 500g       ", "Amul Fresh Paneer 200g                    ", "Amul Fresh Paneer 1kg                     ", "Amul Masti Dahi 200g CUP                  ", "Amul Masti Dahi 200g PACKET               ", "Amul Milk Taaza 500ml                     ", "Amul Milk Gold 500ml                      ", "Amul Cheese Slice 20g                     ", "Amul Cheese Cube 25g                      ", "Vanilla Ice Cream (Family Pack)           ", "Butter Scotch Ice Cream (Family Pack)     ", "Strawberry Ice Cream (Family Pack)        ", "Chocolate Ice Cream (Family Pack)         ", "Raj Bhog Ice Cream (Family Pack)          ", "Alphonso Mango Ice Cream (Family Pack)    ", "ChocoChips Ice Cream (Family Pack)        ", "Green Pista Ice Cream (Family Pack)       ", "Brownie Blast Ice Cream (Family Pack)     ", "Shahi Anjir Ice Cream (Family Pack)       ", "Cookies and Cream Ice Cream (Family Pack) ", "Tutti Fruiti Ice Cream (Family Pack)      ", "Amul Elaichi Shrikhand 500g               ", "Amul Elaichi Shrikhand 200g               ", "Amul Kesar Shrikhand 500g                 ", "Amul Mango Shrikhand 500g                 ", "Amul Badam Pista Shrikhand 500g           ", "Amul Badam Pista Shrikhand 200g           ", "Amul Kool Elaichi                         ", "Amul Kool Badam                           ", "Amul Kool Kesar                           ", "Amul Kool Koko - Chocolate Milk           ", "Amul Kool Rose Flavour                    ", "Amul Kool Cafe                            ", "Amul Masti ButterMilk 200ml               ", "Amul Masti ButterMilk 1L                  ", "Amul Lassi                                "};		// All Product Names Initialized
//		above is list of all product name with respect to its price 
//
int inp[60][2], item_count;	// Global Variables
//
//
void main() {
	int i, sum = 0, total_value = 0, value, n;
	float ori_am, disc;			// ori_am for original value in gst and disc has value of discount
    // For Current time
    time_t t;		//
    time(&t);		// for getting current date and time
    //
    //
	printf("Enter The BILL Number: ");
	scanf("%d", &n);
    menu();
    //
	 system("cls");
	//
    printf("_________________________________________________________________________________________________________\n");
    printf("---------------------------------------------AMUL GODHRA-------------------------------------------------\n");
    printf("_________________________________________________________________________________________________________\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("                                             TAX INVOICE                                                 \n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("    Bill No.:- %d                            		      Bill Date:- %s           \n", n, ctime(&t));
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("    Item                                      Quantity                  Rate                  Value\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    //
    for (i = 0; i < item_count; i++) {
   	sum = sum + inp[i][1];				//	getting total number of quantity
    	value = price[inp[i][0]] * inp[i][1];			// multiplying price and quantity to get it total value
    	total_value = total_value + value;				// getting total value
		printf("    %d) %s%d                      %d                   %d\n", i+1, names[inp[i][0]], inp[i][1], price[inp[i][0]], value);
    }	
    //
    ori_am = total_value * 0.1;				// gst on total price
	ori_am = total_value - ori_am;			// value before gst
    disc = total_value * 0.02;				// discount on total value
	disc = total_value - disc;				// total value after discount
    printf("=========================================================================================================\n");
    printf("    ITEMS: %d                              QUANTITY: %d                             TOTAL VALUE: %d \n", i, sum, total_value);
    printf("=========================================================================================================\n");
    printf("=========================================================================================================\n");
    printf("                                             GST DETAILS                                                 \n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("    GST                Original                  CGST                    SGST                 Total\n");
    printf("    IND                 Amount                                                               Amount\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("    1)                  %.2f                   5%c                      5%c                    %d\n", ori_am, '%', '%', total_value);
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("    Discount @2%c                                                                             %.2f\n", '%', disc);
    printf("    ROUND OFF AMOUNT                                                                         %.1f\n", round(disc));
    printf("=========================================================================================================\n");
    printf("    AMMOUNT TO BE PAID: %.2f \n", round(disc));
    printf("=========================================================================================================\n");
    //
//
}
//
//
void menu(void) {				// Function for displaying menu
	int i;
	printf("============================================================================================================================\n");
	printf("------------------------------------------------------------MENU------------------------------------------------------------\n");
	printf("============================================================================================================================\n\n");
	printf("	ICE CREAMS									FAMILY PACKS\n\n");
	printf("(1) Vanilla Ice Cream								(29) Vanilla Ice Cream (Family Pack)\n");
	printf("(2) Butter Scotch Ice Cream							(30) Butter Scotch Ice Cream (Family Pack)\n");
	printf("(3) Strawberry Ice Cream							(31) Strawberry Ice Cream (Family Pack)\n");
	printf("(4) Chocolate Ice Cream								(32) Chocolate Ice Cream (Family Pack)\n");
	printf("(5) Raj Bhog Ice Cream								(33) Raj Bhog Ice Cream (Family Pack)\n");
	printf("(6) Alphonso Mango Ice Cream							(34) Alphonso Mango Ice Cream (Family Pack)\n");
	printf("(7) ChocoChips Ice Cream							(35) ChocoChips Ice Cream (Family Pack)\n");
	printf("(8) Green Pista Ice Cream							(36) Green Pista Ice Cream (Family Pack)\n");
	printf("(9) Brownie Blast Ice Cream							(37) Brownie Blast Ice Cream (Family Pack)\n");
	printf("(10) Kesar Pista Ice Cream							(38) Shahi Anjir Ice Cream (Family Pack)\n");
	printf("(11) Cookies and Cream Ice Cream						(39) Cookies and Cream Ice Cream (Family Pack)\n");
	printf("										(40) Tutti Fruiti Ice Cream (Family Pack)\n\n");
	printf("............................................................................................................................\n");
	printf("	CHOCOLATES									SHRIKHANDS\n\n");
	printf("(12) Amul Dark Chocolate Bars							(41) Amul Elaichi Shrikhand 500g (100)\n");
	printf("(13) Amul Milk Chocolate Bars							(42) Amul Elaichi Shrikhand 200g (40)\n");
	printf("(14) Amul Fruit and Nut Chocolate Bars						(43) Amul Kesar Shrikhand 500g (103)\n");
	printf("(15) Amul Chocominis Truffles							(44) Amul Mango Shrikhand 500g (90)\n");
	printf("(16) Amul Sugar Free Dark Chocolate Bars					(45) Amul Badam Pista Shrikhand 500g (115)\n");
	printf("(17) Amul Fruit N Nut Chocolate Bars 150g					(46) Amul Badam Pista Shrikhand 200g (50)\n\n");
	printf("............................................................................................................................\n");
	printf("	Other Items									DRINKS\n\n");
	printf("(18) Amul Pasteurised Salted Butter 100g					(47) Amul Kool Elaichi\n");
	printf("(19) Amul Pasteurised Salted Butter 200g					(48) Amul Kool Badam\n");
	printf("(20) Amul Pasteurised Salted Butter 500g					(49) Amul Kool Kesar\n");
	printf("(21) Amul Fresh Paneer 200g							(50) Amul Kool Koko - Chocolate Milk\n");
	printf("(22) Amul Fresh Paneer 1kg							(51) Amul Kool Rose Flavour\n");
	printf("(23) Amul Masti Dahi 200g CUP (20)						(52) Amul Kool Cafe\n");
	printf("(24) Amul Masti Dahi 200g PACKET (15)						(53) Amul Masti ButterMilk 200ml (12)\n");
	printf("(25) Amul Milk Taaza 500ml							(54) Amul Masti ButterMilk 1L (50)\n");
	printf("(26) Amul Milk Gold 500ml							(55) Amul Lassi\n");
	printf("(27) Amul Cheese Slice 20g (10)\n");
	printf("(28) Amul Cheese Cube 25g (14)\n");
	printf("============================================================================================================================\n");
	printf("\nEnter the number of item and quantity: \n");
	//
	for (i = 0; inp[i-1][0] != (-1); i++) {
		scanf("%d%d", &inp[i][0], &inp[i][1]);		// Taking input from user
		inp[i][0]--;		// if item no. in input is 28 then in the array it is 27. So decreasing the input value by 1
	}
	//
	i--;				// For removing the final input 0 0 
	item_count = i;		// assigning global variable item_count with the value of i
}
//
//
/*
//
Sample Input:
Enter The BILL Number: 90

Enter the number of item and quantity:
23 5
55 4
17 1
0 0


OUTPUT:

The Output is attached in the same folder below the code
*/
//
// EOF
