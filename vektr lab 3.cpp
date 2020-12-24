#include <iostream>
#include <math.h>

using namespace std;

template <typename T>
class Vector
{
	int n;
	T* koords;

public:
	Vector();
	Vector(int n);
	~Vector();
	Vector(int ren, T* rkoords);
	Vector(const Vector& copy);

	Vector operator= (const Vector& assi);
	Vector operator+ (const Vector& sum);
	Vector operator- (const Vector& sub);
	T operator* (const Vector& mulv);
	Vector operator* (const T mul);

	bool operator== (Vector& equ);
	bool operator!= (Vector& neg);
	bool operator> (Vector& more);
	bool operator< (Vector& less);
	bool operator>= (Vector& moe);
	bool operator<= (Vector& loe);

	template <class T> friend istream& operator>> (istream& in, Vector<T>& a);
	template <class T> friend ostream& operator<< (ostream& out, const Vector<T>& a);

	float abs(Vector& abs);
	double angle(Vector& angle);
	bool getn(Vector& gn);
};

int main()
{
	setlocale(LC_ALL, "Russian");
	printf("<===== Векторы =====>\n");

	Vector<float> a;
	Vector<float> b;

	cin >> a;
	cout << a << endl;

	cin >> b;
	cout << b << endl;

	if (a.getn(b)) // проверка на равенство длины векторов
	{
		cout << "\nСумма векторов = " << a + b << endl;
		cout << "Разность векторов = " << a - b << endl;
		cout << "Произведение векторов = " << a * b << endl;
		cout << "Угол между векторами = " << a.angle(b) << " градусов" << endl;

		if (a > b)
			cout << "Вектор " << a << " больше вектора " << b;
		else if (a == b)
			cout << "Вектор " << a << " равен вектору " << b;
		else
			cout << "Вектор " << a << " меньше вектора " << b;
	}
	else
		cout << "Векторы должны быть одной длины!";

	return 0;
}

template<typename T>
Vector<T>::Vector()
{
	n = 2;
	koords = new T[n];
	for (int i = 0; i < n; i++)
		koords[i] = 0;
}

template<typename T>
Vector<T>::Vector(int n)
{
	koords = new T[n];
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] koords;
}

template<typename T>
Vector<T>::Vector(int ren, T* rkoords)
{
	n = ren;
	koords = rkoords;
}

template<typename T>
Vector<T>::Vector(const Vector& copy)
{
	n = copy.n;
	koords = new float[n];
	for (int i = 0; i < n; i++)
		koords[i] = copy.koords[i];
}

template<typename T>
Vector<T> Vector<T>::operator= (const Vector& assi)
{
	n = assi.n;
	koords = new float[n];
	for (int i = 0; i < n; i++)
		koords[i] = assi.koords[i];
	return *this;
}

template<typename T>
Vector<T> Vector<T>::operator+ (const Vector& sum)
{
	Vector buf;
	buf.n = n;
	for (int i = 0; i < n; i++)
		buf.koords[i] = koords[i] + sum.koords[i];
	return buf;
}

template<typename T>
Vector<T> Vector<T>::operator- (const Vector& sub)
{
	Vector buf;
	buf.n = n;
	for (int i = 0; i < n; i++)
		buf.koords[i] = koords[i] - sub.koords[i];
	return buf;
}

template<typename T>
T Vector<T>::operator* (const Vector& mulv)
{
	T buf = 0;
	for (int i = 0; i < n; i++)
		buf += koords[i] * mulv.koords[i];
	return buf;
}

template<typename T>
Vector<T> Vector<T>::operator* (const T mul)
{
	Vector buf;
	buf.n = n;
	for (int i = 0; i < n; i++)
		buf.koords[i] = koords[i] * mul;
	return buf;
}

template<typename T>
bool Vector<T>::operator== (Vector& equ)
{
	if (abs(*this) == abs(equ))
		return 1;
	else return 0;
}

template<typename T>
bool Vector<T>::operator!= (Vector& neg)
{
	if (abs(*this) != abs(neg))
		return 1;
	else return 0;
}

template<typename T>
bool Vector<T>::operator> (Vector& less)
{
	if (abs(*this) > abs(less))
		return 1;
	else return 0;
}

template<typename T>
bool Vector<T>::operator< (Vector& more)
{
	if (abs(*this) < abs(more))
		return 1;
	else return 0;
}

template<typename T>
bool Vector<T>::operator>= (Vector& moe)
{
	if (abs(*this) >= abs(moe))
		return 1;
	else return 0;
}

template<typename T>
bool Vector<T>::operator<= (Vector& loe)
{
	if (abs(*this) <= abs(loe))
		return 1;
	else return 0;
}

template<typename T>
istream& operator>> (istream& in, Vector<T>& a)
{
	printf("\nВведите размерность вектора: \n");
	in >> a.n;
	a.koords = new T[a.n];
	printf("\nВведите эл-ты вектора: \n");
	for (int i = 0; i < a.n; i++)
		in >> a.koords[i];
	return in;
}

template<typename T>
ostream& operator<< (ostream& out, const Vector<T>& a)
{
	out << "(";
	for (int i = 0; i < a.n; i++)
	{
		if (i < (a.n - 1))
			out << a.koords[i] << ", ";
		else out << a.koords[i] << ")";
	}
	return out;
}

template<typename T>
float Vector<T>::abs(Vector& mod)
{
	float abs = 0;
	for (int i = 0; i < mod.n; i++)
		abs += mod.koords[i] * mod.koords[i];
	return sqrt(abs);
}

template<typename T>
double Vector<T>::angle(Vector& ang)
{
	T buf = 0;
	for (int i = 0; i < n; i++)
		buf += koords[i] * ang.koords[i];
	double angle = 0;
	angle = buf / (abs(*this) * abs(ang));
	return (acos(angle) * 180 / 3.14159265);
}

template<typename T>
bool Vector<T>::getn(Vector& gn)
{
	if (n == gn.n)
		return 1;
	else
		return 0;
}