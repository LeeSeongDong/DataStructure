#include "IoHandler.h"

void IoHandler::printPolynomial(PolynomialChain &p)
{
	p.currentSetFirst();

	if (!p.getCurrent())
	{
		cout << 0;
		return;
	}

	while (p.getCurrent())
	{
		////////////////////////////////////////////////////////////////////////////////////////////////첫째항
		if (p.getCurrent() == p.getFirstLink())
		{
			if (p.getCurrentData().exp == 0)										//지수가 0일때
			{
				cout << p.getCurrentData().coef;
			}

			else																//지수가 0이 아닐때
			{

				if (p.getCurrentData().exp == 1)										//지수가 1일때
				{
					if (p.getCurrentData().coef > 0)										//계수가 양수
					{
						if (p.getCurrentData().coef == 1)									//계수가 1
						{
							cout << "x";
						}

						else															//계수가 1아닌 양수
						{
							cout << p.getCurrentData().coef << "x";
						}
					}

					else															//계수가 음수
					{
						if (p.getCurrentData().coef == -1)									//계수가 -1
						{
							cout << "-x";
						}
						else															//계수가 -1아닌 음수
						{
							cout << p.getCurrentData().coef << "x";
						}
					}
				}

				else															//지수가 1이 아닐때
				{
					if (p.getCurrentData().coef >= 0)									//계수가 양수
					{
						if (p.getCurrentData().coef == 1)									//계수가 1
						{
							cout << "x^" << p.getCurrentData().exp;
						}

						else															//계수가 1아닌 양수
						{
							cout << p.getCurrentData().coef << "x^" << p.getCurrentData().exp;
						}
					}

					else															//계수가 음수
					{
						if (p.getCurrentData().coef == -1)									//계수가 -1
						{
							cout << "-x^" << p.getCurrentData().exp;
						}
						else															//계수가 -1아닌 음수
						{
							cout << p.getCurrentData().coef << "x^" << p.getCurrentData().exp;
						}
					}
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////나머지

		else
		{
			if (p.getCurrentData().exp == 0)							//지수가 0일때
			{
				if (p.getCurrentData().coef > 0)							//계수가 양수
				{
					cout << " +" << p.getCurrentData().coef;
				}
				else													//계수가 음수
				{
					cout << " " << p.getCurrentData().coef;
				}
			}

			else													//지수가 0이 아닐때
			{

				if (p.getCurrentData().exp == 1)									//지수가 1일때
				{
					if (p.getCurrentData().coef > 0)									//계수가 양수
					{
						if (p.getCurrentData().coef == 1)									//계수가 1
						{
							cout << " +" << "x";
						}

						else															//계수가 1아닌 양수
						{
							cout << " +" << p.getCurrentData().coef << "x";
						}
					}

					else														//계수가 음수
					{
						if (p.getCurrentData().coef == -1)							//계수가 -1
						{
							cout << " -x";
						}
						else													//계수가 -1아닌 음수
						{
							cout << " " << p.getCurrentData().coef << "x";
						}
					}
				}

				else										//지수가 1이 아닐때
				{
					if (p.getCurrentData().coef >= 0)								//계수가 양수
					{
						if (p.getCurrentData().coef == 1)							//계수가 1
						{
							cout << " +" << "x^" << p.getCurrentData().exp;
						}

						else													//계수가 1아닌 양수
						{
							cout << " +" << p.getCurrentData().coef << "x^" << p.getCurrentData().exp;
						}
					}

					else														//계수가 음수
					{
						if (p.getCurrentData().coef == -1)							//계수가 -1
						{
							cout << " -x^" << p.getCurrentData().exp;
						}
						else													//계수가 -1아닌 음수
						{
							cout << " " << p.getCurrentData().coef << "x^" << p.getCurrentData().exp;
						}
					}
				}
			}
		}

		p.currentSetNext();
	}
}