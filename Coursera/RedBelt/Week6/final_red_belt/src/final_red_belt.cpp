
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class SearchServer {
public:
  SearchServer() = default;
  explicit SearchServer(istream& document_input);
  // конструктор принимает поток ввода содержащий базу документов
  // один документ єто одна строка входного потока состоят из слов разделенных одним или несколь
  // кими пробелами Слова состоят из строчных латинских букв

  void UpdateDocumentBase(istream& document_input);
  //заменяет текущую базу документов на новую, которая содержится в потоке document_input.
  //При этом документ из первой строки этого потока будет иметь идентификатор (docid) 0,
  //документ из второй строки — идентификатор 1 и т.д.
  //
  // Точно так же должен назначать идентификаторы документам и конструктор класса SearchServer.


  void AddQueriesStream(istream& query_input, ostream& search_results_output);
  //выполняем поиск принимает входной поток поисковых запросов и выходной поток для записи
  //результатов поиска
  //один запрос это одна строка в потоке query_input каждый поисковой запрос состоит из слов
  // разделенных одним или несколькими пробелами так же как и в документах слова в запросах
  // состоят из строчных латинских букв

  //результат - набор максимум из пяти наиболее релевантных докумунтов.
  //В реальных поисковых системах метрика релевантности устроена довольно сложно

  //в качестве метрики релевантности мы будем использовать суммарное количество
  //вхождений всех слов запроса в документ.

  //ПРИМЕР  запрос "the best capital"
  //London is the capital of great britain — 2
  //(слово "the" входит в документ 1 раз, слово "best" — ни разу, слово "capital" — 1 раз)
  // moscow is the capital of the russian federation — 3
  //(слово "the" входит в документ 2 раза, слово "best" — ни разу, слово "capital" — 1 раз)
  //paris is the capital of france — 2
  //("the" — 1, "best" — 0, "capital" — 1)

  //В итоге получается, что документ "moscow is the capital of the russian federation"
  //оказывается наиболее релевантным запросу "the best capital".

  // ВЫВОД
  //Для каждого поискового запроса метод AddQueriesStream должен вывести в поток
  //search_results_output одну строку в формате

  // [текст запроса]: {docid: <значение>, hitcount: <значение>}
  //{docid: <значение>, hitcount: <значение>} ...,
  //где:
  //docid — идентификатор документа
  //hitcount — значение метрики релевантности для данного документа((то есть суммарное
  //            количество вхождений всех слов запроса в данный документ).
  //Замечания::
  //Добавлять в результаты поиска документы, hitcount которых равен нулю, не нужно.
  //при подсчёте hitcount нужно учитывать только слова целиком, то есть слово «there»
  //не является вхождением слова «the»
};


int main() {

	const string doc1 = "london is the capital of great britain";
	const string doc2 = "moscow is the capital of the russian federation";
	istringstream doc_input1(doc1 + '\n' + doc2);
	SearchServer srv(doc_input1);

	const string query = "the capital";
	istringstream query_input1(query);
	srv.AddQueriesStream(query_input1, cout);

	istringstream doc_input2(doc2 + '\n' + doc1);
	srv.UpdateDocumentBase(doc_input2);
	istringstream query_input2(query);
	srv.AddQueriesStream(query_input2, cout);
//  код выше должен выводить
//	the capital: {docid: 1, hitcount: 3} {docid: 0, hitcount: 2}
//	the capital: {docid: 0, hitcount: 3} {docid:

	return 0;
}
