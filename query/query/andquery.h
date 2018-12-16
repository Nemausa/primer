#ifndef ANDQUERY_H
#define ANDQUERY_H


#include "binaryquery.h"


class AndQuery : public BinaryQuery
{
	//using line_no = TextQuery::line_no; //  used in the eval function
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& left, const Query& right):
        BinaryQuery(left, right, "&")
    {
        std::cout << "AndQuery::AndQuery()\n";
    }

    // @note: inherits rep and define eval

    QueryResult eval(const TextQuery &text) const override
    {
        // this is just a placeholder rather than the real definition
		auto left = lhs.eval(text), right = rhs.eval(text);
		auto ret_lines = std::make_shared<std::set<line_no>>();
		set_intersection(left.begin(), left.end(),
			right.begin(), right.end(),
			inserter(*ret_lines, ret_lines->begin()));

		return QueryResult(rep(), ret_lines, left.get_file());
    }
};

inline Query operator& (const Query& lhs, const Query& rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

#endif // ANDQUERY_H
