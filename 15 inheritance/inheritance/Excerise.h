//////////////////////////////////////////////////////////////////////////
//  @file     ex1_3.h
//  @author   VincentLee
//  @date     2018-06-01
//  @mail     vincentleecn@163.com
//
//  @version  2018-06-01
//  -added 
//  @remark   
//  @note
//////////////////////////////////////////////////////////////////////////

#ifndef EXERCISE_H
#define EXERCISE_H

//
// Exercise 15.1:
// What is a virtual member?
//  A virtual member in a base class expects its derived class define its own version.
//  In particular base classes ordinarily should define a virtual destructor, even if
//  it does no work.
//
// Exercise 15.2:
// How does the protected access specifier differ from private?
// private members   : base class itself and friend can access
// protected members : base class itself, friend and derived classes can access

//
// Exercise 15.12:
// Is it ever useful to declare a member function as both override and final?
// Why or why not?
//  Sure. override means overriding the same name virtual function in base class.
//  final means preventing any overriding this virtual function by any derived classes
//  that are more lower at the hierarchy .

#include <iostream>

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price) {}
	std::string isbn() const { return bookNo; }

	virtual double net_price(std::size_t n) const
	{
		return n * price;
	} 

	virtual ~Quote() = default;


private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& b, double p, std::size_t q, double disc) :
		Quote(b, p), min_qty(q), discount(disc)  {   }

	double net_price(std::size_t n) const override;

private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

double Bulk_quote::net_price(std::size_t n) const
{
	return n * price * ( n >= min_qty ? 1 - discount : 1);
	
}


#endif // EXERCISE_H
