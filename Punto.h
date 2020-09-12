#ifndef PUNTO_H
#define PUNTO_H

class Punto{
	int ascissa;
	int ordinata;
	bool e_stato_colpito;

public:
	Punto(int const &, int const &, bool const &);

	int ascissaGet() const;
	int ordinataGet() const;
	bool e_stato_colpitoGet() const;

	void ascissaSet(const int);
	void ordinataSet(const int);
	void e_stato_colpitoSet(const bool);

	void ascissaPrint() const;
	void ordinataPrint() const;
	void e_stato_colpitoPrint() const;
	void PuntoPrint() const;
};

#endif // PUNTO_H
