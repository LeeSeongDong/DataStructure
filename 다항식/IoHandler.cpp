#include "IoHandler.h"

void IoHandler::printPolynomial(Polynomial &p)
{
	if (p.getTerms() == 0)
	{
		cout << 0;
		return;
	}

	for (int i = 0; i < p.getTerms(); ++i)
	{
		////////////////////////////////////////////////////////////////////////////////////////////////첫째항
		if (i == 0)
		{
			if (p.getTermArr(i).exp == 0)										//지수가 0일때
			{
				cout << p.getTermArr(i).coef;
			}

			else																//지수가 0이 아닐때
			{

				if (p.getTermArr(i).exp == 1)										//지수가 1일때
				{
					if (p.getTermArr(i).coef > 0)										//계수가 양수
					{
						if (p.getTermArr(i).coef == 1)									//계수가 1
						{
							cout << "x";
						}

						else															//계수가 1아닌 양수
						{
							cout << p.getTermArr(i).coef << "x";
						}
					}

					else															//계수가 음수
					{
						if (p.getTermArr(i).coef == -1)									//계수가 -1
						{
							cout << "-x";
						}
						else															//계수가 -1아닌 음수
						{
							cout << p.getTermArr(i).coef << "x";
						}
					}
				}

				else															//지수가 1이 아닐때
				{
					if (p.getTermArr(i).coef >= 0)									//계수가 양수
					{
						if (p.getTermArr(i).coef == 1)									//계수가 1
						{
							cout << "x^" << p.getTermArr(i).exp;
						}

						else															//계수가 1아닌 양수
						{
							cout << p.getTermArr(i).coef << "x^" << p.getTermArr(i).exp;
						}
					}

					else															//계수가 음수
					{
						if (p.getTermArr(i).coef == -1)									//계수가 -1
						{
							cout << "-x^" << p.getTermArr(i).exp;
						}
						else															//계수가 -1아닌 음수
						{
							cout << p.getTermArr(i).coef << "x^" << p.getTermArr(i).exp;
						}
					}
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////나머지

		else
		{
			if (p.getTermArr(i).exp == 0)							//지수가 0일때
			{
				if (p.getTermArr(i).coef > 0)							//계수가 양수
				{
					cout << " +" << p.getTermArr(i).coef;
				}
				else													//계수가 음수
				{
					cout << " " << p.getTermArr(i).coef;
				}
			}

			else													//지수가 0이 아닐때
			{

				if (p.getTermArr(i).exp == 1)									//지수가 1일때
				{
					if (p.getTermArr(i).coef > 0)									//계수가 양수
					{
						if (p.getTermArr(i).coef == 1)									//계수가 1
						{
							cout << " +" << "x";
						}

						else															//계수가 1아닌 양수
						{
							cout << " +" << p.getTermArr(i).coef << "x";
						}
					}

					else														//계수가 음수
					{
						if (p.getTermArr(i).coef == -1)							//계수가 -1
						{
							cout << " -x";
						}
						else													//계수가 -1아닌 음수
						{
							cout << " " << p.getTermArr(i).coef << "x";
						}
					}
				}

				else										//지수가 1이 아닐때
				{
					if (p.getTermArr(i).coef >= 0)								//계수가 양수
					{
						if (p.getTermArr(i).coef == 1)							//계수가 1
						{
							cout << " +" << "x^" << p.getTermArr(i).exp;
						}

						else													//계수가 1아닌 양수
						{
							cout << " +" << p.getTermArr(i).coef << "x^" << p.getTermArr(i).exp;
						}
					}

					else														//계수가 음수
					{
						if (p.getTermArr(i).coef == -1)							//계수가 -1
						{
							cout << " -x^" << p.getTermArr(i).exp;
						}
						else													//계수가 -1아닌 음수
						{
							cout << " " << p.getTermArr(i).coef << "x^" << p.getTermArr(i).exp;
						}
					}
				}
			}
		}
	}
}