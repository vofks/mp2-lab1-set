// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{	
	BitLen = len;
	pMem = new TELEM[BitLen];
	if (BitLen != NULL)
		for (int i = 0; i < BitLen; i++)
		{
			pMem[i] = 0;
		}
	MemLen = 0;
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	BitLen = bf.BitLen;
	pMem = new TELEM[BitLen];
	if (BitLen != NULL)
		for (int i = 0; i < BitLen; i++)
		{
			pMem[i] = bf.pMem[i];
		}
}

TBitField::~TBitField()
{
	if (pMem != NULL)
		delete [] pMem;	
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	return 0;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	return 0;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return 0;
}

void TBitField::SetBit(const int n) // установить бит
{
}

void TBitField::ClrBit(const int n) // очистить бит
{
}

int TBitField::GetBit(const int n) const // получить значение бита
{
  return 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	return TBitField(0);
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  return 0;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
	return TBitField(0);
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
	return TBitField(0);
}

TBitField TBitField::operator~(void) // отрицание
{
	return TBitField(0);
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
	return istream(0);
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
	return ostream(0);
}
