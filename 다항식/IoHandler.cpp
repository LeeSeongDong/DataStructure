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
		////////////////////////////////////////////////////////////////////////////////////////////////ù°��
		if (i == 0)
		{
			if (p.getTermArr(i).exp == 0)										//������ 0�϶�
			{
				cout << p.getTermArr(i).coef;
			}

			else																//������ 0�� �ƴҶ�
			{

				if (p.getTermArr(i).exp == 1)										//������ 1�϶�
				{
					if (p.getTermArr(i).coef > 0)										//����� ���
					{
						if (p.getTermArr(i).coef == 1)									//����� 1
						{
							cout << "x";
						}

						else															//����� 1�ƴ� ���
						{
							cout << p.getTermArr(i).coef << "x";
						}
					}

					else															//����� ����
					{
						if (p.getTermArr(i).coef == -1)									//����� -1
						{
							cout << "-x";
						}
						else															//����� -1�ƴ� ����
						{
							cout << p.getTermArr(i).coef << "x";
						}
					}
				}

				else															//������ 1�� �ƴҶ�
				{
					if (p.getTermArr(i).coef >= 0)									//����� ���
					{
						if (p.getTermArr(i).coef == 1)									//����� 1
						{
							cout << "x^" << p.getTermArr(i).exp;
						}

						else															//����� 1�ƴ� ���
						{
							cout << p.getTermArr(i).coef << "x^" << p.getTermArr(i).exp;
						}
					}

					else															//����� ����
					{
						if (p.getTermArr(i).coef == -1)									//����� -1
						{
							cout << "-x^" << p.getTermArr(i).exp;
						}
						else															//����� -1�ƴ� ����
						{
							cout << p.getTermArr(i).coef << "x^" << p.getTermArr(i).exp;
						}
					}
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////������

		else
		{
			if (p.getTermArr(i).exp == 0)							//������ 0�϶�
			{
				if (p.getTermArr(i).coef > 0)							//����� ���
				{
					cout << " +" << p.getTermArr(i).coef;
				}
				else													//����� ����
				{
					cout << " " << p.getTermArr(i).coef;
				}
			}

			else													//������ 0�� �ƴҶ�
			{

				if (p.getTermArr(i).exp == 1)									//������ 1�϶�
				{
					if (p.getTermArr(i).coef > 0)									//����� ���
					{
						if (p.getTermArr(i).coef == 1)									//����� 1
						{
							cout << " +" << "x";
						}

						else															//����� 1�ƴ� ���
						{
							cout << " +" << p.getTermArr(i).coef << "x";
						}
					}

					else														//����� ����
					{
						if (p.getTermArr(i).coef == -1)							//����� -1
						{
							cout << " -x";
						}
						else													//����� -1�ƴ� ����
						{
							cout << " " << p.getTermArr(i).coef << "x";
						}
					}
				}

				else										//������ 1�� �ƴҶ�
				{
					if (p.getTermArr(i).coef >= 0)								//����� ���
					{
						if (p.getTermArr(i).coef == 1)							//����� 1
						{
							cout << " +" << "x^" << p.getTermArr(i).exp;
						}

						else													//����� 1�ƴ� ���
						{
							cout << " +" << p.getTermArr(i).coef << "x^" << p.getTermArr(i).exp;
						}
					}

					else														//����� ����
					{
						if (p.getTermArr(i).coef == -1)							//����� -1
						{
							cout << " -x^" << p.getTermArr(i).exp;
						}
						else													//����� -1�ƴ� ����
						{
							cout << " " << p.getTermArr(i).coef << "x^" << p.getTermArr(i).exp;
						}
					}
				}
			}
		}
	}
}