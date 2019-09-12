/*
 * test.h
 *
 *  Created on: 9 дек. 2018 г.
 *      Author: DIOLNA
 */

#ifndef TEST_H_
#define TEST_H_

void TestOneSymbol(){
	AssertEqual(IsPalindrom("a"), true, " one symbol");
	AssertEqual(IsPalindrom(" "), true, " one symbol");
	AssertEqual(IsPalindrom("?"), true, " one symbol");
	}

void TestEmptyString(){
	string a;
	AssertEqual(IsPalindrom(a), true, "symbol is empty");
}
void TestPalindrom(){
	AssertEqual(IsPalindrom("aabbbaa"), true, "aabbbaa");
	AssertEqual(IsPalindrom("a bbb a"), true, "a bbb a");
	AssertEqual(IsPalindrom("aabbaa"), true, "aabbaa");
	AssertEqual(IsPalindrom("          "), true , "all space");
	AssertEqual(IsPalindrom("AABBaa"), false, "AABBaa");
	AssertEqual(IsPalindrom(" AABBAA "), true, " AABBAA ");
	AssertEqual(IsPalindrom("ddffdd "), false, "ddffdd ");
	AssertEqual(IsPalindrom("ff"), true, " ff");
	AssertEqual(IsPalindrom("rerererererererererer"), true, "rerererererererererer");
	AssertEqual(IsPalindrom("tytrtycc"), false, "tytrtycc");
	AssertEqual(IsPalindrom(" t y t y t "), true, " t y t y t ");
	AssertEqual(IsPalindrom(" 1 "), true, " 1 ");
	AssertEqual(IsPalindrom(" 1 1 1"), false, " 1 1 1");
	AssertEqual(IsPalindrom("tytrtycc"), false, "tytrtycc");
	AssertEqual(IsPalindrom("madam"), true, "madam");
	AssertEqual(IsPalindrom("  pollop  "), true, "  pollop  ");
	AssertEqual(IsPalindrom("  pollop "), false, "  pollop  ");
	AssertEqual(IsPalindrom("dddd dddd"), true, "dddd dddd");
	AssertEqual(IsPalindrom(" dddd dddd "), true, " dddd dddd ");
	AssertEqual(IsPalindrom(" dddd  dddd "), true, " dddd  dddd ");
	AssertEqual(IsPalindrom(" dadd dddd "), false, " dadd dddd ");
	AssertEqual(IsPalindrom(" ddd   ddd "), true, " ddd   ddd ");
	AssertEqual(IsPalindrom(""), true, "");
	AssertEqual(IsPalindrom("   "), true, " three space ");
	AssertEqual(IsPalindrom("maddam"), true, "maddam");
	AssertEqual(IsPalindrom("0-0-0"), true, "0-0-0");
	AssertEqual(IsPalindrom("ABA"), true, "ABA");
	AssertEqual(IsPalindrom("ttrrrrtt"), true, "404 ");
	AssertEqual(IsPalindrom(" dddd"), false, " dddd");
	AssertEqual(IsPalindrom("abcFabc"), false, "abcFabc");
	AssertEqual(IsPalindrom("AB4dffdBA"), false, "AB4dffdBA");
	AssertEqual(IsPalindrom("abcd10dcba"), false, "abcd10dcba");
	AssertEqual(IsPalindrom("AB4dffdBA"), false, "AB4dffdBA");
	AssertEqual(IsPalindrom("nABdffdBA"), false, "nABdffdBA");
	AssertEqual(IsPalindrom("abcdabcda"), false, "abcdabcda");
	AssertEqual(IsPalindrom("ABacdfABBAasdfBA"), false, "ABacdfABBAasdfBA");
	AssertEqual(IsPalindrom("abc abccbacba"), false, "abc abccbacba");
	AssertEqual(IsPalindrom("abc abc cbacba"), false, "abc abccbacba");
	AssertEqual(IsPalindrom("abc abccba cba"), true, "abc abccba cba");
	AssertEqual(IsPalindrom("wabcabccbacba"), false, "wabcabccbacba");
	AssertEqual(IsPalindrom("abcabccbacbaw"), false, "abcabccbacbaw");
	AssertEqual(IsPalindrom("aaa1aaac"), false, "aaa1aaac");
	AssertEqual(IsPalindrom("caaa1aaa"), false, "caaa1aaa");
	AssertEqual(IsPalindrom("ABCCBA"), true, "ABCCBA");
	AssertEqual(IsPalindrom("aAaa1aaa"), false, "aAa1aaa");
	AssertEqual(IsPalindrom("aaa1AAA"), false, "aaa1AAA");
	AssertEqual(IsPalindrom("/ABA/"), true, "/ABA/");
	AssertEqual(IsPalindrom("ABA/"), false, "ABA/");







}




#endif /* TEST_H_ */
