#include <iostream>
#include <bits/stdc++.h>
#include<string>
using namespace std;
void leftrotate(string &s, int d)
{
	reverse(s.begin(), s.begin() + d);
	reverse(s.begin() + d, s.end());
	reverse(s.begin(), s.end());
}
string XOR(string a, string b, int length)
{
	string result;
	for (int i = 0; i < length; i++)
	{
		if ((a[i] == '1'&&b[i] == '1') || (a[i] == '0'&&b[i] == '0'))
		{
			result += '0';
		}
		else if ((a[i] == '1'&&b[i] == '0') || (a[i] == '0'&&b[i] == '1'))
		{
			result += '1';
		}
	}
	return result;
}
int binary_to_decimal(string a)
{
	if (a == "0000" || a == "00")
		return 0;
	else if (a == "0001" || a == "01")
		return 1;
	else if (a == "0010" || a == "10")
		return 2;
	else if (a == "0011" || a == "11")
		return 3;
	else if (a == "0100")
		return 4;
	else if (a == "0101")
		return 5;
	else if (a == "0110")
		return 6;
	else if (a == "0111")
		return 7;
	else if (a == "1000")
		return 8;
	else if (a == "1001")
		return 9;
	else if (a == "1010")
		return 10;
	else if (a == "1011")
		return 11;
	else if (a == "1100")
		return 12;
	else if (a == "1101")
		return 13;
	else if (a == "1110")
		return 14;
	else if (a == "1111")
		return 15;
	else
		return 16;
}
string decimal_to_binary(int a)
{
	string b = "";
	switch (a)
	{
	case 0:
		b = "0000";
		break;
	case 1:
		b = "0001";
		break;
	case 2:
		b = "0010";
		break;
	case 3:
		b = "0011";
		break;
	case 4:
		b = "0100";
		break;
	case 5:
		b = "0101";
		break;
	case 6:
		b = "0110";
		break;
	case 7:
		b = "0111";
		break;
	case 8:
		b = "1000";
		break;
	case 9:
		b = "1001";
		break;
	case 10:
		b = "1010";
		break;
	case 11:
		b = "1011";
		break;
	case 12:
		b = "1100";
		break;
	case 13:
		b = "1101";
		break;
	case 14:
		b = "1110";
		break;
	case 15:
		b = "1111";
		break;
	default:
		b = "none";
		break;
	}
	return b;
}
string hex_to_binary(string hexa)
{
	string bin;
	for (int i = 0; i < hexa.length(); i++)
	{
		switch (hexa[i])
		{
		case '0':
			bin += "0000";
			break;
		case '1':
			bin += "0001";
			break;
		case '2':
			bin += "0010";
			break;
		case '3':
			bin += "0011";
			break;
		case '4':
			bin += "0100";
			break;
		case '5':
			bin += "0101";
			break;
		case '6':
			bin += "0110";
			break;
		case '7':
			bin += "0111";
			break;
		case '8':
			bin += "1000";
			break;
		case '9':
			bin += "1001";
			break;
		case 'A':
			bin += "1010";
			break;
		case 'B':
			bin += "1011";
			break;
		case 'C':
			bin += "1100";
			break;
		case 'D':
			bin += "1101";
			break;
		case 'E':
			bin += "1110";
			break;
		case 'F':
			bin += "1111";
			break;
		default:
			break;
		}
	}
	return bin;
}
string binary_to_hex(string bin, int length)
{
	string word = "";
	string new_word = "";
	for (int i = 0; i < length; i++)
	{
		word += bin[i];
		if ((i + 1) % 4 == 0)
		{
			//	cout << "word[" << i << "]=" << word << endl;
			if (word == "0000")
				new_word += '0';
			else if (word == "0001")
				new_word += '1';
			else if (word == "0010")
				new_word += '2';
			else if (word == "0011")
				new_word += '3';
			else if (word == "0100")
				new_word += "4";
			else if (word == "0101")
				new_word += "5";
			else if (word == "0110")
				new_word += "6";
			else if (word == "0111")
				new_word += "7";
			else if (word == "1000")
				new_word += "8";
			else if (word == "1001")
				new_word += "9";
			else if (word == "1010")
				new_word += "A";
			else if (word == "1011")
				new_word += "B";
			else if (word == "1100")
				new_word += "C";
			else if (word == "1101")
				new_word += "D";
			else if (word == "1110")
				new_word += 'E';
			else if (word == "1111")
				new_word += "F";
			word = "";
		}
		//	cout  <<"new_word="<<new_word << endl;
	}
	return new_word;
}
string DEC(string plain, string key, int sign)
{
	string key_1, key_2[16], all_key, final_key_hex;
	string plain_1;
	string left_key = "", left_plain = "", left_plain_old = "";
	string right_key = "", right_plain = "", right_plain_old = "";
	string right_plain_e_box = "", right_plain_xor_key = "", right_plain_s_box = "", right_plain_permutation = "";
	string right_plain_hex, left_plain_hex;
	string word_s_box;
	string round_16_word;
	string encrypted_word, encrypted_word_hex;
	int Permutated_Choice_1[56] = {
		57,49,41,33,25,17,9,
		1,58,50,42,34,26,18,
		10,2,59,51,43,35,27,
		19,11,3,60,52,44,36,
		63,55,47,39,31,23,15,
		7,62,54,46,38,30,22,
		14,6,61,53,45,37,29,
		21,13,5,28,20,12,4
	};
	int Permutated_Choice_2[48] = {
		14,17,11,24,1,5,
		3,28,15,6,21,10,
		23,19,12,4,26,8,
		16,7,27,20,13,2,
		41,52,31,37,47,55,
		30,40,51,45,33,48,
		44,49,39,56,34,53,
		46,42,50,36,29,32
	};
	int Initial_Permutation[64] = {
		58,50,42,34,26,18,10,2,
		60,52,44,36,28,20,12,4,
		62,54,46,38,30,22,14,6,
		64,56,48,40,32,24,16,8,
		57,49,41,33,25,17,9,1,
		59,51,43,35,27,19,11,3,
		61,53,45,37,29,21,13,5,
		63,55,47,39,31,23,15,7
	};
	int E_BIT_SELECTION_TABLE[48] = {
		32,1,2,3,4,5,
		4,5,6,7,8,9,
		8,9,10,11,12,13,
		12,13,14,15,16,17,
		16,17,18,19,20,21,
		20,21,22,23,24,25,
		24,25,26,27,28,29,
		28,29,30,31,32,1
	};
	int S_BOX[8][4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
							  0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
							  4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
							  15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
							{ 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
							  3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
							  0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
							  13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },
							{ 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
							  13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
							  13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
							  1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
							{ 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
							  13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
							  10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
							  3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
							{ 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
							  14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
							  4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
							  11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
							{ 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
							  10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
							  9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
							  4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
							{ 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
							  13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
							  1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
							  6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
							{ 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
							  1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
							  7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
							  2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };
	int Permutation_S_Box[32] = {
		 16,7,20,21,
		 29,12,28,17,
		 1,15,23,26,
		 5,18,31,10,
		 2,8,24,14,
		 32,27,3,9,
		 19,13,30,6,
		 22,11,4,25
	};
	int Inverse_Permutation[64] = {
		 40,8,48,16,56,24,64,32,
			39,7,47,15,55,23,63,31,
			38,6,46,14,54,22,62,30,
			37,5,45,13,53,21,61,29,
			36,4,44,12,52,20,60,28,
			35,3,43,11,51,19,59,27,
			34,2,42,10,50,18,58,26,
			33,1,41,9,49,17,57, 25
	};

	for (int i = 0; i < 64; i++)
	{
		plain_1 += plain[Initial_Permutation[i] - 1];
		if (i < 32)
			left_plain += plain_1[i];
		else if (i >= 32)
			right_plain += plain_1[i];
	}
	for (int i = 0; i < 56; i++)
	{
		key_1 += key[Permutated_Choice_1[i] - 1];
		if (i < 28)
			left_key += key_1[i];
		else if (i >= 28)
			right_key += key_1[i];
	}
	for (int i = 1; i <= 16; i++)
	{
		if (i == 1 || i == 2 || i == 9 || i == 16)
		{
			leftrotate(left_key, 1);
			leftrotate(right_key, 1);
		}
		else
		{
			leftrotate(left_key, 2);
			leftrotate(right_key, 2);
		}
		all_key = left_key + right_key;
		for (int j = 0; j < 48; j++)
			key_2[i - 1] += all_key[Permutated_Choice_2[j] - 1];
		final_key_hex = binary_to_hex(key_2[i - 1], 48);
		all_key = "";
		final_key_hex = "";
	}
	for (int i = 1; i <= 16; i++)
	{
		left_plain_old = left_plain;
		right_plain_old = right_plain;
		left_plain = right_plain_old;
		for (int i = 0; i < 48; i++)
			right_plain_e_box += right_plain_old[E_BIT_SELECTION_TABLE[i] - 1];
		if (sign == 1)
			right_plain_xor_key = XOR(key_2[i - 1], right_plain_e_box, 48);
		else if (sign == 0)
			right_plain_xor_key = XOR(key_2[16 - i], right_plain_e_box, 48);
		for (int m = 0; m < 48; m++)
		{
			word_s_box += right_plain_xor_key[m];
			if ((m + 1) % 6 == 0)
			{
				string word_column = "", word_row = "";
				for (int i = 0; i < 6; i++)
				{
					if (i == 0 || i == 5)
						word_row += word_s_box[i];
					if (i == 1 || i == 2 || i == 3 || i == 4)
						word_column += word_s_box[i];
				}
				word_s_box = "";
				int second_col = binary_to_decimal(word_row);
				int third_col = binary_to_decimal(word_column);
				int value_in_decimal = S_BOX[m / 6][second_col][third_col];
				right_plain_s_box += decimal_to_binary(value_in_decimal);
			}
		}
		for (int i = 0; i < 32; i++)
			right_plain_permutation += right_plain_s_box[Permutation_S_Box[i] - 1];
		right_plain = XOR(right_plain_permutation, left_plain_old, 32);
		right_plain_hex = binary_to_hex(right_plain, 32);
		left_plain_hex = binary_to_hex(left_plain, 32);
		right_plain_e_box = "";
		right_plain_xor_key = "";
		right_plain_s_box = "";
		right_plain_permutation = "";
	}
	round_16_word = right_plain + left_plain;
	for (int i = 0; i < 64; i++)
		encrypted_word += round_16_word[Inverse_Permutation[i] - 1];
	encrypted_word_hex = binary_to_hex(encrypted_word, 64);
	return encrypted_word_hex;
}
int main(int argc, char **argv)
{
	string operation, plain_or_cipher, key;
	operation = argv[1];
	plain_or_cipher = argv[2];
	key = argv[3];
	string plain_hex, plain_dec;
	string key_hex, key_dec;
	string cipher_hex, cipher_dec;
	string key_1, key_2;
	int sign;
	if (operation[0] == 'e')
		sign = 1;
	else if (operation[0] == 'd')
		sign = 0;
	if (operation[0] == 'e' || operation[0] == 'd')
	{
		if (operation[0] == 'e')
		{
			plain_hex = plain_or_cipher;
		}
		else if (operation[0] == 'd')
		{
			cipher_hex = plain_or_cipher;
		}
		key_hex = key;
	}
	if (operation[0] == 'e')
		plain_dec = hex_to_binary(plain_hex);
	else if (operation[0] == 'd')
		cipher_dec = hex_to_binary(cipher_hex);
	key_dec = hex_to_binary(key_hex);
	if (operation[0] == 'e')
	{
		key_1 = DEC(plain_dec, key_dec, sign);
		cout << "cipher=" << key_1 << endl;
	}
	else if (operation[0] == 'd')
	{
		key_2 = DEC(cipher_dec, key_dec, sign);
		cout << "plain= " << key_2 << endl;
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
