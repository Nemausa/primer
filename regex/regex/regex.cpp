// regex_match example

#include <iostream>
#include <string>
#include <regex>
using namespace std;

#define vstr(n)  str##n
#define reg(n)   re##n

#define regex_m(n) regex_match(vstr(n), reg(n))
#define regex_s(n) regex_search(vstr(n), reg(n))

int main()
{

	
	std::string pattern("acd*b");
	std::regex re(pattern);

	std::string str("acdacdb");
	bool ret = std::regex_match(str, re);

	/// \ 1. "."： 匹配除"\n"之外的任何单个字符,若要匹配包括"\n"在内的任意字符,
	/// \ 需使用诸如"[\s\S]"之类的模式；
	std::regex re1(".");
	std::string str1("\\");

	ret = regex_match(str1, re1);

	/// \ 2. "^"：
	/// \ 匹配输入字符串的开始位置,不匹配任何字符,要匹配"^"字符本身,需使用"\^"；
	regex re2("^[0-9]{4}[a-zA-Z]*");
	string str2("1234aZdsdfljsdlfjs");
	
	ret = regex_match(str2, re2);
	
	/// \ 3. "$"：
	/// \ 匹配输入字符串结尾的位置,不匹配任何字符,要匹配"$"字符本身,需使用"\$"；
	regex re3(".*[cd]$");
	string str3("sadf1949lsdof2397n");

	ret = regex_match(str3, re3);

	/// \ 4. *:
	/// \ 匹配前面的子表达式零次或多次。例如,zo* 能匹配 "z" 以及 "zoo"。* 等价于{0,}。
	regex re4("abc{0,}");
	string str4("ab");

	ret = regex_match(str4, re4);

	/// \ 5. +	匹配前面的子表达式一次或多次。例如,'zo+' 能匹配 "zo" 以及 "zoo",
	/// \ 但不能匹配 "z"。+ 等价于 {1,}。
	regex re5("abc{1,}");
	string str5("abc");

	ret = regex_match(str5, re5);

	/// \ something to do 
	/// \ 6. ?	匹配前面的子表达式零次或一次。例如,"do(es)?" 可以匹配 "do" 或 
	/// \ "does" 中的"do" 。? 等价于 {0,1}。
	regex re6("do(es)?");
	string str6("");

	ret = regex_match(str6, re6);

	/// \ 7. {n}	n 是一个非负整数。匹配确定的 n 次。例如,'o{2}' 不能匹配 "Bob"
	/// \ 中的 'o',但是能匹配 "food" 中的两个 o。
	regex re7(".o{0,2}d");
	string str7("foood");

	ret = regex_match(str7, re7);

	/// \ 8. ?当该字符紧跟在任何一个其他限制符(*,+,?,{n},{n,},{n,m})后面时,匹配模式
	/// \ 是非贪婪的。非贪婪模式尽可能少的匹配所搜索的字符串,而默认的贪婪模式则尽可能
	/// \ 多的匹配所搜索的字符串。例如,对于字符串"oooo","o+?"将匹配单个"o",而"o+"
	/// \ 将匹配所有"o"。
	regex re8("fo?d");
	string str8("fod");

	ret = regex_match(str8, re8);

	/// \ 9. \将下一个字符标记为一个特殊字符、或一个原义字符、或一个向后引用、或一个八
	/// \ 进制转义符。例如,"n"匹配字符"n"。"\n"匹配一个换行符。序列"\\"匹配"\"而"\("
	/// \ 则匹配"("。
	regex re9 ("\\(");
	string str9("\(");

	ret = regex_match(str9, re9);

	/// \ 10. (pattern)匹配pattern并获取这一匹配。所获取的匹配可以从产生的Matches
	/// \ 集合得到,在VBScript中使用SubMatches集合,在JScript中则使用$0…$9属性。要
	/// \匹配圆括号字符,请使用"\("或"\)"。
	regex re10("(abc)");
	string str10("abc");

	ret = regex_m(10);

	/// \ 11. (?:pattern)匹配pattern但不获取匹配结果,也就是说这是一个非获取匹配,
	/// \ 不进行存储供以后使用。这在使用"或"字符(|)来组合一个模式的各个部分是很有用。
	/// \ 例如, "industr(?:y|ies)"就是一个比"industry|industries"更简略的表达式。
	regex re11("industr(?:y|ies)");
	string str11("industry");

	ret = regex_m(11);

	/// \ TODO
	/// \ 12. (?=pattern)正向预查,在任何匹配pattern的字符串开始处匹配查找字符串。
	/// \ 这是一个非获取匹配,也就是说,该匹配不需要获取供以后使用。例如,
	/// \ "Windows(?=95|98|NT|2000)"能匹配"Windows2000"中的"Windows",但不能匹配
	/// \ "Windows3.1"中的"Windows"。预查不消耗字符,也就是说,在一个匹配发生后,在
	/// \ 最后一次匹配之后立即开始下一次匹配的搜索,而不是从包含预查的字符之后开始。
	regex re12("Windows(?=95|98|NT|2000)");
	string str12("Windows2000");

	ret = regex_m(12);

	/// \ TODO
	/// \ 13. (?!pattern)负向预查,在任何不匹配pattern的字符串开始处匹配查找字符串。
	/// \ 这是一个非获取匹配,也就是说,该匹配不需要获取供以后使用。例如"Windows(?!95
	/// \ |98|NT|2000)"能匹配"Windows3.1"中的"Windows",但不能匹配"Windows2000"中
	/// \ 的"Windows"。预查不消耗字符,也就是说,在一个匹配发生后,在最后一次匹配之后
	/// \ 立即开始下一次匹配的搜索,而不是从包含预查的字符之后开始
	regex re13("Windows(?!95|98|NT|2000)");
	string str13("Windows3.1");

	ret = regex_m(13);

	/// \ 14. x|y匹配x或y。例如,"z | food"能匹配"z"或"food"。"(z | f)ood"则匹配
	/// \ "zood"或"food"。
	regex re14("z|food");
	string str14("z");

	ret = regex_m(14);

	/// \ 15. [xyz] 
	/// \ 字符集合。匹配所包含的任意一个字符。例如,"[abc]"可以匹配"plain" 中的"a"。
	regex re15("pl[abc]in");
	string str15("plain");

	ret = regex_m(15);

	/// \ 16. [^xyz]
	/// \ 负值字符集合。匹配未包含的任意字符。例如,"[^abc]"可以匹配"plain"中的"p"。
	regex re16("[^abc]lain");
	string str16("plain");

	ret = regex_m(16);

	/// \ 17. \b 匹配一个单词边界,也就是指单词和空格间的位置。例如,"er\b"可以匹配
	/// \ "never"中的"er",但不能匹配"verb"中的"er"。
	regex re17("er\\b");
	string str17("never");

	ret = regex_s(17);

	/// \ 18. \B
	/// \ 匹配非单词边界。"er\B"能匹配"verb"中的"er",但不能匹配"never"中的"er"。
	regex re18("er\\B");
	string str18("never");
	
	ret = regex_s(18);

	/// 19. \cx 匹配由x指明的控制字符。例如,\cM匹配一个Control-M或回车符。x的值必须
	/// \ 为A-Z或a-z之一。否则,将c视为一个原义的"c"字符。
	regex re19("\\cM");
	string str19("\^M");

	ret = regex_s(19);

	/// \ 20. \d 匹配一个数字字符。等价于[0-9]。
	regex re20("^\\d+$");
	string str20("12312");

	ret = regex_m(20);

	/// \ 21. \D 匹配一个非数字字符。等价于[^0-9]。
	regex re21("\\D");
	string str21("a");

	ret = regex_m(21);



	/// \ \f 匹配一个换页符。等价于\x0c和\cL。
	/// \ \n 匹配一个换行符。等价于\x0a和\cJ。
	/// \ \r 匹配一个回车符。等价于\x0d和\cM。
	/// \ \s 匹配任何空白字符,包括空格、制表符、换页符等等。等价于[\f\n\r\t\v]。
	/// \ \S 匹配任何非空白字符。等价于[^\f\n\r\t\v]。
	/// \ \t 匹配一个制表符。等价于\x09和\cI。
	/// \ \v 匹配一个垂直制表符。等价于\x0b和\cK。
	/// \ \w 匹配包括下划线的任何单词字符。等价于"[A-Za-z0-9_]"。
	/// \ \W 匹配任何非单词字符。等价于"[^A-Za-z0-9_]"。

	/// \ \xn 
	/// \ 匹配n,其中n为十六进制转义值。十六进制转义值必须为确定的两个数字长。例如,
	/// \ "\x41"匹配"A"。"\x041"则等价于"\x04"&"1"。正则表达式中可以使用ASCII编码.

	/// \ \num 
	/// \ 匹配num,其中num是一个正整数。对所获取的匹配的引用。例如,"(.)\1"匹配两个
	/// \ 连续的相同字符。

	/// \ \n
	/// \ 标识一个八进制转义值或一个向后引用。如果\n之前至少n个获取的子表达式,则n为向
	/// \ 后引用。否则,如果n为八进制数字(0-7),则n为一个八进制转义值。

	/// \ \nm 	
	/// \ 标识一个八进制转义值或一个向后引用。如果\nm之前至少有nm个获得子表达式,则nm
	/// \ 为向后引用。如果\nm之前至少有n个获取,则n为一个后跟文字m的向后引用。如果前面
	/// \ 的条件都不满足,若n和m均为八进制数字(0-7),则\nm将匹配八进制转义值nm。

	/// \ \nml
	/// \ 如果n为八进制数字(0-3),且m和l均为八进制数字(0-7),则匹配八进制转义值nml。


	/// \ \un匹配n,其中n是一个用四个十六进制数字表示的Unicode字符。
	/// \ 例如,\u00A9匹配版权符号(©)。

	return 0;
}
