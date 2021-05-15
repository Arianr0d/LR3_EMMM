#include <iostream>

using namespace std;

// ������� ������ �� ������������ ������������ �������� t � ������� ������
double r(int t) {
	return 96.0-47.0/(t + 1);
}

// ������� ��������� ��������� ������� ������������ �������� t
double phi(int t) {
	return 90.0 / (t + 1);
}

int main() {

	double p = 100, // ��������� ������ ������������
		   sum = 0;
	long double alpha = 0.9,  // �������������� ���������
			    P,            // ������� �� ������������ ������������ �� N �������
				P_pr;		  // ������� �� ������������ ������������ �� N-1 �������

	int t = 1;

	FILE* file;
	fopen_s(&file, "output.txt", "w");
	fprintf_s(file, "%3s  | %6s \n", "N", "P(0)");

	while (true) {
		sum += pow(alpha, t-1) * r(t-1);

		// ������ ������ �� ������������ ������������ �� N �������
		P = (1 / (1 - pow(alpha, t)))* (sum + pow(alpha,t)*(p - phi(t)));
		
		fprintf_s(file, "%3i  | %6.3f \n", t, P);

		// ������� ���������� ������ �����
		if (t > 1 && P > P_pr) {
			fprintf_s(file, "\n�����: P(0) = %6.3f  ��� N = %i", P_pr, t-1);
			break;
		}

		t++;
		P_pr = P;
	}
}