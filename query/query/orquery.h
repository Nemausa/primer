#ifndef ORQUERY_H
#define ORQUERY_H

#include "binaryquery.h"

class OrQuery :public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& left, const Query& right):
        BinaryQuery(left, right, "|")
    {
        std::cout << "OrQuery::OrQuery\n";
    }

    QueryResult eval(const TextQuery& text)const override
    {
		auto left = lhs.eval(text), right = rhs.eval(text);
		auto ret_lines =
			std::make_shared<std::set<line_no>>(left.begin(), left.end());
		ret_lines->insert(right.begin(), right.end());

		return QueryResult(rep(), ret_lines, left.get_file());
    }
};

inline Query operator|(const Query &lhs, const Query& rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif // ORQUERY_H
