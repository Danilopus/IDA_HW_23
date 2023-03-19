#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
//#include <array>

// Service functions prototypes ------------------------------------
int Get_Int_SA();				// String-analysis вариант фильтра INTEGER
int Get_Int_Positive();			// String-Analysis вариант проверки ввода INTEGER_POSITIVE		
int Get_Int_PG();				// peek&get вариант проверки ввода INTEGER	
double Get_Dbl_SA();		// String-analysis вариант фильтра DOUBLE.
double Get_Dbl_Positive();	// String-analysis вариант фильтра DOUBLE_POSITIVE
double Get_Dbl_PG();		// peek&get вариант проверки ввода DOUBLE	
int Get_Random(int Range_min, int Range_max);
double Get_Random(double Range_min, double Range_max);
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max);
template <typename ANY> void Array_Console_Out(ANY arr[], int Size);

// Homework 23 ----------------------------------------------------	

//Task 1
template <typename ANY> void MAX_from_3_and_change(ANY &Num1, ANY &Num2, ANY &Num3)
{
	if (Num1 > Num2)
		Num2 = Num1;
	else Num1 = Num2;
	if (Num2 > Num3)
		Num3 = Num2;
	else Num1 = Num2 = Num3;
}
void MAX_from_3_and_change()
{
	int Num1 = Get_Random(-999,999), Num2 = -Get_Random(-999, 999), Num3 = Get_Random(-999, 999);
	std::cout << "\nTrying with int:\nNum1 = " << Num1 << "\tNum2 = " << Num2 << "\tNum3 = " << Num3;
	MAX_from_3_and_change(Num1, Num2, Num3);
	std::cout << "\nResult:\nNum1 = "<<Num1<<"\tNum2 = " << Num2 << "\tNum3 = " << Num3;

	
	double double_arr[3];
	Fill_Array_with_Random(double_arr, 3, -999.0, 999.0);
	std::cout << "\n\nTrying with double:\nNum1 = " << double_arr[0] << "\tNum2 = " << double_arr[1] << "\tNum3 = " << double_arr[2];
	MAX_from_3_and_change(double_arr[0], double_arr[1], double_arr[2]);
	std::cout << "\nResult:\nNum1 = " << double_arr[0] << "\tNum2 = " << double_arr[1] << "\tNum3 = " << double_arr[2];

}
//Task 2
template <typename any_type_of_data> any_type_of_data& Reference_of_first_negative(any_type_of_data arr[], int Size, int& First_Negative_Index)
{
	First_Negative_Index = -1;
	for (int i = 0; i < Size; i++)
	{
		if (arr[i] < 0)
		{
			First_Negative_Index = i;
			return arr[i];	
		}
	}	
	std::cout << "\n" << "No negative values in array\n";
	return arr[0];
}
void Reference_of_first_negative_demo()
{
	int const Size = 20;
	int Test_Array[Size] = {};
	int First_Negative_Index = {};
	Fill_Array_with_Random(Test_Array, Size, -99, 99);
	std::cout << "\n" << "Array of random integer:";
	Array_Console_Out(Test_Array, Size);	
	std::cout << "\nResult:"<< Reference_of_first_negative(Test_Array, Size, First_Negative_Index)<<" ["<< First_Negative_Index<<"]";
	
	double Test_Array2[Size] = {};
	Fill_Array_with_Random(Test_Array2, Size, 99.0, 999.0);
	std::cout << "\n\n\n" << "Array of random double:";
	Array_Console_Out(Test_Array2, Size);
	std::cout << "\nResult:" << Reference_of_first_negative(Test_Array2, Size, First_Negative_Index) << " [" << First_Negative_Index << "]";
}
//Task 3
template <typename any_type_of_data> void Zeroing_elements_off_array(any_type_of_data arr_1[], int Size_1, any_type_of_data arr_2[], int Size_2, int& Changes_Counter)
{
	Changes_Counter = 0;
	std::cout << "\nElements changed: ";
	for (int i = 0; i < Size_1; i++)
		for (int k = 0; k < Size_2; k++)
			if (*(arr_1 + i) == *(arr_2 + k)&& *(arr_2 + k)!=0)
			{
				*(arr_2 + k) = 0;
				Changes_Counter++;
				std::cout << "[" << k << "] ";
			}
}
void Zeroing_elements_off_array_demo()
{
	int const Size_1 = 10, Size_2=20;
	int Test_Array_1[Size_1] = {}, Test_Array_2[Size_2] = {};
	int Range = 30;
	int Changes_Counter = {};

	Fill_Array_with_Random(Test_Array_1, Size_1, -Range, Range);
	Fill_Array_with_Random(Test_Array_2, Size_2, -Range, Range);
	std::cout << "\n" <<"Array_1:";
	Array_Console_Out(Test_Array_1, Size_1);
	std::cout << "\n" << "Array_2:";
	Array_Console_Out(Test_Array_2, Size_2);
	std::cout << "\nResult Array_2:";
	Zeroing_elements_off_array(Test_Array_1, Size_1, Test_Array_2, Size_2, Changes_Counter);
	
	Array_Console_Out(Test_Array_2, Size_2);
	std::cout << "\nChanges made: " << Changes_Counter;
		
}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	setlocale(LC_CTYPE, "Russian");
	std::srand(time(NULL));
	system("mode con cols=110 lines=40"); 
	std::string Name_of_Work = { "Home Work 23: References" };
	std::string Menu_Element_1 = { "Function search maximum from 3 variables and change others to maximum" };
	std::string Menu_Element_2 = { "Function returns reference of first negative element of array" };
	std::string Menu_Element_3 = { "Zeroing elements of array1 in array2" };
	//std::string Menu_Element_4 = { "Search_First_Ordinary_in_Array(arr[], Size): Returns first ordinary number in an array" };

	do 
	{		
		system("cls");
		std::cout << "\n\t***\t" << Name_of_Work << "\t***\n\n\t\n\nChoose an opion: \n";
		std::cout << "\n 1. " << Menu_Element_1;
		std::cout << "\n 2. " << Menu_Element_2;
		std::cout << "\n 3. " << Menu_Element_3;
		//std::cout << "\n 4. " << Menu_Element_4;
		std::cout << "\n\n 0. Exit\n";
		int choice = 0;
		std::cout << "\nYour choice: ";
		choice = Get_Int_Positive();		
		std::cout << "\n";
		// Обработка выбора пользователя
		if (choice == 0) { std::cout << "\nGood By"; for (int j = 0; j < 50; j++) { Sleep(50 - j); std::cout << "y"; } std::cout << "e!"; Sleep(850);  return 0; }
		else if (choice == 1) MAX_from_3_and_change();
		else if (choice == 2) Reference_of_first_negative_demo();
		else if (choice == 3) Zeroing_elements_off_array_demo();
		//else if (choice == 4) Search_First_Ordinary_in_Array_demo();
			
		else { std::cout << "\nSuch choice does not exist yet\n"; Sleep(1000); }
		std::cout << "\n\n";
		system("pause");
	} while (true);
	return 0;
}

// Service functions -----------------------------------------------
int Get_Int_SA() {
	std::string a;
	std::cin.sync(); 
	std::cin.clear(); 
	getline(std::cin, a);
	if (a != "")
	{

		if ((a.find_first_not_of("-0123456789") == -1))
		{
			for (int i = 1; i < a.size(); i++) // определяем есть ли минусы кроме первого символа
			{
				if (a[i] == '-') 
				{
					std::cout << "Input Error: Minus misstanding. [INTEGER] expected.\n";
					return Get_Int_SA();
				}
			}
			try
			{
				return stoi(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. [INTEGER] expected.\n";
				return Get_Int_SA();
			}


		}
		else
		{
			std::cout << "Input Error: Incorrect symbol. [INTEGER] expected.\n";
			return Get_Int_SA();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. [INTEGER] expected.\n";
		return Get_Int_SA();
	}
}
int Get_Int_Positive()
{
	std::string a;
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "") 
	{

		if ((a.find_first_not_of("0123456789") == -1))
		{
			try{
				return stoi(a);
			}
			catch (std::out_of_range){
				std::cout << "Input Error: overflow. Positive [INTEGER] expected.\n";
			}
		}
		else
		{
			std::cout << "Input Error: Positive [INTEGER] expected.\n";
			return Get_Int_Positive();
		}		
	}
	else
		std::cout << "Input Error: NULL input. Positive [INTEGER] expected.\n";
	return Get_Int_Positive();
}
int Get_Int_PG()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! [INTEGER] expected. Repeat please...\n";
	}
	return a;
}
double Get_Dbl_SA(){
	std::string a;
	std::cin.sync();
	getline(std::cin, a);
	if (a == "") { std::cout << "\nInput Error : NULL input\n"; return Get_Dbl_SA(); }
	if ((a.find_first_not_of("-.0123456789") == -1))
	{
		for (int i = 1; i < a.size(); i++) // Проверяем отсутсвие лишних минусов
		{
			if (a[i] == '-')
			{
				std::cout << "\nInput Error: Minus misstanding. [DOUBLE] expected.\n";
				return Get_Dbl_SA();
			}

		}
		bool Dot_Flag = 0;
		for (int i = 0; i < a.size(); i++) // проверяем отсутсвие лишних точек
		{
			if (a[i] == '.')
			{
				if (Dot_Flag == 1)
				{
					std::cout << "\nInput Error: Dot misstandig. [DOUBLE] expected.\n";
					return Get_Dbl_SA();
				}
				Dot_Flag = 1;
			}

		}		 	
				try{
					return stod(a);
				}
				catch (std::out_of_range) {
					std::cout << "Input Error: overflow. [DOUBLE] expected.\n";
					return Get_Dbl_SA();					
				}						
	}
	else {		
		std::cout << "Incorrect symbols: [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
		return Get_Dbl_SA();
	}
}
double Get_Dbl_Positive(){
	std::string a, dot = ".";
	std::cin.sync();
	std::cin.clear();
	getline(std::cin, a);
	if (a != "")
	{
		if ((a.find_first_not_of(".0123456789") == -1))
		{
			bool One_Dot_already = false;
			for (int i = 0; i < a.size(); i++)
			{				
				if (a[i] == dot[0] && One_Dot_already == true) //проверяем количество разделителей
				{
					std::cout << "Input Error: Dot misstandig. Positive [DOUBLE] expected.\n";
					return Get_Dbl_Positive();
				}
				if (a[i] == dot[0])	One_Dot_already = true;
			}
			try
			{				
				return stod(a);
			}
			catch (std::out_of_range)
			{
				std::cout << "Input Error: Data type overflow. Positive [DOUBLE] expected.\n";
				return Get_Dbl_Positive();
			}
		}
		else
		{
			//std::cout << "Incorrect symbols: positive REAL expected.\nUse coma instead of dot. Example 50,64\n"; // да точно говорю вот даже сообщение такое было, а теперь наоборот wtf*2?!
			std::cout << "Incorrect symbols: Positive [DOUBLE] expected.\nUse dot instead of coma. Example 50.64\n";
			return Get_Dbl_Positive();
		}
	}
	else
	{
		std::cout << "Input Error: NULL input. Positive [DOUBLE] expected.\n";
		return Get_Dbl_Positive();
	}
	return Get_Dbl_Positive();
}
double Get_Dbl_PG()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input error! [DOUBLE] expected. Repeat please...\n";
	}
	return a;
}
int Get_Random(int Range_min=-999, int Range_max=999)
{
	if (Range_min > Range_max) 
	{ 
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	//return (Range_min + rand() % (Range_max - Range_min + 1));
	double K_random = double((rand() % RAND_MAX)) / RAND_MAX;
	int random = Range_min + ((Range_max - Range_min) * K_random);
	//return Range_min + (Range_max - Range_min) * (rand() % RAND_MAX) / RAND_MAX;
	return random;
}
double Get_Random(double Range_min=-9999.0, double Range_max=9999.0)
{
	if (Range_min > Range_max)
	{
		std::cout << "\nError: Range_min > Range_max. New range: [Range_max..Range_min]\n";
		std::swap(Range_min, Range_max);
	}
	return 	Range_min + (Range_max - Range_min) * double(rand() % RAND_MAX) / RAND_MAX;	
}
template <typename ANY> void Array_Console_Out(ANY arr[], int Size)
{
	std::cout << "\n[";
	for (int i = 0; i < Size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max)
{
	for (int i = 0; i < Size; i++)
	{
		arr[i] = Get_Random(Range_min, Range_max);		
	}
}
