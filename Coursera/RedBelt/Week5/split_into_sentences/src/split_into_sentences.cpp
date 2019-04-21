#include "test_runner.h"

#include <vector>
#include <iostream>

using namespace std;

// Объявляем Sentence<Token> для произвольного типа Token
// синонимом vector<Token>.
// Благодаря этому в качестве возвращаемого значения
// функции можно указать не малопонятный вектор векторов,
// а вектор предложений — vector<Sentence<Token>>.
template <typename Token>
using Sentence = vector<Token>;

// Класс Token имеет метод bool IsEndSentencePunctuation() const
template <typename Token>
vector<Sentence<Token>> SplitIntoSentences(vector<Token> tokens) {
  // Напишите реализацию функции, не копируя объекты типа Token
	Sentence<Token> sentence;
	vector<Sentence<Token>> vec;
	bool flag;
	auto it = tokens.begin();
	while(it!=tokens.end()){
		while((*it).IsEndSentencePunctuation() == false){

				sentence.push_back(move(*it));

				++it;
				if(it==tokens.end()) break;
		}

		if(it == tokens.end()){
			vec.push_back(move(sentence));
			break;
		}
		while((*it).IsEndSentencePunctuation() == true){
			flag = true;
		sentence.push_back(move(*it));
		++it;
		if(it==tokens.end()) break;
		}
		vec.push_back(move(sentence));  // добавляем знаки конца предложения
		if(it==tokens.end()) break;
		if(flag!= true) ++it;


	}
	//vec.push_back(move(sentence));
	if(vec.empty()) vec.push_back(move(sentence));

	//cout << endl;
	return vec;
}


struct TestToken {
  string data;
  bool is_end_sentence_punctuation = false;

  bool IsEndSentencePunctuation() const {
    return is_end_sentence_punctuation;
  }
  bool operator==(const TestToken& other) const {
    return data == other.data && is_end_sentence_punctuation == other.is_end_sentence_punctuation;
  }
};

ostream& operator<<(ostream& stream, const TestToken& token) {
  return stream << token.data;
}

// Тест содержит копирования объектов класса TestToken.
// Для проверки отсутствия копирований в функции SplitIntoSentences
// необходимо написать отдельный тест.
void TestSplitting() {
  ASSERT_EQUAL(
    SplitIntoSentences(vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!"}})),
    vector<Sentence<TestToken>>({
        {{"Split"}, {"into"}, {"sentences"}, {"!"}}
    })
  );

  ASSERT_EQUAL(
    SplitIntoSentences(vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!", true}})),
    vector<Sentence<TestToken>>({
        {{"Split"}, {"into"}, {"sentences"}, {"!", true}}
    })
  );

  ASSERT_EQUAL(
    SplitIntoSentences(vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}, {"Without"}, {"copies"}, {".", true}})),
    vector<Sentence<TestToken>>({
        {{"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}},
        {{"Without"}, {"copies"}, {".", true}},
    })
  );

  ASSERT_EQUAL(
      SplitIntoSentences(vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}})),
      vector<Sentence<TestToken>>({
          {{"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}}

      })
    );
  ASSERT_EQUAL(
        SplitIntoSentences(vector<TestToken>({{"!", true},{"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}})),
        vector<Sentence<TestToken>>({
	  	  	  {{"!", true}},
            {{"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}}

        })
      );

  ASSERT_EQUAL(
          SplitIntoSentences(vector<TestToken>({{"!", true}, {"!", true}, {"!", true}})),
          vector<Sentence<TestToken>>({
  	  	  	  {{"!", true},  {"!", true}, {"!", true}}

          })
        );
  ASSERT_EQUAL(
            SplitIntoSentences(vector<TestToken>({{}})),
            vector<Sentence<TestToken>>({
    	  	  	  {{}}

            })
          );

  ASSERT_EQUAL(
      SplitIntoSentences(vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}, {"Without"}, {"copies"}, {"."}})),
      vector<Sentence<TestToken>>({
          {{"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}},
          {{"Without"}, {"copies"}, {"."}},
      })
    );


}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSplitting);
  return 0;
}
