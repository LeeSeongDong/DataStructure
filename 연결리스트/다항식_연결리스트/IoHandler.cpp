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
		////////////////////////////////////////////////////////////////////////////////////////////////ù°��
		if (p.getCurrent() == p.getFirstLink())
		{
			if (p.getCurrentData().exp == 0)										//������ 0�϶�
			{
				cout << p.getCurrentData().coef;
			}

			else																//������ 0�� �ƴҶ�
			{

				if (p.getCurrentData().exp == 1)										//������ 1�϶�
				{
					if (p.getCurrentData().coef > 0)										//����� ���
					{
						if (p.getCurrentData().coef == 1)									//����� 1
						{
							cout << "x";
						}

						else															//����� 1�ƴ� ���
						{
							cout << p.getCurrentData().coef << "x";
						}
					}

					else															//����� ����
					{
						if (p.getCurrentData().coef == -1)									//����� -1
						{
							cout << "-x";
						}
						else															//����� -1�ƴ� ����
						{
							cout << p.getCurrentData().coef << "x";
						}
					}
				}

				else															//������ 1�� �ƴҶ�
				{
					if (p.getCurrentData().coef >= 0)									//����� ���
					{
						if (p.getCurrentData().coef == 1)									//����� 1
						{
							cout << "x^" << p.getCurrentData().exp;
						}

						else															//����� 1�ƴ� ���
						{
							cout << p.getCurrentData().coef << "x^" << p.getCurrentData().exp;
						}
					}

					else															//����� ����
					{
						if (p.getCurrentData().coef == -1)									//����� -1
						{
							cout << "-x^" << p.getCurrentData().exp;
						}
						else															//����� -1�ƴ� ����
						{
							cout << p.getCurrentData().coef << "x^" << p.getCurrentData().exp;
						}
					}
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////������

		else
		{
			if (p.getCurrentData().exp == 0)							//������ 0�϶�
			{
				if (p.getCurrentData().coef > 0)							//����� ���
				{
					cout << " +" << p.getCurrentData().coef;
				}
				else													//����� ����
				{
					cout << " " << p.getCurrentData().coef;
				}
			}

			else													//������ 0�� �ƴҶ�
			{

				if (p.getCurrentData().exp == 1)									//������ 1�϶�
				{
					if (p.getCurrentData().coef > 0)									//����� ���
					{
						if (p.getCurrentData().coef == 1)									//����� 1
						{
							cout << " +" << "x";
						}

						else															//����� 1�ƴ� ���
						{
							cout << " +" << p.getCurrentData().coef << "x";
						}
					}

					else														//����� ����
					{
						if (p.getCurrentData().coef == -1)							//����� -1
						{
							cout << " -x";
						}
						else													//����� -1�ƴ� ����
						{
							cout << " " << p.getCurrentData().coef << "x";
						}
					}
				}

				else										//������ 1�� �ƴҶ�
				{
					if (p.getCurrentData().coef >= 0)								//����� ���
					{
						if (p.getCurrentData().coef == 1)							//����� 1
						{
							cout << " +" << "x^" << p.getCurrentData().exp;
						}

						else													//����� 1�ƴ� ���
						{
							cout << " +" << p.getCurrentData().coef << "x^" << p.getCurrentData().exp;
						}
					}

					else														//����� ����
					{
						if (p.getCurrentData().coef == -1)							//����� -1
						{
							cout << " -x^" << p.getCurrentData().exp;
						}
						else													//����� -1�ƴ� ����
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