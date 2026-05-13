#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class clsString
{
private:
	string _Value;
public:
	clsString()
	{

	}
	clsString(string Value)
	{
		_Value = Value;
	}
	void SetValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue))string Value;
	static short Length(string String)
	{
		return String.length();
	}
	short Length()
	{
		return _Value.length();
	}
	static short CountWords(string String)
	{
		string Separator = " ";
		string sWord;
		short Position;
		short Counter = 0;
		while ((Position = String.find(Separator)) != std::string::npos)
		{
			sWord = String.substr(0, Position);
			if (sWord != "")
			{
				Counter++;
			}
			String.erase(0, Position + Separator.length());
		}
		if (String != "")
		{
			Counter++;
		}
		return Counter;
	}
	short CountWords()
	{
		return CountWords(_Value);
	}
	static string UpperFirstLetterOfEachWord(string String)
	{
		bool IsFirstLetter = true;
		for (int i = 0;i < String.length();i++)
		{
			if (IsFirstLetter&&String[i]!=' ')
			{
				String[i] = toupper(String[i]);
			}
			IsFirstLetter = (String[i] == ' ' ? true : false);
		}
		return String;
	}
	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}
	static string LowerFirstLetterOfEachWord(string String)
	{
		bool IsFirstLetter = true;
		for (int i = 0;i < String.length();i++)
		{
			if (IsFirstLetter && String[i] != ' ')
			{
				String[i] = tolower(String[i]);
			}
			IsFirstLetter = (String[i] == ' ' ? true : false);
		}
		return String;
	}
	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}
	static string UpperAllString(string String)
	{
		for (int i = 0;i < String.length();i++)
		{
			String[i] = toupper(String[i]);
		}
		return String;
	}
	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}
	static string LowerAllString(string String)
	{
		for (int i = 0;i < String.length();i++)
		{
			String[i] = tolower(String[i]);
		}
		return String;
	}
	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}
	static char InvertLetterCase(char Letter)
	{
		return isupper(Letter) ? tolower(Letter) : toupper(Letter);
	}
	static string InvertAllLettersCase(string String)
	{
		for (int i = 0;i < String.length();i++)
		{
			String[i] = InvertLetterCase(String[i]);
		}
		return String;
	}
	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}
	enum enWhatToCount { SmallLetter = 1, CapitalLetters = 2, All = 3 };
	static short CountLetters(string String, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
		{
			return String.length();
		}
		short Counter = 0;
		for (int i = 0;i < String.length();i++)
		{
			if (WhatToCount == enWhatToCount::SmallLetter && islower(String[i]))
			{
				Counter++;
			}
			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(String[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	static short CountCapitalLetters(string String)
	{
		return CountLetters(String, enWhatToCount::CapitalLetters);
	}
	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string String)
	{
		return CountLetters(String, enWhatToCount::SmallLetter);
	}
	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}
	static short CountSpecificLetter(string String, char Letter, bool MatchCase = true)
	{
		short Counter = 0;
		for (int i = 0;i < String.length();i++)
		{
			if (MatchCase && String[i] == Letter)
			{
				Counter++;
			}
			else if (!MatchCase && tolower(String[i]) == tolower(Letter))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}
	static bool IsVowel(char Letter)
	{
		Letter = tolower(Letter);
		return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
	}
	static short CountVowels(string String)
	{
		short Counter = 0;
		for (int i = 0;i < String.length();i++)
		{
			if (IsVowel(String[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountVowels()
	{
		return CountVowels(_Value);
	}
	static vector<string> Split(string String, string Separator = " ")
	{
		string Word;
		int Position;
		vector<string> vString;
		while ((Position = String.find(Separator)) != std::string::npos)
		{
			Word = String.substr(0, Position);
			/*if (Word != "")
			{
				vString.push_back(Word);
			}*/
			vString.push_back(Word);
			String.erase(0, Position + Separator.length());
		}
		if (String != "")
		{
			vString.push_back(String);
		}
		return vString;
	}
	vector<string>Split(string Separator = " ")
	{
		return Split(_Value, Separator);
	}
	static string TrimLeft(string String)
	{
		for (int i = 0;i < String.length();i++)
		{
			if (String[i] != ' ')
			{
				return String.substr(i, String.length() - i);
			}
		}
		return "";
	}
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}
	static string TrimRight(string String)
	{
		for (int i = String.length() - 1;i >= 0;i--)
		{
			if (String[i] != ' ')
			{
				return String.substr(0, i+1);
			}
		}
		return "";
	}
	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}
	static string Trim(string String)
	{
		return TrimLeft(TrimRight(String));
	}
	void Trim()
	{
		_Value = Trim(_Value);
	}
	static string JoinString(vector<string> vString, string Separator = " ")
	{
		string String = "";
		for (string& S : vString)
		{
			String += S + Separator;
		}
		return String.substr(0, String.length() - Separator.length());
	}
	static string ReverseWordsInString(string String)
	{
		vector<string> vString = Split(String, " ");
		string NewString = "";

		vector<string>::iterator Iter = vString.end();
		while (Iter != vString.begin())
		{
			--Iter;
			NewString += *Iter + " ";
		}
		return NewString.substr(0, NewString.length() - 1);
	}
	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}
	static string ReplaceWord(string String, string ReplacedWord, string ReplacingWord, bool MatchCase = true)
	{
		vector<string> vString = Split(String, " ");
		for (string& S : vString)
		{
			if (MatchCase)
			{
				if (S == ReplacedWord)
				{
					S = ReplacingWord;
				}
			}
			else
			{
				if (LowerAllString(S) == LowerAllString(ReplacedWord))
				{
					S = ReplacingWord;
				}
			}
		}
		return JoinString(vString, " ");
	}
	string ReplaceWord(string ReplacedWord, string ReplacingWord)
	{
		return ReplaceWord(_Value, ReplacedWord, ReplacingWord);
	}
	static string RemovePunctuations(string String)
	{
		string NewString = "";
		for (int i = 0;i < String.length();i++)
		{
			if (!ispunct(String[i]))
			{
				NewString += String[i];
			}
		}
		return NewString;
	}
	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}
};