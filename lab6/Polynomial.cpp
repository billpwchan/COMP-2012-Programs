#include "Polynomial.h"


Polynomial::Polynomial():deg(0){
	this->coef=new Fraction[1];
	this->coef[0].setFraction(0, 1);
}

Polynomial::Polynomial(const Polynomial& p){
//	this->deg=p.getDeg();
//    this->coef=new Fraction[this->deg+1];
//	for (int i=0;i<=this->deg;i++){
//        this->coef[i].setFraction(p.getCoef()[i].getSign()?-p.getCoef()[i].getNumerator():p.getCoef()[i].getNumerator(), p.getCoef()[i].getDenominator());
//	}
    *this=p;
    
}

Polynomial::~Polynomial(){
	delete [] this->coef;
}

void Polynomial::addCoef(const Fraction& f, const int deg){
	if (f.getNumerator()==0||deg<0){
		return;
	}
	//Given degree 3, we can add a new degree that is the same as 2 or greater than the current degree.
	if (deg<=this->deg){
        this->coef[deg].setFraction((this->coef[deg]+f).getSign()?-(this->coef[deg]+f).getNumerator():(this->coef[deg]+f).getNumerator(), !(this->coef[deg]+f).getDenominator()?1:(this->coef[deg]+f).getDenominator());
//        *this=this->reduce();
	}else{
		Fraction* temp = new Fraction[deg+1];
		for (int i=0;i<=this->deg;i++){
            temp[i].setFraction(this->coef[i].getSign()?-this->coef[i].getNumerator():this->coef[i].getNumerator(),this->coef[i].getDenominator());
		}
		for (int i=this->deg+1;i<deg;i++){
			temp[i].setFraction(0, 1);
		}
        temp[deg].setFraction(f.getSign()?-f.getNumerator():f.getNumerator(),f.getDenominator());
        if (this->coef!=NULL)
            delete [] this->coef;
		this->coef=temp;
        this->deg=deg;
	}
}

Polynomial& Polynomial::reduce(){
	int i=0;
	for (i=this->deg;i>=0;i--){
		if (this->coef[i].getNumerator()!=0)
			break;
	}
    //First case, all are zero
    if (i==-1){
        delete [] this->coef;
        this->coef=new Fraction[1];
        this->coef[0].setFraction(0, 1);
        this->deg=0;
        return *this;
    }
    if (i==this->deg){
        return *this;
    }
	Fraction* temp = new Fraction[i+1];
	for (int j=0;j<=i;j++){
        temp[j].setFraction(this->coef[j].getSign()?-this->coef[j].getNumerator():this->coef[j].getNumerator(),this->coef[j].getDenominator());
    }
	delete [] this->coef;
	this->coef=temp;
	this->deg=i;
	return (*this);
}

const Polynomial& Polynomial::operator=(const Polynomial& p){
    if (this!=&p){
        delete [] this->coef;
        this->deg=p.getDeg();
        this->coef = new Fraction[p.getDeg()+1];
        for (int i=0;i<=this->deg;i++){
            this->addCoef(p.getCoef()[i], i);
        }
    }
    return *this;
}



ostream& operator<<(ostream& os, const Polynomial& p){
    for (int i=p.getDeg();i>=0;i--){
        cout <<p.getCoef()[i]<<"x"<<i;
        if (i)
            cout << " + ";
    }
    return os;
}


Polynomial Polynomial::operator+(const Polynomial& p) const{
    Polynomial temp;
    for (int i=0;i<=this->deg; i++){
        temp.addCoef(this->coef[i], i);
    }
    for (int i=0;i<=p.getDeg();i++){
        temp.addCoef(p.getCoef()[i], i);
    }
    //temp.deg is partically correct.
    temp.deg=(this->deg-p.getDeg())>0?this->deg:p.getDeg();
    temp=temp.reduce();
    return temp;
 }

Polynomial Polynomial::operator-(const Polynomial& p) const{
    Polynomial temp;
    for (int i=0;i<=this->deg;i++){
        temp.addCoef(this->coef[i], i);
    }
    for (int i=0;i<=p.getDeg();i++){
        Fraction temp_Frac;
        temp_Frac.setFraction(p.getCoef()[i].getSign()?p.getCoef()[i].getNumerator():-p.getCoef()[i].getNumerator(), p.getCoef()[i].getDenominator());
        temp.addCoef(temp_Frac, i);
    }
    temp.deg=(this->deg-p.getDeg())>0?this->deg:p.getDeg();
    temp=temp.reduce();
    return temp;
}

Polynomial Polynomial::operator*(const Polynomial& p) const{
    Polynomial temp;
    for (int i=0;i<=this->deg+p.getDeg();i++){
        temp.addCoef(Fraction(0,1), i);
    }
    for (int i=0;i<=this->deg;i++){
        for (int j=0;j<=p.getDeg();j++){
//            Fraction temp_Frac(0,1);
//            temp_Frac.setFraction((this->coef[i]*p.getCoef()[j]).getSign()?-(this->coef[i]*p.getCoef()[j]).getNumerator():(this->coef[i]*p.getCoef()[j]).getNumerator(), (this->coef[i]*p.getCoef()[j]).getDenominator());
            temp.addCoef(this->coef[i]*p.coef[j], i+j);
        }
    }
    temp.deg=this->deg+p.getDeg();
//    cout << temp<<endl;
    temp=temp.reduce();
//    cout << temp<<endl;
    return temp;
}

const Polynomial& Polynomial::operator+=(const Polynomial& p){
    *this=*this+p;
    return *this;
}

const Polynomial& Polynomial::operator-=(const Polynomial& p){
    *this=*this-p;
    return *this;
}



