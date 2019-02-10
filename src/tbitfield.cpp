#include "tbitfield.h"

TBitField::TBitField(int len)
{	
	BitLen = len;
	MemLen = BitLen/(sizeof(TELEM) * 8) + 1;
	pMem = new TELEM[MemLen];
	if (BitLen != NULL)
		for (int i = 0; i < MemLen; i++)
		{
			pMem[i] = 0;
		}	
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM[MemLen];
	if (BitLen != NULL)
		for (int i = 0; i < MemLen; i++)
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
	return n / (sizeof(TELEM) * 8);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	return 1 << n % (sizeof(TELEM) * 8);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	if (n < 0) throw n;
	if (n >= BitLen) throw n;
	pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if (n < 0) throw n;
	if (n >= BitLen) throw n;
	pMem[GetMemIndex(n)] &= !GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if ((n < 0) || (n >= BitLen)) throw n;
  if ((GetMemIndex(1) & GetMemMask(n)) != 0)
		return 1;
	else
		return 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	delete [] pMem;
	MemLen = bf.MemLen;
	BitLen = bf.BitLen;
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; i++)
	{
		pMem[i] = bf.pMem[i];
	}
	return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
	if (BitLen != bf.BitLen)
		return false;
	else
		for(int i = 0; i < MemLen; i++)
			if (pMem[i] != bf.pMem[i])
				return false;
	return true;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  if (*this == bf)
		return true;
	else 
		return false;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
	int len = BitLen;
	if (bf.BitLen > BitLen) len = bf.BitLen;
	TBitField tmp(len);
	for (int i = 0; i < MemLen; i++) 
		tmp.pMem[i] = pMem[i] | bf.pMem[i];	
	return tmp;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
	int BitMax = BitLen;
	int MinMem = MemLen;
	if (BitLen < bf.BitLen) BitMax = bf.BitLen;
	if (MemLen > bf.MemLen) MinMem = bf.MemLen;
	TBitField tmp(BitMax);
	for (int i = 0; i < MinMem; i++)
		tmp.pMem[i] = pMem[i] & bf.pMem[i];
	return tmp;
}

TBitField TBitField::operator~(void) // отрицание
{
	TBitField tmp(*this);
	for (int i = 0; i < MemLen; i++)
		tmp.pMem[i] = !pMem[i];
	return tmp;	
	
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
